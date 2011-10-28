/*******************************************************************************
 * @file myTCP.c
 * @author James Anderson <jra798>
 * @date 10/11/2011
 * @version 1.0
 * @brief reads in specified file and sends to specified IP then wites receved 
 * messages to output file
 ******************************************************************************/

#include	"myTCP.h"


myNetwork net;

int server_port_number;
int client_port_number;

char server_ip_address[4];
char client_ip_address[4];

bool server;

struct _MYTCP_Header server_header;
struct _MYTCP_Header client_header;

vector <string> send_buff;
vector <string> recv_buff;

pthread_mutex_t send_lock;
pthread_mutex_t recv_lock;

pthread_t sender;
pthread_t receiver;


void tcp_server_init(int port_number)
{
	//Server
    server = true;
    net.init(port_number);
	
    //Start threads
	if(pthread_create(&sender, NULL, send_thread, NULL))
	{
		cout << "ERROR" << endl;
	}
	if(pthread_create(&receiver, NULL, recv_thread, NULL))
	{
		cout << "ERROR" << endl;
	}
    
    pthread_join(sender,NULL);
    pthread_join(receiver,NULL);
    
    
}

void tcp_client_init(char * ip_address, int port_number)
{
	//Client
    server = false;
    strcpy(server_ip_address, ip_address, 4);
    net.init(port_number, server_ip_address);
    
    
    //Start threads
	if(pthread_create(&sender, NULL, send_thread, NULL))
	{
		cout << "ERROR" << endl;
	}
	if(pthread_create(&receiver, NULL, recv_thread, NULL))
	{
		cout << "ERROR" << endl;
	}
    
    pthread_join(sender,NULL);
    pthread_join(receiver,NULL);
      
}

void tcp_send(const void *buffer, size_t bufferLength)
{
    
    
    
}

int tcp_recv(const void *buffer , size_t bufferLength)
{
    
    
    
}


void * send_thread(void *arg)
{
    if(server)
    {
        
    }
    else
    {
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
    }
    

    
    //add header to no data
    //send 
    
    //receive
    */
}        

void * recv_thread(void *arg)
{
     
    if(server)
    {
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
    else
    {
    }   
}


