#ifndef MYNETWORK_H
#define MYNETWORK_H
/*******************************************************************************
 * @file myNetwork.c
 * @author James Anderson <jra798>
 * @date 10/11/2011
 * @version 1.0
 * @brief simulates a unreliable network
 ******************************************************************************/

#include	"myNetwork.h"

void myNetwork::void sendto(int sid, const void *buffer, size_t bufferLength 
            ,int flag, sockaddr *addr, socklen_t addrLength)
{
    
    
    
};

int myNetwork::recvfrom(int sid, const void *buffer , size_t bufferLength
                     , int flag, sockaddr *addr, int addrLength);
{
    
    
};

#endif
