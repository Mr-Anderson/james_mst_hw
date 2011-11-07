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

myNetwork::myNetwork(int port, long unsigned int ip)
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
    //if(DEBUG) printf("NET: Server started on port %u \n", port);
}

void myNetwork::init(int port, long unsigned int ip)
{
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(port);
    servaddr.sin_addr.s_addr = ip;
	
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    //if(DEBUG) printf("NET: Client started\n");
}

void myNetwork::mysendto(void *buffer, size_t bufferLength, int flag, sockaddr *addr, socklen_t addrLength)
{
    //sleep(5);
    sendto(sockfd, buffer, bufferLength, flag, addr, addrLength);
    char char_ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &((sockaddr_in *) addr)->sin_addr.s_addr, char_ip, INET_ADDRSTRLEN);
    if(DEBUG) printf("NET: Sending %u bytes to %s on port %u\n", bufferLength, char_ip, ntohs(((sockaddr_in *) addr)->sin_port));
}

int myNetwork::myrecvfrom(void *buffer, size_t bufferLength, int flag, sockaddr *addr, socklen_t * addrLength)
{
    //if(DEBUG) printf("NET: Receiver started\n");
    char char_ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &((sockaddr_in *) addr)->sin_addr.s_addr, char_ip, INET_ADDRSTRLEN);
    //if(DEBUG) printf("NET: Receiving from %s on port %u\n", char_ip, ntohs(((sockaddr_in *) addr)->sin_port));
	
	int n = recvfrom(sockfd, buffer, bufferLength, flag, addr, addrLength);
    
    inet_ntop(AF_INET, &((sockaddr_in *) addr)->sin_addr.s_addr, char_ip, INET_ADDRSTRLEN);
    //if(DEBUG) printf("NET: Received %u bytes from %s on port %u\n", n, char_ip, ntohs(((sockaddr_in *) addr)->sin_port));
    
    return n;
}

void myNetwork::getMyIP(char * IP)
{
	inet_ntop(AF_INET, &servaddr.sin_addr, IP, INET_ADDRSTRLEN);
}

void myNetwork::getServAddr(struct sockaddr_in *addr)
{
    *addr = servaddr;
}
