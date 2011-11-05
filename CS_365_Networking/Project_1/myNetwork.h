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
		myNetwork(int port);
		myNetwork(int port, long unsigned int ip);

		void init(int port);
		void init(int port, long unsigned int ip);

		void mysendto(void *buffer, size_t bufferLength, int flag, sockaddr *addr, socklen_t addrLength);
                    
		int myrecvfrom(void *buffer, size_t bufferLength, int flag, sockaddr *addr, socklen_t * addrLength);
        
		void getMyIP(char * IP);

        void getServAddr(struct sockaddr_in *addr);
	private:
		int sockfd;
		struct sockaddr_in servaddr;
};

#endif
