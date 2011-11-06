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

unsigned long server_ip_address;
unsigned long client_ip_address;

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
deque <tcp_buff> data_buff;
deque <timeout> timeout_buff;

pthread_mutex_t send_lock;
pthread_mutex_t recv_lock;
pthread_mutex_t data_lock;
pthread_mutex_t timeout_lock;


pthread_t sender_pthread;
pthread_t receiver_pthread;
pthread_t timeout_pthread;
pthread_t server_pthread;
pthread_t client_pthread;

sockaddr_in addr;
socklen_t len;

int cli_seq;
int next_cli_seq;
int srv_seq;
int next_srv_seq;

int msgs_out;

bool init_close;



void tcp_server_init(int port_number)
{
    if(DEBUG) printf("Server Init Called\n");
	//Server
    server = true;
    init_close =false;
    server_state = SRV_CLOSED;
    net.init(port_number);
    msgs_out = 0;

	net.getServAddr(&addr);
    printf("IP stuff: %x %u \n",addr.sin_addr.s_addr, ntohs(addr.sin_port));

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
    if(DEBUG) printf("Started Server Threads\n");
    
    pthread_join(server_pthread, NULL);
    pthread_join(timeout_pthread, NULL);    
    pthread_join(receiver_pthread, NULL);
    if(DEBUG) printf("Joined Server Threads\n");
    
}

void tcp_client_init(long unsigned int ip_address, int port_number)
{
    if(DEBUG) printf("Client Init Called\n");
	//Client
    server = false;
    init_close = false;
    client_state = CLI_CLOSED;
    server_ip_address = ip_address;
    net.init(port_number, server_ip_address);
    msgs_out = 0;
    
	net.getServAddr(&addr);
    printf("IP stuff: %x %u \n",addr.sin_addr.s_addr, ntohs(addr.sin_port));
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
    if(DEBUG) printf("Started Client Threads\n");
    
    pthread_join(client_pthread, NULL);
    pthread_join(timeout_pthread, NULL);
    pthread_join(receiver_pthread, NULL);
    if(DEBUG) printf("Joined Client Threads\n");
      
}

void tcp_client_close()
{
    if(DEBUG) printf("Client Close Called\n");
    init_close = true;
}

void tcp_client_restart()
{
    if(DEBUG) printf("Client Reset Called\n");
    if (init_close == true)
    {
        init_close = false;
    }
    else
    {
        printf("no your stupid you need to call tcp_client_close first \n");
        if(DEBUG) printf("yup still stupid\n");
    }
}

void tcp_send(const void *buffer, size_t bufferLength)
{
    
    tcp_buff send_msg;
      
    //copys application data into temp buffer
    memcpy(send_msg.data, buffer, bufferLength); 
    
    //setup header with data size
    reset_head(&send_msg.header);
    send_msg.header.data_len = bufferLength;
    
    //push temp buffer onto send buffer
    pthread_mutex_lock(&send_lock);
    send_buff.push_back(send_msg);
    if(DEBUG) printf("TCP Send Called - buffer size:%d, data size:%d\n",send_buff.size() ,bufferLength);
    pthread_mutex_unlock(&send_lock);
    
    
}

int tcp_recv(void *buffer , size_t bufferLength)
{
    
    tcp_buff recv_msg;
    
    //wait for data
    while(data_buff.empty())
    {
        continue;
    }
    
    //pull in data
    pthread_mutex_lock(&data_lock);
    recv_msg = data_buff.front();
    if(DEBUG) printf(" TCP Receive Called - buffer size:%d, data size:%d\n",data_buff.size() ,recv_msg.header.data_len);
    pthread_mutex_unlock(&data_lock);
    
    //remove from queue
    data_buff.pop_front();
    
    //copy data into buffer
    memcpy(buffer , recv_msg.data , bufferLength);
    

    
    //return data size
    return recv_msg.header.data_len;
}

