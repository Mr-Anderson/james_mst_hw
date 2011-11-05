/*James Anderson*/
/*CS365			*/
/*HW2			*/
/*	dg_cli.c 	*/
/*				*/

#include	"unp.h"

void dg_cli(FILE *in_fp, FILE *out_fp, int sockfd, const SA *pservaddr, socklen_t servlen)
{
	int	n;
	char	sendline[MAXLINE], recvline[MAXLINE + 1];
	
	
	
	while (!feof(in_fp)) 
	{
		n = fread(sendline, 1, MAXLINE ,in_fp);
	
		sendto(sockfd, sendline, n , 0, pservaddr, servlen);

		n = recvfrom(sockfd, recvline, MAXLINE, 0, NULL, NULL);
		
		fwrite(recvline ,1, n , out_fp);
	}

}
