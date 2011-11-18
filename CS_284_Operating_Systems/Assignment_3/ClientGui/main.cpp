/******************************************************************************
* @file client.c
* @author James Anderson <jra798>
* @date 10/11/2011
* @version 1.0
* @brief Client creates a socket to connect to Server.
*   When the communication established, Client writes data to server
*   and echoes the response from Server.
******************************************************************************/

#include "../shared.h"
#include <QtGui/QApplication>
#include "clientgui.h"
#include "hostname.h"
#include "username.h"


using namespace std;

void signalHandler(int sig);

void * clientListener(void * socket );

pthread_t client_pthread;

int main( int argc, char** argv )
{


    QApplication Program(argc, argv);

    //open chat window
    ClientGui chatWindow;
    chatWindow.show();

    //open hostname setter
    Hostname hostnameSet;
    hostnameSet.show();


    Program.exec();


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
        write(soc, buf, sizeof(buf));

        if( strcmp(buf,"/exit") == 0 ||
            strcmp(buf,"/quit") == 0 ||
            strcmp(buf,"/part") == 0 )
            {
                break;
            }

    }

    pthread_exit(&client_pthread);

    close(soc);

    return(0);
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
        if(strcmp(readBuff, "\b\bServer will shut down in 10 seconds\n") == 0)
        {
            timeout = time(NULL) + 10;
            final = true;
        }
        if (final && timeout <= time(NULL))
        {
            exit(1);
        }
    }
}


void signalHandler(int sig)
{

    printf("\b\bPlease type /exit, /quit, or /part to leave room.\n");

}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ClientGui w;
    w.show();

    return a.exec();
}
