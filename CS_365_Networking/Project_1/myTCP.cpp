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

size_t buff_len = WINDOW_SIZE +sizeof(struct _MYTCP_Header);

struct tcp_buff
{
    struct _MYTCP_Header header;
    char data[WINDOW_SIZE];
};

enum client_state_t
{
   CLOSED,
   SYN_SENT,
   ESTABLISHED,
   FIN_WAIT_1,
   FIN_WAIT_2,
   TIME_WAIT
};

client_state_t client_state;

enum server_state_t
{
    CLOSED,
    LISTEN,
    SYN_RCVD,
    ESTABLISHED,
    CLOSE_WAIT,
    LAST_ACK
};

server_state_t server_state;

deque <tcp_buff> send_buff;
deque <tcp_buff> recv_buff;

pthread_mutex_t send_lock;
pthread_mutex_t recv_lock;

pthread_t sender;
pthread_t receiver;

sockaddr_in addr;
socklen_t len;




void tcp_server_init(int port_number)
{
	//Server
    server = true;
    server_state = CLOSED;
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
    client_state = CLOSED;
    memcpy(server_ip_address, ip_address, 4);
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
    tcp_buff send_msg;
    
    memcpy(send_msg.data, buffer, bufferLength); 
    
    send_buff.push_back(send_msg);
    
    //net.mysendto(sendline, buff_len, 0, (sockaddr*)&addr, len);
    
}

int tcp_recv(void *buffer , size_t bufferLength)
{
    tcp_buff recv_msg;
    
    while(recv_buff.empty())
    {
        continue;
    }
    
    recv_msg = recv_buff.front();
    
    recv_buff.pop_front();
    
    memcpy(buffer , recv_msg.data , bufferLength);
    
    //net.myrecvfrom(recvline, buff_len, 0, (sockaddr*)&addr, &len);
    
    return recv_msg.header.data_len;
}


void * send_thread(void *arg)
{

    //cout << "aaaaaarg send" << endl;
    
    if(server)
    {
        
    }
    else
    {
        _MYTCP_Header header;
        
        if(client_state == CLOSED)
        {
            //setup header for intial syn
            reset_head(&header);
            header.tcp_hdr.seq = CLIENT_ISN;
            header.tcp_hdr.syn = 1;
        }
        
    }
    
    

    
    //add header to no data
    //send 
    
    //receive
    
    
}        

void * recv_thread(void *arg)
{
    //cout << "aaaaaarg recv" << endl;
    
    if(server)
    {
        while(1)
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

void reset_head(struct _MYTCP_Header *header)
{
        header->tcp_hdr.source = 0;
        header->tcp_hdr.dest = 0;
        header->tcp_hdr.seq = 0;
        header->tcp_hdr.ack_seq = 0;
        header->tcp_hdr.res1 = 0;
        header->tcp_hdr.doff = 0;
        header->tcp_hdr.fin = 0;
        header->tcp_hdr.syn = 0;
        header->tcp_hdr.rst = 0;
        header->tcp_hdr.psh = 0;
        header->tcp_hdr.ack = 0;
        header->tcp_hdr.urg = 0;
        header->tcp_hdr.res2 = 0;
        header->tcp_hdr.window = 0;
        header->tcp_hdr.check = 0;
        header->tcp_hdr.urg_ptr = 0;
        header->data_len = 0;
}




