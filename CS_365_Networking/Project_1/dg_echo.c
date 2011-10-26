#ifndef DG_ECHO_C
#define DG_ECHO_C
/*******************************************************************************
 * @file dg_echo.c
 * @author James Anderson <jra798>
 * @date 10/11/2011
 * @version 1.0
 * @brief echos back message recived message 
 ******************************************************************************/

#include	"unp.h"
#include	"myTCP.h"

void dg_echo(int sockfd, SA *pcliaddr, socklen_t clilen)
{
    int         n;
    socklen_t   len;
    char        mesg[MAXLINE];
    myTCP tcp;

    for ( ; ; ) 
    {
        len = clilen;
        n = tcp.recvfrom(sockfd, mesg, MAXLINE, 0, pcliaddr, &len);

        tcp.sendto(sockfd, mesg, n, 0, pcliaddr, len);
    }
}
#endif
