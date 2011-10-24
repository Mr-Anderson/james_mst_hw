#ifndef DG_CLI_C
#define DG_CLI_C
/*******************************************************************************
 * @file dg_cli.c
 * @author James Anderson <jra798>
 * @date 10/11/2011
 * @version 1.0
 * @brief sends in file to server and writes receved messages to out file
 ******************************************************************************/

#include    "unp.h"

void dg_cli(FILE *in_fp, FILE *out_fp, int sockfd, const SA *pservaddr, socklen_t servlen)
{
    int n;
    char    sendline[MAXLINE], recvline[MAXLINE + 1];
    
    while (!feof(in_fp)) 
    {
        n = fread(sendline, 1, MAXLINE ,in_fp);
    
        sendto(sockfd, sendline, n , 0, pservaddr, servlen);

        n = recvfrom(sockfd, recvline, MAXLINE, 0, NULL, NULL);
        
        fwrite(recvline ,1, n , out_fp);
    }

}
#endif
