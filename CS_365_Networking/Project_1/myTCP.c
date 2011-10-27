/*******************************************************************************
 * @file myTCP.c
 * @author James Anderson <jra798>
 * @date 10/11/2011
 * @version 1.0
 * @brief reads in specified file and sends to specified IP then wites receved 
 * messages to output file
 ******************************************************************************/

#include	"myTCP.h"

myTCP::myTCP()
{
}

myTCP::myTCP(int port_number)
{
	init(port_number);
}

myTCP::myTCP(char * ip_address, int port_number)
{
	init(ip_address, port_number);
}

void myTCP::init(int port_number)
{
	//Server
    server = true;
    
    //initalize udp
	net.init(port_number, server);
    
    while()
    {
        //recieve
        //strip header to client header
        if(client_header.tcp_hdr.syn)
        {
            server_header = client_header;
            server_header.tcp_hdr.ack = 1;
            server_header.tcp_hdr.seq = CLIENT_ISN;
            server_header.tcp_hdr.ack_seq = server_header.tcp_hdr.seq + 1;
            
            //add header to no data
            //send to client
            
            //wait for recept
            
            
            
        }
    }
    
    
}

void myTCP::init(char * ip_address, int port_number)
{
	//Client
    server = false;
   
	net.init(port_number, server);
	strcpy(server_ip_address, ip_address, 4);
    
    //setup header for intial syn
    client_header.tcp_hdr.source = 0;
    client_header.tcp_hdr.dest = 0;
    client_header.tcp_hdr.seq = CLIENT_ISN;
    client_header.tcp_hdr.ack_seq = 0;
    client_header.tcp_hdr.res1 = 0;
    client_header.tcp_hdr.doff = 0;
    client_header.tcp_hdr.fin = 0;
    client_header.tcp_hdr.syn = 1;
    client_header.tcp_hdr.rst = 0;
    client_header.tcp_hdr.psh = 0;
    client_header.tcp_hdr.ack = 0;
    client_header.tcp_hdr.urg = 0;
    client_header.tcp_hdr.res2 = 0;
    client_header.tcp_hdr.window = 0;
    client_header.tcp_hdr.check = 0;
    client_header.tcp_hdr.urg_ptr = 0;
    client_header.data_len = 0;
    
    //add header to no data
    //send 
    
    //receive
    
    
    
}

void myTCP::void send(const void *buffer, size_t bufferLength)
{
    
    
    
}

int myTCP::recv(const void *buffer , size_t bufferLength)
{
    
    
    
}
