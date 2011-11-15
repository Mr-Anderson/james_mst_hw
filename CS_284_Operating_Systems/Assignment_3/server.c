/******************************************************************************
* @file server.c
* @author James Anderson <jra798>
* @date 10/11/2011
* @version 1.0
* @brief starts server to echo back messages on specified port
******************************************************************************/
 
#include "shared.h"
 

pthread_t client_pthread;

pthread_mutex_t netSocks_lock;

vector <int> netSocks;
int clients;
 
int main(int argc, char **argv)
{
    int soc;
    char buf[512], *host;

    
    
    //create the socket addresses
    sockaddr_in server ={ AF_INET, htons(SERVER_PORT)}
    sockaddr_in client_addr = { AF_INET };
    
    
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
    
    //main loop
    for(;;)
    {
        int netSock;
        
        printf("server: listening for new clients");
        
        //accept new connections
        if(netSock = accept(soc, (sockaddr*)&peer, (socklen_t*)&peerlen) == -1)
        {
            perror( "server: accept failed" );
            exit( 1 );
        }
        else
        {
            pthread_mutex_lock(&netSocks_lock)
            netSocks.push_back(netSock);
            pthread_mutex_lock(&data_lock);
            
            //create new thread for client
            pthread_create(&client_pthread, NULL, ClientHandler, &var);
        }
    }
}


void * ClientHandler(void arg *)
{
    pthread_mutex_lock(&data_lock);
    int client_id = 
}
