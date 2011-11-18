/******************************************************************************
* @file client.c
* @author James Anderson <jra798>
* @date 10/11/2011
* @version 1.0
* @brief Client creates a socket to connect to Server.                      
*   When the communication established, Client writes data to server   
*   and echoes the response from Server.  
******************************************************************************/

#include "shared.h"
 

using namespace std; 
 
void signalHandler(int sig);

void * clientListener(void * socket );

pthread_t client_pthread;

int main( int argc, char** argv ) 
{ 
    int soc; 
    sockaddr_in server_addr = { AF_INET, htons( SERVER_PORT ) }; 
    char buf[MAX_BUFFER_SIZE]; 
    struct hostent *host; 

    if( argc != 2 ) 
    { 
        printf( "Usage: %s hostname\n", argv[0] ); 
        exit(1); 
    } 
 
    //translate the host name to hostent then place in server address
    if( ( host = gethostbyname( argv[1] ) ) == NULL ) 
    { 
        printf( "%s: %s unknown host\n", argv[0], argv[1] ); 
        exit( 1 ); 
    } 
    bcopy( host->h_addr_list[0], (char*)&server_addr.sin_addr, host->h_length ); 

    //open a new socket
    if( ( soc = socket( AF_INET, SOCK_STREAM, 0 ) ) == -1 ) 
    { 
        perror( "client: socket failed" ); 
        exit( 1 ); 
    } 

    //connect to the socket
    if( connect( soc, (struct sockaddr*)&server_addr, 
         sizeof(server_addr) ) == -1 ) 
    { 
        perror( "client: connect FAILED:" ); 
        exit( 1 ); 
    } 
    
    //start singal handler
    signal(SIGINT, signalHandler);
    
    //print welcome message
    printf("Welcome to the chatroom\n"); 
    printf("Please type your username:" ); 

    
    //start listen thread
    pthread_create(&client_pthread, NULL, clientListener, &soc);
    
    //read in messages
    while( gets( buf) ) 
    {
        printf("\033[1A\r                                                 \r");
        printf("\033[5;37;44mYou\033[0m:%s\n",buf);
        write(soc, buf, sizeof(buf)); 
        
        if( strcmp(buf,"/exit") == 0 ||
            strcmp(buf,"/quit") == 0 ||
            strcmp(buf,"/part") == 0 )
            {
                break;
            }

    } 
    
    printf("See you soon.\n");
    
    close(soc); 
    
    exit(0);
    
}


void * clientListener(void * socket )
{
    int netSock = *(int*)socket;
    int k;
    char readBuff[MAX_BUFFER_SIZE];
    time_t timeout;
    bool final = false;
    
    while( (k = read(netSock, readBuff, sizeof(readBuff))) != 0 )
    {

        printf("%s",readBuff);

        //check for the last messages
        if(strcmp(readBuff, "Have a nice day\n") == 0)
        {
            //tell user
            printf("Client is shuting down\n");
            
            //close the socket
            close(netSock);
            
            //close the program
            exit(1);
        }

    }
}


void signalHandler(int sig)
{

    printf("\b\bPlease type /exit, /quit, or /part to leave room.\n");

}
