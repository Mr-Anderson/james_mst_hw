/******************************************************************************
* @file server.c
* @author James Anderson <jra798>
* @date 10/11/2011
* @version 1.0
* @brief starts server to echo back messages on specified port
******************************************************************************/
 
#include "shared.h"
 
using namespace std; 
 
void signalHandler(int sig);

void * clientHandler(void * socket );

void writeOut(int caller, string writeBuff);


pthread_t client_pthread;

pthread_mutex_t netSocks_lock;
pthread_mutex_t write_lock;

vector <int> netSocks;

bool shutdown_server;
int soc;


 
int main(int argc, char **argv)
{
    
    shutdown_server = false;
    
    //create the socket addresses
    struct sockaddr_in server_addr ={ AF_INET, htons(SERVER_PORT)};
    struct sockaddr_in client_addr = { AF_INET };
    
    
    //open the socket
    if( ( soc = socket( AF_INET, SOCK_STREAM, 0 ) ) == -1 )
    {
        perror( "server: socket failed" );
        exit( 1 );
    }
    
    //bind to the socket 
    if( bind(soc, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1 )
    {
        perror( "server: bind failed" );
        exit( 1 );
    }
    
    //start listening for clients
    if( listen(soc, CLIENT_SUPPORT) == -1 )
    {
        perror( "server: listen failed" );
        exit( 1 );  
    }
    
    //start singal handler
    signal(SIGINT, signalHandler);
    
    //main loop
    for(int i = 0;; i++)
    {
        int netSock;
        
        printf("Listening for new clients\n");
        
        //accept new connections
        if((netSock = accept(soc, (struct sockaddr*)&client_addr, (socklen_t*)&client_addr)) == -1)
        {
            perror( "server: accept failed" );
            exit( 1 );
        }
        else
        {
            //add new client to socket address vector
            pthread_mutex_lock(&netSocks_lock);
            netSocks.push_back(netSock);
            pthread_mutex_unlock(&netSocks_lock);
            
            printf("netsoc: %u\n", netSock);
            //create new thread for client
            pthread_create(&client_pthread, NULL, clientHandler, &netSock);
        }
        
    }
}

void writeOut(int caller, char * writeBuff)
{
    for(int i = 0; i < netSocks.size(); i++)
    {
        //write to all clients
        //printf("printing %s to %u",writeBuff, netSocks[i]);
        write (netSocks[i], writeBuff, MAX_BUFFER_SIZE);

    }
}


void * clientHandler(void * socket )
{
    char readBuff[MAX_BUFFER_SIZE];
    bool exit = false;
    char username[30];
    int k;
    bool initial = true;
    int netSock = *(int*)socket;
    
    
    while( (k = read(netSock, readBuff, sizeof(readBuff))) != 0 && !exit)
    {
        char writeBuff[MAX_BUFFER_SIZE];
        printf("message received :%s\n",readBuff);
        
        if (initial)
        {
            strncpy(username, readBuff, k);
        
            strcpy(writeBuff, username);
            strcat(writeBuff, " has entered the room.\n");
            
            initial = false;
        }
        else if(strcmp(readBuff,"/exit") == 0 ||
                strcmp(readBuff,"/quit") == 0 ||
                strcmp(readBuff,"/part") == 0 )
        {
            strcpy(writeBuff, username);;
            strcat(writeBuff, " has left the room.\n");
            
            exit = true; 
        }
        else 
        {
            
            
            strcpy(writeBuff, "\033[33m");
            strcpy(writeBuff, username);
            strcat(writeBuff, ":\033[0m ");
            strcat(writeBuff, readBuff);
            strcat(writeBuff, "\n");
        }
        
        //print to server and clients
        pthread_mutex_lock(&write_lock);
        printf("%s",writeBuff);
        writeOut(netSock, writeBuff);
        pthread_mutex_unlock(&write_lock);
        
        if(exit)
        {
                close(netSock);
                
                //remove from client list
                pthread_mutex_lock(&netSocks_lock);
                for(int i = 0; i < netSocks.size(); i++)
                {
                    if(netSocks[i] == netSock)
                    {
                        netSocks.erase( netSocks.begin() + i);
                    }
                }
                pthread_mutex_unlock(&netSocks_lock);
                
                
                break;
        }
        
    }

}

void signalHandler(int sig)
{
    char writeBuff[MAX_BUFFER_SIZE];
    
    strcpy(writeBuff, "\b\bServer will shut down in 10 seconds\n"); 
    
    //print to server and clients
    pthread_mutex_lock(&write_lock);
    printf("%s\n",writeBuff);
    writeOut(-1, writeBuff);
    pthread_mutex_unlock(&write_lock);
    
    
    sleep(10);
    
    for(int i = 0; i < netSocks.size(); i++)
    {
        //close all client
        close(netSocks[i]);
    }
    
    //close threads
    pthread_exit(NULL);
    
    //close socket
    close(soc);
    
    printf("Have a nice day\n");
    
    exit(1);
}
