/*James Anderson*/
/*CS365			*/
/*HW2			*/
/*	dg­_echo.c 	*/
/*				*/

#include	"unp.h"

void dg_echo(int sockfd, SA *pcliaddr, socklen_t clilen)
{
	int			n;
	socklen_t	len;
	char		mesg[MAXLINE];

	for ( ; ; ) 
	{
		len = clilen;
		n = recvfrom(sockfd, mesg, MAXLINE, 0, pcliaddr, &len);

		sendto(sockfd, mesg, n, 0, pcliaddr, len);
	}
}
