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



struct timeout
{  
    //message that needs to be resent
    tcp_buff msg;
    
    //Ack sequence to remove timout
    unsigned int ack_seq;

    //time of messages timeout
    clock_t endtime;
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
vector <tcp_buff> ack_buff;
vector <timeout> timeout_buff;

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
    net.getServAddr(&addr);
    msgs_out = 0;

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
      
}

void tcp_client_close()
{
    if(DEBUG) printf("Client Close Called\n");
    init_close = true;
    while(client_state != CLI_CLOSED)
    {
        continue;
    }

    pthread_kill(client_pthread, SIGKILL);
    pthread_kill(timeout_pthread, SIGKILL);
    pthread_kill(receiver_pthread, SIGKILL);
    
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
    //set isns
    cli_seq = CLIENT_ISN ;
    next_cli_seq = CLIENT_ISN; 
    bool wait_init = true;
    time_t time_wait;    
    
    if(DEBUG) printf("Client Thread Started\n");
	for(;;) //put some condition here
	{
	    //set bit for incementing seq once on first syn and fin 
	    bool init = false;
	    bool send = false;
	    
	    //reset msg
	    tcp_buff send_msg;
	    reset_head(&send_msg.header);
	     
	    

        if(client_state == CLI_ESTABLISHED )
	    {
	        pthread_mutex_lock(&timeout_lock);
            if(init_close)
            {
                //send fin bit 
                send_msg.header.tcp_hdr.fin = 1;

                init = true;
                
                //tell it to send
                send = true;
                
                client_state = CLI_FIN_WAIT_1;
                if(DEBUG) printf("CLI_FIN_WAIT_1\n");
            }
	        else if(!send_buff.empty() &&  (timeout_buff.size() < W))
	        {
	            //send data
                //get data to send
                tcp_buff temp_msg;
                pthread_mutex_lock(&send_lock);
                temp_msg = send_buff.front();
                send_buff.pop_front();
                pthread_mutex_unlock(&send_lock);

                //tell it to send
                send = true;

                //add data
                memcpy(send_msg.data, temp_msg.data, temp_msg.header.data_len);
                send_msg.header.data_len = temp_msg.header.data_len;
	        }
	        pthread_mutex_unlock(&timeout_lock);  

	    }
	    else if(client_state == CLI_TIME_WAIT)
        {
            if(wait_init)
            {
                if(DEBUG) printf("Client Time Wait\n");
                time_wait = time(NULL) + CLI_TIME_WAIT_TIME;
                
                wait_init = false;
            }
            else if(time_wait <= time(NULL) )
            {
                timeout_buff.clear();
                client_state = CLI_CLOSED;
                if(DEBUG) printf("CLI_CLOSED\n");
            }
        }
	    
	    
	    
	    
	    
	    
		if(client_state == CLI_CLOSED)
	    {             
                usleep(100000);  
                if(DEBUG) printf("Sending Initial SYN\n");
                
                //setup initial syn 
                send_msg.header.tcp_hdr.syn = 1;                
                
                init = true;
                
                //tell it to send
                send = true;
                
                //increment state
                client_state = CLI_SYN_SENT;
                if(DEBUG) printf("CLI_SYN_SENT\n");
	    }
	    else if(!recv_buff.empty())
        {
            //get message
            tcp_buff recv_msg;
            pthread_mutex_lock(&recv_lock);
            recv_msg = recv_buff.front();
            recv_buff.pop_front();
            pthread_mutex_unlock(&recv_lock);
	        
	        //see if we need to ack 
	        if(recv_msg.header.data_len > 0 
	           || recv_msg.header.tcp_hdr.fin == 1
	           || recv_msg.header.tcp_hdr.syn == 1)
	        {
	            //ack data
	            send_msg.header.tcp_hdr.ack = 1;
	            
	            //tell it to send
	            send = true;
	         
	            //see if their is data 
	            if(recv_msg.header.data_len > 0)
	            {
	                //see if its the next data in our seq
	                if(recv_msg.header.tcp_hdr.seq == next_srv_seq)
	                {
	                    //add to data
	                    pthread_mutex_lock(&data_lock);
                        data_buff.push_back(recv_msg);
                        pthread_mutex_unlock(&data_lock);
                        
                        //increment expected seq
                        srv_seq = recv_msg.header.tcp_hdr.seq;
                        next_srv_seq = srv_seq + recv_msg.header.data_len;
	                }
	                
	                //set ack seq
	                //TODO needs to be changed if pipelined
	                send_msg.header.tcp_hdr.ack_seq =
	                    recv_msg.header.tcp_hdr.seq + recv_msg.header.data_len;
	            } 
	            else if(recv_msg.header.tcp_hdr.fin == 1)
	            {
	                if(client_state == CLI_FIN_WAIT_2)
	                {
                        //increment expected seq
	                    srv_seq = recv_msg.header.tcp_hdr.seq;
                        next_srv_seq = srv_seq + 1;
                        
	                    
	                    //move to close wait
	                    client_state = CLI_TIME_WAIT;
	                    if(DEBUG) printf("CLI_TIME_WAIT_1\n");
	                }
	                
	                //set ack seq
	                send_msg.header.tcp_hdr.ack_seq = 
	                    recv_msg.header.tcp_hdr.seq + 1;
  
	            }
	            else if (recv_msg.header.tcp_hdr.syn == 1 
	                  && recv_msg.header.tcp_hdr.ack == 1)
	            {  
	                //got syn ack
                    if(client_state == CLI_SYN_SENT)
                    {            
                        //get servers sequence number 
                        srv_seq = recv_msg.header.tcp_hdr.seq; 
                        next_srv_seq = srv_seq + 1;
                        
                        client_state = CLI_ESTABLISHED;
                        if(DEBUG) printf("CLI_ESTABLISHED_1\n");
                    }
	               
                    //set ack seq
                    send_msg.header.tcp_hdr.ack_seq = 
                       recv_msg.header.tcp_hdr.seq + 1; 
	            }

	            
	                    
	            
	        }
            else if(client_state == CLI_FIN_WAIT_1
             && recv_msg.header.tcp_hdr.ack == 1)
            {         
                
                //got fin ack   
                //get servers sequence number 
                srv_seq = recv_msg.header.tcp_hdr.seq; 
                next_srv_seq = srv_seq + 1;
                
                client_state = CLI_FIN_WAIT_2;
                if(DEBUG) printf("CLI_FIN_WAIT_2\n");
                
                
            }    
	        
	        
        }
        

	    if (send)
	    {
            cli_seq = next_cli_seq;
	        
	        //setup header
            send_msg.header.tcp_hdr.seq = cli_seq;
                        
            //send msg
            timeout_send(&send_msg, sizeof(send_msg));
	    
	        //send message and increment seq num
	        if(!(send_msg.header.tcp_hdr.ack == 1 
	            && send_msg.header.data_len == 0 )
	            || init)
            {
                
                
                if(send_msg.header.data_len == 0)
                {
                    next_cli_seq++;
                }
                else
                {
                    next_cli_seq += send_msg.header.data_len;
                }
                
            }

        }


        usleep(10000);

	}
}        

