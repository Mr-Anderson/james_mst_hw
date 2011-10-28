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

myNetwork::myNetwork(int port)
{
	init(port);
}

myNetwork::myNetwork(int port, char * ip)
{
	init(port, ip);
}

void myNetwork::init(int port)
{
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family      = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port        = htons(port);
	
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	bind(sockfd, (SA *) &servaddr, sizeof(servaddr));
}

void myNetwork::init(int port, char * ip)
{
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(port);
	inet_pton(AF_INET, ip, &servaddr.sin_addr);
	
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
}

void myNetwork::mysendto(void *buffer, size_t bufferLength, int flag, sockaddr *addr, socklen_t addrLength)
{
	sendto(sockfd, buffer, bufferLength, flag, addr, addrLength);
}

int myNetwork::myrecvfrom(void *buffer, size_t bufferLength, int flag, sockaddr *addr, socklen_t * addrLength)
{
	recvfrom(sockfd, buffer, bufferLength, flag, addr, addrLength);
}

void myNetwork::getMyIP(char * IP)
{
	inet_ntop(AF_INET, &servaddr.sin_addr, IP, INET_ADDRSTRLEN);
}
