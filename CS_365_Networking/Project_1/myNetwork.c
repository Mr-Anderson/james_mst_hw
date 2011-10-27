/*******************************************************************************
 * @file myNetwork.c
 * @author James Anderson <jra798>
 * @date 10/11/2011
 * @version 1.0
 * @brief simulates a unreliable network
 ******************************************************************************/

#include	"myNetwork.h"

myNetwork::myNetwork()
{

}

myNetwork::myNetwork(int port, bool server)
{
	init(port, server);
}

void myNetwork::init(int port, bool server)
{
	if(server)
	{
		bzero(&servaddr, sizeof(servaddr));
		servaddr.sin_family      = AF_INET;
		servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
		servaddr.sin_port        = htons(SERV_PORT);
		
		sockfd = socket(AF_INET, SOCK_DGRAM, 0);
		bind(sockfd, (SA *) &servaddr, sizeof(servaddr));
	}
	else
	{
		bzero(&servaddr, sizeof(servaddr));
		servaddr.sin_family = AF_INET;
		servaddr.sin_port = htons(SERV_PORT);
		inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
		
		sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	}
}

void myNetwork::sendto(const void *buffer, size_t bufferLength, int flag, sockaddr *addr, socklen_t addrLength)
{
	sendto(sockfd, buffer, bufferLength, flag, addr, addrLength);
}

int myNetwork::recvfrom(const void *buffer, size_t bufferLength, int flag, sockaddr *addr, int addrLength)
{
	recvfrom(sockfd, buffer, bufferLength, flag, addr, addrLength);
}
