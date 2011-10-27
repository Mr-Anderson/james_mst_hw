#ifndef MYNETWORK_H
#define MYNETWORK_H
/*******************************************************************************
 * @file myNetwork.h
 * @author James Anderson <jra798>
 * @date 10/11/2011
 * @version 1.0
 * @brief simulates an unreliable network
 ******************************************************************************/

#include	"unp.h"

class myNetwork
{
	public:
		myNetwork();
		myNetwork(int port, bool server);
	
		void init(int port, bool server);

		void mysendto(void *buffer, size_t bufferLength, int flag, sockaddr *addr, socklen_t addrLength);
                    
		int myrecvfrom(void *buffer, size_t bufferLength, int flag, sockaddr *addr, socklen_t * addrLength);
        
		void getMyIP(char * IP);
	private:
		int sockfd;
		struct sockaddr_in servaddr;
};

#endif
