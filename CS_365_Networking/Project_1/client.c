/*******************************************************************************
 * @file client.c
 * @author James Anderson <jra798>
 * @date 10/11/2011
 * @version 1.0
 * @brief reads in specified file and sends to specified IP then wites receved 
 *  messages to output file
 ******************************************************************************/

#include	"unp.h"
#include    "dg_cli.c"

int main(int argc, char **argv)
{
    int     sockfd;
    struct sockaddr_in  servaddr;
    FILE * in_pf;
    FILE * out_pf;
    
    if (argc != 4)
    {
        fputs(" usage: udpcli <IPaddress> <InputFile> <OutputFile> \r \n", stderr);
        exit(0);
    }
    
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    in_pf=fopen (argv[2] , "r");
    out_pf=fopen (argv[3] , "w+");

    if (in_pf == NULL) perror ("Error opening file");
    else
    {
        dg_cli(in_pf, out_pf, sockfd, (SA *) &servaddr, sizeof(servaddr));
        
        fclose (in_pf);
        fclose (out_pf);
    }
    
    exit(0);
}
