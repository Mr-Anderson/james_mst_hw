#ifndef MYTCP_C
#define MYTCP_C
/*******************************************************************************
 * @file myTCP.c
 * @author James Anderson <jra798>
 * @date 10/11/2011
 * @version 1.0
 * @brief reads in specified file and sends to specified IP then wites receved 
 * messages to output file
 ******************************************************************************/

#include	"myTCP.h"

myTCP::myTCP(string ip_address, int port_number)
{

    FILE * in_pf;
    FILE * out_pf;

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

}

void myTCP::void sendto(int sid, const void *buffer, size_t bufferLength,
                        int flag, sockaddr *addr, socklen_t addrLength)
{
    
    
    
};

int myTCP::recvfrom(int sid, const void *buffer , size_t bufferLength, 
				    int flag, sockaddr *addr, int addrLength);
{
  
    
    
};
#endif