// keeps track of the server state and iterates through tcp protocal
void * srv_thread(void *arg)
{
    //set isns
    srv_seq = SERVER_ISN ;
    next_srv_seq = SERVER_ISN; 
    
    if (DEBUG) printf("Server thread started.\n");
	for(;;) //put some condition here
	{
	
		//set bit for incementing seq once on first syn and fin 
	    bool init = false;
	    bool send = false;
	    
	    //reset msg
	    tcp_buff send_msg;
	    reset_head(&send_msg.header);
	     
	    
		if(server_state == SRV_CLOSED)
	    {            
                //increment stat
                if(DEBUG) printf("SRV_CLOSED\n");
                server_state = SRV_LISTEN;
                if(DEBUG) printf("SRV_LISTEN\n");
	    }
	    else if(!recv_buff.empty())
        {
            //get message
            tcp_buff recv_msg;
            pthread_mutex_lock(&recv_lock);
            recv_msg = recv_buff.front();
            recv_buff.pop_front();
            pthread_mutex_unlock(&recv_lock);
	        
	        //see if we need to ack 
	        if(recv_msg.header.data_len > 0 
	           || recv_msg.header.tcp_hdr.fin == 1
	           || recv_msg.header.tcp_hdr.syn == 1)
	        {
	            //ack data
	            send_msg.header.tcp_hdr.ack = 1;
	            
	            //send message
	            send = true;
	            
	            //see if their is data 
	            if(recv_msg.header.data_len > 0)
	            {
	                //see if its the next data in our seq
	                if(recv_msg.header.tcp_hdr.seq == next_cli_seq)
	                {
	                    //add to data
	                    pthread_mutex_lock(&data_lock);
                        data_buff.push_back(recv_msg);
                        pthread_mutex_unlock(&data_lock);
                        
                        //increment expected seq
                        cli_seq = recv_msg.header.tcp_hdr.seq;
                        next_cli_seq = cli_seq + recv_msg.header.data_len;
	                }
	                
	                //set ack seq
	                //TODO need more here for pipelined
	                send_msg.header.tcp_hdr.ack_seq =
	                    recv_msg.header.tcp_hdr.seq + recv_msg.header.data_len;
	            } 
	            else if(recv_msg.header.tcp_hdr.fin == 1)
	            {
	                if(server_state == SRV_ESTABLISHED)
	                {
                        //increment expected seq
	                    cli_seq = recv_msg.header.tcp_hdr.seq;
                        next_cli_seq = cli_seq + 1;
	                    
	                    //move to close wait
	                    server_state = SRV_CLOSE_WAIT;
	                    if(DEBUG) printf("SRV_CLOSE_WAIT\n");
	                }
	                
	                //set ack seq
	                send_msg.header.tcp_hdr.ack_seq = 
	                    recv_msg.header.tcp_hdr.seq + 1;
  
	            }
	            else if (recv_msg.header.tcp_hdr.syn == 1 )
	            {  
                    if(server_state == SRV_LISTEN)
                    {            
                        //get clients sequence number 
                        cli_seq = recv_msg.header.tcp_hdr.seq; 
                        next_cli_seq = cli_seq + 1;
                        
                        init = true;
                        
                        server_state = SRV_SYN_RCVD;
                        if(DEBUG) printf("SRV_SYN_RCVD\n");
                    }
                    
                    //set syn bit 
                    send_msg.header.tcp_hdr.syn = 1;

                    //set ack seq
                    send_msg.header.tcp_hdr.ack_seq = 
                       recv_msg.header.tcp_hdr.seq + 1; 
	            }
	                    
	            
	        }
        	else if (server_state == SRV_SYN_RCVD)
            {
                //get ack to our syn ack
                if(recv_msg.header.tcp_hdr.ack == 1 
                    && recv_msg.header.tcp_hdr.ack_seq == next_srv_seq)
                {
                    
                    //move to established
                    server_state = SRV_ESTABLISHED;
                    if(DEBUG) printf("SRV_ESTABLISHED\n");
                }
            }
            else if (server_state == SRV_LAST_ACK)
            {
                //get ack to our fin
                if(recv_msg.header.tcp_hdr.ack == 1
                    && recv_msg.header.tcp_hdr.ack_seq == next_srv_seq)
                {
                    
                    //move to established
                    server_state = SRV_CLOSED;
                    if(DEBUG) printf("SRV_CLOSED\n");
                }
            }

        }
        
        
        if(server_state == SRV_ESTABLISHED)
	    {
            //if(DEBUG) printf("%u %u\n",send_buff.empty(),timeout_buff.size());
	        if(!send_buff.empty() && (timeout_buff.size() < W))
	        {
	            
	            //send data
                //get data to send
                tcp_buff temp_msg;
                pthread_mutex_lock(&send_lock);
                temp_msg = send_buff.front();
                send_buff.pop_front();
                pthread_mutex_unlock(&send_lock);

                //tell it to send
                send = true;

                //add data
                memcpy(send_msg.data, temp_msg.data, temp_msg.header.data_len);
                send_msg.header.data_len = temp_msg.header.data_len;
	        }  

	    }
	    else if (server_state == SRV_CLOSE_WAIT)
	    {
	        if(DEBUG) printf("Server Shutting Down \n");
	        //send fin after ack
	        if(send_msg.header.tcp_hdr.ack == 0 )
	        {
	            send_msg.header.tcp_hdr.fin = 1;
	            init = true;
	           
	            send = true;
	            
	           	//move to last ack
	            server_state = SRV_LAST_ACK;
	            if(DEBUG) printf("SRV_LAST_ACK\n");
	        }
	    }

	    if(send)
	    {
	    
            srv_seq = next_srv_seq;

	        //setup header
            send_msg.header.tcp_hdr.seq = srv_seq;
            
            //send msg
            timeout_send(&send_msg, sizeof(send_msg));	    
	    
	        //send message and increment seq num
	        if(!(send_msg.header.tcp_hdr.ack == 1 
	            && send_msg.header.data_len == 0 )
	            || init)
            {

                if(send_msg.header.data_len == 0 )
                {
                    next_srv_seq++;
                }
                else
                {
                    next_srv_seq += send_msg.header.data_len;
                }
                
            }

        }

        usleep(10000);

	}    
} 