// keeps track of the client state and iterates through tcp protocal
void * cli_thread(void *arg)
{
    if(DEBUG) printf("Client Thread Started\n");
	while(true) //put some condition here
	{
    	if(client_state == CLI_CLOSED)
		{
            if(DEBUG) printf("CLI_CLOSED\n");
            if(!init_close)
            {
                //setup header for intial syn
                _MYTCP_Header header;		
                reset_head(&header);
                cli_seq = CLIENT_ISN;
                next_cli_seq = CLIENT_ISN +1;
                
                //setup header
                header.tcp_hdr.seq = cli_seq;
                header.tcp_hdr.syn = 1;
                
                //send msg
                net.mysendto(&header, sizeof(header), 0, (sockaddr*)&addr, sizeof(addr));
                if(DEBUG) printf("SYN Sent\n");
                //increment state
                client_state = CLI_SYN_SENT;
                
                //make sure receive buffer is clear
                recv_buff.clear();
            }
	    }
		else if(client_state == CLI_SYN_SENT)
		{
		    //see if their is a new message
            if(!recv_buff.empty())
            {
                //get message
                tcp_buff recv_msg;
                pthread_mutex_lock(&recv_lock);
                recv_msg = recv_buff.front();
                recv_buff.pop_front();
                pthread_mutex_unlock(&recv_lock);
                
                //see if contains our ack
                if((recv_msg.header.tcp_hdr.syn == 1) 
                    && (recv_msg.header.tcp_hdr.ack == 1) 
                    && (recv_msg.header.tcp_hdr.ack_seq == (next_cli_seq)))
                {
                    //make header
                    _MYTCP_Header header;		
                    reset_head(&header);
                
                    //set server sequence
                    srv_seq = recv_msg.header.tcp_hdr.seq; 
                    
                    //increment sequnece numbers
                    cli_seq = next_cli_seq;
                    next_cli_seq += 1;
                    
                    //setup header
                    header.tcp_hdr.ack = 1;
                    header.tcp_hdr.ack_seq = srv_seq + 1;
                    header.tcp_hdr.seq = cli_seq;
                    
                    //send msg
                    net.mysendto(&header, sizeof(header), 0, (sockaddr*)&addr, sizeof(addr));
                    
                    //icrement state
                    client_state = CLI_ESTABLISHED;
                }
            }
		}
		else if(client_state == CLI_ESTABLISHED)
		{
            //run established
            established(&cli_seq, &next_cli_seq, &srv_seq, &next_srv_seq); 
            
            //check for close
            if (init_close)
            {
            
                //setup header for intial fin
                _MYTCP_Header header;		
                reset_head(&header);
                
                //icrement sequence
                cli_seq = next_cli_seq;
                next_cli_seq++;
                
                //setup header
                header.tcp_hdr.seq = cli_seq;
                header.tcp_hdr.fin = 1;
                
                //send msg
                net.mysendto(&header, sizeof(header), 0, (sockaddr*)&addr, sizeof(addr));
                
                //increment state
                client_state = CLI_FIN_WAIT_1;
                
            }
		}
		else if(client_state == CLI_FIN_WAIT_1)
		{
            //see if their is a new message
            if(!recv_buff.empty())
            {
                //get message
                tcp_buff recv_msg;
                pthread_mutex_lock(&recv_lock);
                recv_msg = recv_buff.front();
                recv_buff.pop_front();
                pthread_mutex_unlock(&recv_lock);
                
                //see if contains our ack
                if( (recv_msg.header.tcp_hdr.ack == 1) 
                    && (recv_msg.header.tcp_hdr.ack_seq == (next_cli_seq)))
                {     
                    //set server sequence
                    srv_seq = recv_msg.header.tcp_hdr.seq;
                    next_srv_seq = srv_seq + 1;
                
                    //icrement state
                    client_state = CLI_FIN_WAIT_2;
                }
            }
		}
		else if(client_state == CLI_FIN_WAIT_2)
		{
        	//see if their is a new message
            if(!recv_buff.empty())
            {
                //get message
                tcp_buff recv_msg;
                pthread_mutex_lock(&recv_lock);
                recv_msg = recv_buff.front();
                recv_buff.pop_front();
                pthread_mutex_unlock(&recv_lock);
                
                //see if contains our fin
                if(recv_msg.header.tcp_hdr.fin == 1)
                {
                    //make header
                    _MYTCP_Header header;		
                    reset_head(&header);
                
                    //set server sequence
                    srv_seq = recv_msg.header.tcp_hdr.seq; 
                    
                    //increment sequnece numbers
                    cli_seq = next_cli_seq;
                    next_cli_seq += 1;
                    
                    //setup header
                    header.tcp_hdr.ack = 1;
                    header.tcp_hdr.ack_seq = srv_seq + 1;
                    header.tcp_hdr.seq = cli_seq;
                    
                    //send msg
                    net.mysendto(&header, sizeof(header), 0, (sockaddr*)&addr, sizeof(addr));
                    
                    //icrement state
                    client_state = CLI_TIME_WAIT;
                }
            }    
		}
		else if(client_state == CLI_TIME_WAIT)
		{
            sleep(CLI_TIME_WAIT_TIME);
            client_state = CLI_TIME_WAIT;
		}
	}
}        

