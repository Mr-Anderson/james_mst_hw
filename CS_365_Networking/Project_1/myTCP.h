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
    
        myTCP(int port_number);//constructor for reciever
     
        myTCP(string ip_address, int port_number);//constructor for sender
        
        void send(const void *msg, size_t len);//function to send data
        
        int recv(const void *buf, size_t len);//function to recieve data
        
    private:
    
        int     sockfd;
        struct sockaddr_in  servaddr;
        int port_number
   
};
#endif