//constantly checks the timeout queue for timeouts 
void * timeout_thread(void *arg)
{
    if(DEBUG) printf("Timeout thread started.\n");
    while(1)
    {
        pthread_mutex_lock(&timeout_lock);
        //iterate trough timeouts
        for(int i = 0; i < timeout_buff.size(); i++)
        {
            //remove message from timeout queue
            if(timeout_buff[i].endtime <= clock())
            {
                if(DEBUG) printf("Seq %u timed out. Number of timeouts being tracked is %u \n",timeout_buff[i].msg.header.tcp_hdr.seq,timeout_buff.size());
                timeout temp;
                
                
                temp = timeout_buff[i];
                
                //erase old timout
                timeout_buff.erase(timeout_buff.begin() +i);
                
                //unlock and resend message
                pthread_mutex_unlock(&timeout_lock);
                timeout_send( &temp, sizeof(temp), true);
                pthread_mutex_lock(&timeout_lock);
                   
            }
        }
        pthread_mutex_unlock(&timeout_lock);
    }
}  

//constantly calls network recive and writes to deque <tcp_buff> rcv_buff
void * recv_thread(void *arg)
{
    if(DEBUG) printf("Receive thread started.\n");
    bool initial_conect = true;
    for(;;)
    {
        tcp_buff recv_msg;
        
        len = sizeof(addr);
        
        net.myrecvfrom(&recv_msg, sizeof(recv_msg), 0, (sockaddr*)&addr, &len);
        
        if(DEBUG) printf("Received syn:%u	fin:%u	ack:%u	ack_seq:%u	seq:%u		data_len:%u \n",
        recv_msg.header.tcp_hdr.syn,
        recv_msg.header.tcp_hdr.fin,
        recv_msg.header.tcp_hdr.ack, 
        recv_msg.header.tcp_hdr.ack_seq, 
        recv_msg.header.tcp_hdr.seq, 
        recv_msg.header.data_len);
        
        if(server && (server_state == SRV_LISTEN))
        {
            //first message
            client_ip_address = addr.sin_addr.s_addr;
            
            char char_ip[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, &addr.sin_addr.s_addr, char_ip, INET_ADDRSTRLEN);
            //if(DEBUG) printf("Locking Client to %s \n",char_ip);
            
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
                
                //check to see if its an ack we need to send
            }

        }
        
        //check if message is an ack
        if(recv_msg.header.tcp_hdr.ack == 1)
        {
            pthread_mutex_lock(&timeout_lock);
            //find message it is an ack to 
            for(int i = 0; i < timeout_buff.size(); i++ )
            {
                //remove message from timeout queue
                if((timeout_buff[i].ack_seq == recv_msg.header.tcp_hdr.ack_seq) || (timeout_buff[i].msg.header.tcp_hdr.syn == 1))
                {
                    if(DEBUG) printf("Erased Timeout %u size %u \n",timeout_buff[i].msg.header.tcp_hdr.seq, timeout_buff.size());
                    timeout_buff.erase(timeout_buff.begin() +i);
                }
            }
            pthread_mutex_unlock(&timeout_lock);
        }
    }
}

