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

void dg_echo(int sockfd, SA *pcliaddr, socklen_t clilen)
{
    int         n;
    socklen_t   len;
    char        mesg[MAXLINE];

    for ( ; ; ) 
    {
        len = clilen;
        n = recvfrom(sockfd, mesg, MAXLINE, 0, pcliaddr, &len);

        sendto(sockfd, mesg, n, 0, pcliaddr, len);
    }
}
#endif
