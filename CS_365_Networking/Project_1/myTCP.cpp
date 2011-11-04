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

struct timeout
{
    //sequence number of packet sent
    int seq_num;
    //time it was sent on
    int sent;
};

enum client_state_t
{
   CLI_CLOSED,
   CLI_SYN_SENT,
   CLI_ESTABLISHED,
   CLI_FIN_WAIT_1,
   CLI_FIN_WAIT_2,
   CLI_TIME_WAIT
};

client_state_t client_state;

enum server_state_t
{
    SRV_CLOSED,
    SRV_LISTEN,
    SRV_SYN_RCVD,
    SRV_ESTABLISHED,
    SRV_CLOSE_WAIT,
    SRV_LAST_ACK
};

server_state_t server_state;

deque <tcp_buff> send_buff;
deque <tcp_buff> recv_buff;
deque <timeout> timeout_buff;

pthread_mutex_t send_lock;
pthread_mutex_t recv_lock;
pthread_mutex_t timeout_lock;


pthread_t sender_pthread;
pthread_t receiver_pthread;
pthread_t timeout_pthread;
pthread_t server_pthread;
pthread_t client_pthread;

sockaddr_in addr;
socklen_t len;

int cli_seq;
int srv_seq;


void tcp_server_init(int port_number)
{
	//Server
    server = true;
    server_state = SRV_CLOSED;
    net.init(port_number);
	
    //Start threads
	if(pthread_create(&server_pthread, NULL, srv_thread, NULL))
	{
		cout << "ERROR" << endl;
	}
    if(pthread_create(&timeout_pthread, NULL, timeout_thread, NULL))
    {
        cout << "ERROR" << endl;
    }
	if(pthread_create(&receiver_pthread, NULL, recv_thread, NULL))
	{
		cout << "ERROR" << endl;
	}
    
    pthread_join(server_pthread, NULL);
    pthread_join(timeout_pthread, NULL);    
    pthread_join(receiver_pthread, NULL);
    
    
}

void tcp_client_init(char * ip_address, int port_number)
{
	//Client
    server = false;
    client_state = CLI_CLOSED;
    memcpy(server_ip_address, ip_address, 4);
    net.init(port_number, server_ip_address);
    
    
    //Start threads
    if(pthread_create(&client_pthread, NULL, cli_thread, NULL))
	{
		cout << "ERROR" << endl;
	}
    if(pthread_create(&timeout_pthread, NULL, timeout_thread, NULL))
	{
		cout << "ERROR" << endl;
	}
	if(pthread_create(&receiver_pthread, NULL, recv_thread, NULL))
	{
		cout << "ERROR" << endl;
	}
    
    pthread_join(client_pthread, NULL);
    pthread_join(timeout_pthread, NULL);
    pthread_join(receiver_pthread, NULL);
      
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

// keeps track of the client state and iterates through tcp protocal
void * cli_thread(void *arg)
{
	while(true) //put some condition here
	{
    	if(client_state == CLI_CLOSED)
		{
		    //setup header for intial syn
            _MYTCP_Header header;		
            reset_head(&header);
            cli_seq = CLIENT_ISN;
		    header.tcp_hdr.seq = cli_seq;
		    header.tcp_hdr.syn = 1;
            net.mysendto(&header, sizeof(header), 0, (sockaddr*)&addr, len);
            client_state = CLI_SYN_SENT;
            recv_buff.clear();
	    }
		else if(client_state == CLI_SYN_SENT)
		{
            if(!recv_buff.empty())
            {
                tcp_buff recv_msg;
                pthread_mutex_lock(&recv_lock);
                recv_msg = recv_buff.front();
                recv_buff.pop_front();
                pthread_mutex_unlock(&recv_lock);
                if((recv_msg.header.tcp_hdr.syn == 1) && (recv_msg.header.tcp_hdr.ack == 1) && (recv_msg.header.tcp_hdr.ack_seq == (cli_seq + 1)))
                {
                    srv_seq = recv_msg.header.tcp_hdr.seq; //server sequence number
                    client_state = CLI_ESTABLISHED;
                }
            }
		}
		else if(client_state == CLI_ESTABLISHED)
		{

		}
		else if(client_state == CLI_FIN_WAIT_1)
		{

		}
		else if(client_state == CLI_FIN_WAIT_2)
		{

		}
		else if(client_state == CLI_TIME_WAIT)
		{

		}
	}
}        

// keeps track of the server state and iterates through tcp protocal
void * srv_thread(void *arg)
{
	while(true) //put some condition here
	{
		if(server_state == SRV_CLOSED)
		{

		}
		else if(server_state == SRV_LISTEN)
		{
            if(!recv_buff.empty())
            {
                tcp_buff recv_msg;
                pthread_mutex_lock(&recv_lock);
                recv_msg = recv_buff.front();
                recv_buff.pop_front();
                pthread_mutex_unlock(&recv_lock);
                if((recv_msg.header.tcp_hdr.syn == 1) && (recv_msg.header.tcp_hdr.ack == 0))
                {
                    cli_seq = recv_msg.header.tcp_hdr.seq; //server sequence number
                    server_state = SRV_SYN_RCVD;
                }
            }
		}
		else if(server_state == SRV_SYN_RCVD)
		{

		}
		else if(server_state == SRV_ESTABLISHED)
		{

		}
		else if(server_state == SRV_CLOSE_WAIT)
		{

		}
		else if(server_state == SRV_LAST_ACK)
		{

		}
	}    
}  

//constantly calls network send sending data in deque <tcp_buff> send_buff
void * send_thread(void *arg)
{
  
}   

//constantly checks the timeout queue for timeouts 
void * timeout_thread(void *arg)
{
  
}  

//constantly calls network recive and writes to deque <tcp_buff> rcv_buff
void * recv_thread(void *arg)
{
    while(1)
    {
        tcp_buff recv_msg;
        net.myrecvfrom(&recv_msg, sizeof(recv_msg), 0, (sockaddr*)&addr, &len);

        pthread_mutex_lock(&recv_lock);
        recv_buff.push_back(recv_msg);
        pthread_mutex_unlock(&recv_lock);        
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




