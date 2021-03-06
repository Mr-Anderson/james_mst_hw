#ifndef MYTCP_H
#define MYTCP_H
/*******************************************************************************
 * @file myTCP.h
 * @author James Anderson <jra798>, Adam Honse <amhb59>
 * @date 10/11/2011
 * @version 1.0
 * @brief TCP protocal code 
 ******************************************************************************/

#include	"unp.h"
#include	"myNetwork.h"
#include    <pthread.h>
#include    <deque>
#include    <vector>

using namespace std;

 

typedef struct _MYTCP_Header 
{
    struct tcphdr tcp_hdr;
    u_short data_len; //  the actual number of bytes in the data field. 
} __attribute__ ((packed)) MYTCPHeader;

struct tcp_buff
{
    struct _MYTCP_Header header;
    char data[WINDOW_SIZE];
};

//client
void tcp_server_init(int port_number);

//server
void tcp_client_init(long unsigned int ip_address, int port_number);

//function to send data
void tcp_send(const void *msg, size_t len);

//function to recieve data
int tcp_recv(void *buf, size_t len);

//server thread
void * srv_thread(void *arg);

//client thread
void * cli_thread(void *arg);

//timeout thread
void * timeout_thread(void *arg);

//recever thread
void * recv_thread(void *arg);

//initalizes a header
void reset_head(struct _MYTCP_Header *header);

//established loop
bool established(int* our_seq, int* next_our_seq, int* their_seq, int* next_their_seq );

//close tcp
void tcp_client_close();

//sender function
void timeout_send(void* send_msg, size_t bufferLength, bool retransmission = false);

#endif
