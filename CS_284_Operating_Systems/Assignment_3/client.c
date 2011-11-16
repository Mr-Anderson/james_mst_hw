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
 
void * listen(void * socket );


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

    printf("Welcome to the chatroom\n"); 
    printf("Please type your username:" ); 

    while( scanf( "%s", buf) != EOF) 
    { 
        write(soc, buf, sizeof(buf)); 
        read(soc, buf, sizeof(buf)); 
        printf("SERVER ECHOED: %s\n", buf); 
    } 

    close(soc); 
    return(0); 
}