// keeps track of the server state and iterates through tcp protocal
void * srv_thread(void *arg)
{
    if (DEBUG) printf("Server thread started.\n");
	while(true) //put some condition here
	{
		if(server_state == SRV_CLOSED)
		{
            //@TODO setup listen socket
            
            //increment stat
            if(DEBUG) printf("SRV_CLOSED\n");
            server_state = SRV_LISTEN;
		}
		else if(server_state == SRV_LISTEN)
		{
            if(!recv_buff.empty())
            {
                if(DEBUG) printf("Received Message in SRV_LISTEN\n");
                //get message
                tcp_buff recv_msg;
                pthread_mutex_lock(&recv_lock);
                recv_msg = recv_buff.front();
                recv_buff.pop_front();
                pthread_mutex_unlock(&recv_lock);
                
                if((recv_msg.header.tcp_hdr.syn == 1) && (recv_msg.header.tcp_hdr.ack == 0))
                {
                    //create header
                    _MYTCP_Header header;
                    reset_head(&header); 
                     
                    //clients sequence number 
                    cli_seq = recv_msg.header.tcp_hdr.seq; 
                    next_cli_seq = cli_seq + 1;
                    
                    //setup ack message header
                    header.tcp_hdr.syn = 1;
                    header.tcp_hdr.ack = 1;
                    header.tcp_hdr.seq = SERVER_ISN;
                    header.tcp_hdr.ack_seq = cli_seq + 1;
                    
                    //send ack message
                    net.mysendto(&header, sizeof(header), 0, (sockaddr*)&addr, sizeof(addr));
                    
                    //increment stat
                    server_state = SRV_SYN_RCVD;
                }
            }
		}
		else if(server_state == SRV_SYN_RCVD)
		{
            if(!recv_buff.empty())
            {
                //get message
                tcp_buff recv_msg;
                pthread_mutex_lock(&recv_lock);
                recv_msg = recv_buff.front();
                recv_buff.pop_front();
                pthread_mutex_unlock(&recv_lock);
                
                if((recv_msg.header.tcp_hdr.syn == 0) && (recv_msg.header.tcp_hdr.ack == 1))
                {
                     
                    //clients sequence number 
                    cli_seq = recv_msg.header.tcp_hdr.seq; 
                    next_cli_seq = cli_seq + 1;
                    
                    //increment stat
                    server_state = SRV_ESTABLISHED;
                }
            }
		}
		else if(server_state == SRV_ESTABLISHED)
		{
            if(!established(&srv_seq, &next_srv_seq, &cli_seq, &next_cli_seq))
            {
                server_state = SRV_CLOSE_WAIT; 
            }
		}
		else if(server_state == SRV_CLOSE_WAIT)
		{
            //TODO tell aplication that the client is shuting down
            printf("recived fin bit \n");
            
            //setup header for intial syn
            _MYTCP_Header header;		
            reset_head(&header);
            
            //icrement sequence
            srv_seq = next_srv_seq;
            next_srv_seq++;
            
            //setup header
            header.tcp_hdr.seq = srv_seq;
            header.tcp_hdr.fin = 1;
            
            //send msg
            net.mysendto(&header, sizeof(header), 0, (sockaddr*)&addr, sizeof(addr));
            
            //increment state
            server_state = SRV_LAST_ACK;
		}
		else if(server_state == SRV_LAST_ACK)
		{
            if(!recv_buff.empty())
            {
                //get message
                tcp_buff recv_msg;
                pthread_mutex_lock(&recv_lock);
                recv_msg = recv_buff.front();
                recv_buff.pop_front();
                pthread_mutex_unlock(&recv_lock);
                
                if( recv_msg.header.tcp_hdr.ack == 1)
                {                    
                    //increment stat
                    server_state = SRV_CLOSED;
                }
            }
		}
	}    
} 

//constantly checks the timeout queue for timeouts 
void * timeout_thread(void *arg)
{
    if(DEBUG) printf("Timeout thread started.\n");
}  

