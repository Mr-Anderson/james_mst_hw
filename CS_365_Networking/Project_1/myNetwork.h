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

template <class generic>
class myNetwork
{
    public:
    
        void sendto(int, const void, size_t, int, sockaddr, socklen_t);
                    
        int recvfrom(int, const void, size_t, int, sockaddr, int);
        
        

};
#endif
