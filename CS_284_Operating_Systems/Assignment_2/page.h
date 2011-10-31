#ifndef MYTCP_H
#define MYTCP_H
////////////////////////////////////////////////////////////////////////////////
/// @file page_sim.h
/// @author James Anderson <jra798>
/// @date 10/11/2011
/// @version 1.0
/// @brief header file for page file simulator
////////////////////////////////////////////////////////////////////////////////

#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "math.h"
#include "fstream"
#include "iostream"


using namespace std;


//client
void tcp_server_init(int port_number);

//server
void tcp_client_init(char * ip_address, int port_number);

//function to send data
void tcp_send(const void *msg, size_t len);

//function to recieve data
int tcp_recv(void *buf, size_t len);

//sender thread
void * send_thread(void *arg);

//recever thread
void * recv_thread(void *arg);

//initalizes a header
void reset_head(struct _MYTCP_Header *header);


//global variables for storing args
FILE *programlist_fp;

FILE *programtrace_fp;

int page size;

enum page_replacement_algo { lru, fifo, clock}; 

page_replacement_algo algo;

enum paging_mode { prepaging, demandpaging}; 

paging_mode mode;

#endif
