/*******************************************************************************
 * @file myTCP.c
 * @author James Anderson <jra798>
 * @date 10/11/2011
 * @version 1.0
 * @brief reads in specified file and sends to specified IP then wites receved 
 * messages to output file
 ******************************************************************************/

#include	"myTCP.h"

#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "math.h"
#include "fstream"
#include "iostream"

int main(int argc, char **argv)
{

    // check to see if their are the correct number of arguments
    if (argc != 2)
    {
        fputs(" usage: server <Port> \r \n", stderr);
        exit(0);
    }
    
    int port = atoi(argv[1]);
    
    //Create new TCP listener
    tcp_server_init(port);
    
    int         n;
    char        mesg[MAXLINE];
    
    //begin loop to echo data
    for ( ; ; ) 
    {
        n = tcp_recv(mesg, MAXLINE);

        tcp_send(mesg, n);
    }

}



