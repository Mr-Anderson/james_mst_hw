/*******************************************************************************
 * @file server.c
 * @author James Anderson <jra798>
 * @date 10/11/2011
 * @version 1.0
 * @brief starts server to echo back messages on specified port
 ******************************************************************************/

#include    "unp.h"
#include    "dg_echo.c"

int
main(int argc, char **argv)
{
    int                 sockfd;
    struct sockaddr_in  servaddr, cliaddr;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family      = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port        = htons(SERV_PORT);

    bind(sockfd, (SA *) &servaddr, sizeof(servaddr));

    dg_echo(sockfd, (SA *) &cliaddr, sizeof(cliaddr));
}
