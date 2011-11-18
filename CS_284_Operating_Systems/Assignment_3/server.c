/******************************************************************************
* @file server.c
* @author James Anderson <jra798>
* @date 10/11/2011
* @version 1.0
* @brief starts server to echo back messages on specified port
******************************************************************************/
 
#include "shared.h"


struct thread_data
{
    int netSock;
    
    int color;
    int bright;
};
 
using namespace std; 
 
void signalHandler(int sig);

void * clientHandler(void * socket );

void writeOut(int caller, string writeBuff);

int text_color;
int text_bright;



pthread_mutex_t netSocks_lock;
pthread_mutex_t write_lock;
pthread_mutex_t client_thread_lock;

vector <int> netSocks;
vector <pthread_t> clients;

bool shutdown_server;
int soc;


 
int main(int argc, char **argv)
{
    
    shutdown_server = false;
    text_color = 1;
    text_bright = 0;
    
    
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
    for(;;)
    {
        int netSock;
        pthread_t client_pthread;
        thread_data data;
        
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
            
            //set vars
            data.netSock = netSock;
            data.color = text_color;
            data.bright = text_bright;
            
            //printf("netsoc: %u\n", netSock);
            
            //create new thread for client
            pthread_create(&client_pthread, NULL, clientHandler, &data);
            
            
            //add new thread to the vector
            pthread_mutex_lock(&client_thread_lock);
            netSocks.push_back(client_pthread);
            pthread_mutex_unlock(&client_thread_lock);
            
            //increment color
            if (text_color < 6)
            {
                text_color++;
            }
            else
            {
                text_color = 1;
                
                if(text_bright = 0)
                {
                    text_bright = 1;
                }
                else
                {
                    text_bright = 0;
                }
            }
            
        }
        
    }
}

void writeOut(int caller, char * writeBuff)
{
    for(int i = 0; i < netSocks.size(); i++)
    {
        //write to all clients
        if(netSocks[i] != caller)
        { 
            write (netSocks[i], writeBuff, MAX_BUFFER_SIZE);
        }
    }
}


void * clientHandler(void * data_in )
{
    char readBuff[MAX_BUFFER_SIZE];
    bool exit = false;
    char username[30];
    int k;
    bool initial = true;
    int netSock = *(int*)socket;
    thread_data data = *(thread_data*)data_in;
    
    

    while( (k = read(data.netSock, readBuff, sizeof(readBuff))) != 0 && !exit)
    {
        char writeBuff[MAX_BUFFER_SIZE];
        //printf("message received :%s\n",readBuff);
        
        if (initial)
        {
            //strore username in specified color
            sprintf(username, "\033[%d;%dm%s\033[0m", data.bright,30 + data.color,readBuff);
            
            //create message to indicate user is in room
            strcpy(writeBuff, username);
            strcat(writeBuff, " has entered the room.\n");
            
            initial = false;
        }
        else if(strcmp(readBuff,"/exit") == 0 ||
                strcmp(readBuff,"/quit") == 0 ||
                strcmp(readBuff,"/part") == 0 )
        {
            //remove user from the chat 
            strcpy(writeBuff, username);
            strcat(writeBuff, " has left the room.\n");
            
            exit = true; 
        }
        else 
        {
            
            //write out username and messages
            strcpy(writeBuff, "\033[33m");
            strcat(writeBuff, username);
            strcat(writeBuff, ":\033[0m ");
            strcat(writeBuff, readBuff);
            strcat(writeBuff, "\n");
        }
        
        //print to server and clients
        pthread_mutex_lock(&write_lock);
        printf("%s",writeBuff);
        writeOut(data.netSock, writeBuff);
        pthread_mutex_unlock(&write_lock);
        
        if(exit)
        {
                
                //remove from client list
                pthread_mutex_lock(&netSocks_lock);
                for(int i = 0; i < netSocks.size(); i++)
                {
                    if(netSocks[i] == data.netSock)
                    {
                        netSocks.erase( netSocks.begin() + i);
                    }
                }
                pthread_mutex_unlock(&netSocks_lock);
                
                //close socket
                close(netSock);
                
                //exit thread
                break;
        }
        
    }
    while(1){};

}

void signalHandler(int sig)
{
    char writeBuff[MAX_BUFFER_SIZE];
    
    //print warning message
    strcpy(writeBuff, "\b\bServer will shut down in 10 seconds\n"); 
    
    //print to server and clients
    pthread_mutex_lock(&write_lock);
    printf("%s",writeBuff);
    writeOut(-1, writeBuff);
    pthread_mutex_unlock(&write_lock);
    
    //wait ten seconds
    sleep(10);
    
    //print out parting message
    strcpy(writeBuff, "Have a nice day\n"); 
    
    //print to server and clients
    pthread_mutex_lock(&write_lock);
    printf("%s",writeBuff);
    writeOut(-1, writeBuff);
    pthread_mutex_unlock(&write_lock);
    
    for(int i = 0; i < netSocks.size(); i++)
    {
        //close all client
        close(netSocks[i]);
    }
    
    //close socket
    close(soc);
    
    //close program
    exit(1);
}


