#ifndef MYTCP_H
#define MYTCP_H
/*******************************************************************************
 * @file myTCP.h
 * @author James Anderson <jra798>
 * @date 10/11/2011
 * @version 1.0
 * @brief TCP protocal code 
 ******************************************************************************/

#include	"unp.h"

template <class generic>
class myTCP
{
    public:
        void sendto(int sid, const void *buffer, size_t bufferLength 
                    ,int flag, struct sockaddr *addr, socklen_t addrLength);
                    
        int recvfrom(int sid, const void *buffer , size_t bufferLength
                     , int flag, sockaddr *addrLength, int addrLength);

};
#endif
