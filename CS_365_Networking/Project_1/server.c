/*******************************************************************************
 * @file server.c
 * @author James Anderson <jra798>
 * @date 10/11/2011
 * @version 1.0
 * @brief starts server to echo back messages on specified port
 ******************************************************************************/

#include    "unp.h"
#include	"myTCP.h"

int
main(int argc, char **argv)
{

    // check to see if their are the correct number of arguments
    if (argc != 2)
    {
        fputs(" usage: server <Port> \r \n", stderr);
        exit(0);
    }
    
    //Create new TCP listener
    myTCP tcp(argv[1]);
    
    int         n;
    char        mesg[MAXLINE];
    
    //begin loop to echo data
    for ( ; ; ) 
    {
        n = tcp.recv(mesg, MAXLINE);

        tcp.send(mesg, n);
    }

}
