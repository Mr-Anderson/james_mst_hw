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
    
        myTCP();//default constructor for reciever
     
        myTCP(string ip_address, int port_number);//constructor for sender
        
        void send(int, const void, size_t, int, sockaddr, socklen_t);//
        
        int recv(int, const void, size_t, int, sockaddr, int);
        
        myTCP(string ip_address, int port_number);
        bool close();
    private:
    
        int     sockfd;
        struct sockaddr_in  servaddr;
   
};
#endif
