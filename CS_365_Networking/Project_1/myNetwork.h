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

		myNetwork(int port, bool server);
	
        	void sendto(int, const void, size_t, int, sockaddr, socklen_t);
                    
        	int recvfrom(int, const void, size_t, int, sockaddr, int);
        
	private:
		int sockfd;
		struct sockaddr_in servaddr;
		struct sockaddr_in cliaddr;
};

#endif
