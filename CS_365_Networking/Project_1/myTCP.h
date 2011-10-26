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
        bool open();
        
        bool close();
    
        void sendto(int, const void, size_t, int, sockaddr, socklen_t);
                    
        int recvfrom(int, const void, size_t, int, sockaddr, int);

};
#endif
