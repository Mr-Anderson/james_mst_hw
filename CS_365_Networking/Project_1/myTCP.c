/*******************************************************************************
 * @file myTCP.c
 * @author James Anderson <jra798>
 * @date 10/11/2011
 * @version 1.0
 * @brief reads in specified file and sends to specified IP then wites receved 
 * messages to output file
 ******************************************************************************/

#include	"myTCP.h"

myTCP::myTCP()
{
}

myTCP::myTCP(int port_number)
{
	init(port_number);
}

myTCP::myTCP(char * ip_address, int port_number)
{
	init(ip_address, port_number);
}

void myTCP::init(int port_number)
{
	//Server
	net.init(port_number, true);
}

void myTCP::init(char * ip_address, int port_number)
{
	//Client
	net.init(port_number, false);
	strcpy(server_ip_address, ip_address, 4);
}

void myTCP::void sendto(int sid, const void *buffer, size_t bufferLength,
                        int flag, sockaddr *addr, socklen_t addrLength)
{
    
    
    
}

int myTCP::recvfrom(int sid, const void *buffer , size_t bufferLength, 
				    int flag, sockaddr *addr, int addrLength)
{
  
    
    
}
