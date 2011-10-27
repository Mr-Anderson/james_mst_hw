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
#include	"myNetwork.h"

class myTCP
{
    public:
    
	myTCP();
        myTCP(int port_number);//constructor for reciever
        
        myTCP(char * ip_address, int port_number);//constructor for sender
        
        void init(int port_number);//client
        
        void init(char * ip_address, int port_number);//server

        void send(const void *msg, size_t len);//function to send data
        
        int recv(const void *buf, size_t len);//function to recieve data
        
    private:
    	myNetwork net;
        
        int server_port_number;
        int client_port_number;
        
        char server_ip_address[4];
        char client_ip_address[4]
    
        typedef struct _MYTCP_Header 
        {
            struct tcphdr tcp_hdr;
            u_short data_len; //  the actual number of bytes in the data field. 
        } __attribute__ ((packed)) MYTCPHeader;
        
        
        struct _MYTCP_Header server_header;
        struct _MYTCP_Header client_header;
        
       
        
        bool server;
};
#endif
