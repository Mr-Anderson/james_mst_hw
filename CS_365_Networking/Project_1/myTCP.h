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
#include	"MyNetwork.h"

class myTCP
{
    public:
    
	myTCP();
        myTCP(int port_number);//constructor for reciever
        myTCP(char * ip_address, int port_number);//constructor for sender
        
	void init(int port_number);
	void init(char * ip_address, int port_number);

        void send(const void *msg, size_t len);//function to send data
        
        int recv(const void *buf, size_t len);//function to recieve data
        
    private:
    	myNetwork net;
        int port_number;
	char ip_address[4];
   
};
#endif