//constantly calls network recive and writes to deque <tcp_buff> rcv_buff
void * recv_thread(void *arg)
{
    if(DEBUG) printf("Receive thread started.\n");
    bool initial_conect = true;
    while(1)
    {
        tcp_buff recv_msg;
        
        net.myrecvfrom(&recv_msg, sizeof(recv_msg), 0, (sockaddr*)&addr, &len);
        if(DEBUG) printf("Received something!\n");
        
        if(server && server_state == SRV_LISTEN)
        {
            //first message
            client_ip_address = addr.sin_addr.s_addr;
               
            pthread_mutex_lock(&recv_lock);
            recv_buff.push_back(recv_msg);
            pthread_mutex_unlock(&recv_lock);  
        }
        else
        {
            //check if from correct sender 
            if((server && (client_ip_address == addr.sin_addr.s_addr)) 
                || (!server && (server_ip_address == addr.sin_addr.s_addr)))
            {
                //store message
                pthread_mutex_lock(&recv_lock);
                recv_buff.push_back(recv_msg);
                pthread_mutex_unlock(&recv_lock);
            }
        }
    }
}

void reset_head(struct _MYTCP_Header *header)
{
    if(DEBUG) printf("Reset header called.\n");
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

bool established(int* our_seq, int* next_our_seq, int* their_seq, int* next_their_seq)
{
    if(DEBUG) printf("Established called.\n");
    //make our message
    tcp_buff send_msg;
    reset_head(&send_msg.header);
    bool no_fin = true;
    bool sending_data;
   
    //setup acks 
    if(!recv_buff.empty())
    {
        //get message
        tcp_buff recv_msg;
        pthread_mutex_lock(&recv_lock);
        recv_msg = recv_buff.front();
        recv_buff.pop_front();
        pthread_mutex_unlock(&recv_lock);
        
        //check to see if its fin
        if (recv_msg.header.tcp_hdr.fin == 1)
        {
            no_fin == false;
        }
        
        //see if contains is a message
        if(recv_msg.header.tcp_hdr.syn == 0)
        {
            //see if its our ack 
            //@TODO if we want to implement var window need to check more acks
            if(recv_msg.header.tcp_hdr.ack_seq == (next_our_seq))
            {
                //mark our message as acknowlaged
                //@TODO take out of timeout queue
                msgs_out--;
            }

            //set server sequence
            their_seq = recv_msg.header.tcp_hdr.seq;
            
            //setup header 
            send_msg.header.tcp_hdr.ack = 1;
            
            //get data
            if(recv_msg.header.data_len > 0)
            {
                //if this is the next packet in order
                if(their_seq == next_their_seq )
                {
                    //push message onto data queue
                    pthread_mutex_lock(&data_lock);
                    data_buff.push_back(recv_msg);
                    pthread_mutex_unlock(&data_lock); 
                    
                    //set sequence number
                    send_msg.header.tcp_hdr.ack_seq = 
                        their_seq + recv_msg.header.data_len; 
                        
                        
                }
                else
                {
                    //TODO for non pipelined add to queue of 
                    //packets we are not ready for 
                    printf("if we are not pipelined you should not be here \n");
                    send_msg.header.tcp_hdr.ack_seq = next_their_seq;
                }
                
            }
            else
            {
                //set sequence number fo no data
                send_msg.header.tcp_hdr.ack_seq = their_seq +1;
            }
            
            //caluclate next exspected sequence number
            next_their_seq = send_msg.header.tcp_hdr.ack_seq;

        }

    }
    
    //setup send data
    //send only if we dont have messages out
    if(!send_buff.empty() && (msgs_out < W))
    {
    
        //get data to send
        tcp_buff temp_msg;
        pthread_mutex_lock(&send_lock);
        temp_msg = send_buff.front();
        send_buff.pop_front();
        pthread_mutex_unlock(&send_lock);
        
        our_seq = next_our_seq;
        next_our_seq += temp_msg.header.data_len; 
        
        //setup header 
        send_msg.header.tcp_hdr.seq = our_seq;
        
        //add data
        memcpy(send_msg.data, temp_msg.data, temp_msg.header.data_len);
        send_msg.header.data_len = temp_msg.header.data_len;
        
        //increment messages out
        msgs_out++;
        
        //send a message
        sending_data = true;
    }
    
    if(send_msg.header.tcp_hdr.ack == 0 && sending_data)
    {
        //send msg
        net.mysendto(&send_msg, sizeof(send_msg), 0, (sockaddr*)&addr, sizeof(addr));
    }
    
    return no_fin;
}