void reset_head(struct _MYTCP_Header *header)
{
    //if(DEBUG) printf("Reset header called.\n");
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




void timeout_send(void* send_msg, size_t bufferLength, bool retransmission = false)
{
    if( ((tcp_buff*)send_msg)->header.tcp_hdr.syn == 1 || ((tcp_buff*)send_msg)->header.tcp_hdr.fin == 1 || ((tcp_buff*)send_msg)->header.data_len > 0 )
    {
        timeout tout;
        
        //add msg and endtime to timout
        tout.endtime = clock()  + ((TIMEOUT/1000.0) * CLOCKS_PER_SEC  );
        tout.msg = *(tcp_buff*)send_msg;
        if(!retransmission)
        {
            if(((tcp_buff*)send_msg)->header.data_len == 0)
            {
                tout.ack_seq = ((tcp_buff*)send_msg)->header.tcp_hdr.seq + 1;
            }
            else
            {
                tout.ack_seq = ((tcp_buff*)send_msg)->header.tcp_hdr.seq + ((tcp_buff*)send_msg)->header.data_len;
            }
        }
        else
        {
            tout.ack_seq = ((timeout*)send_msg)->ack_seq;
        }

        //push timeout struct onto timout list
        pthread_mutex_lock(&timeout_lock);
        if(DEBUG) printf("Added timeout seq=%u\n", tout.msg.header.tcp_hdr.seq);
        timeout_buff.push_back(tout);
        pthread_mutex_unlock(&timeout_lock);
        
        if(DEBUG) printf("Sending  syn:%u	fin:%u	ack:%u	ack_seq:%u	seq:%u		data_len:%u our ack seq:%u \n",
        ((tcp_buff*)send_msg)->header.tcp_hdr.syn,
        ((tcp_buff*)send_msg)->header.tcp_hdr.fin,
        ((tcp_buff*)send_msg)->header.tcp_hdr.ack, 
        ((tcp_buff*)send_msg)->header.tcp_hdr.ack_seq, 
        ((tcp_buff*)send_msg)->header.tcp_hdr.seq, 
        ((tcp_buff*)send_msg)->header.data_len,
        tout.ack_seq);
    }
    else
    {
        if(DEBUG) printf("Sending  syn:%u	fin:%u	ack:%u	ack_seq:%u	seq:%u		data_len:%u our ack seq:%u \n",
        ((tcp_buff*)send_msg)->header.tcp_hdr.syn,
        ((tcp_buff*)send_msg)->header.tcp_hdr.fin,
        ((tcp_buff*)send_msg)->header.tcp_hdr.ack, 
        ((tcp_buff*)send_msg)->header.tcp_hdr.ack_seq, 
        ((tcp_buff*)send_msg)->header.tcp_hdr.seq, 
        ((tcp_buff*)send_msg)->header.data_len);
    }
    

        
    //send message
    net.mysendto(send_msg, bufferLength, 0, (sockaddr*)&addr, sizeof(addr));
}



