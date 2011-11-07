#ifndef UNP_H
#define UNP_H
/*******************************************************************************
 * @file unp.h
 * @author James Anderson <jra798>
 * @date 10/11/2011
 * @version 1.0
 * @brief specifies general includes and parameter information
 ******************************************************************************/

#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "math.h"
#include "fstream"
#include "iostream"
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/tcp.h> 
#include <signal.h> 

#define DEBUG true

#define MAXLINE          1024
/* max text line length */

#define SERV_PORT        9877   
#define SA  struct sockaddr

//tcp parameter defines
#define WINDOW_SIZE         1024    //sender receiver buffer sizeof
#define MSS                 256     //the maximum number of bytes in the data field of a TCP segment
#define W                   1       //max windows
#define TIMEOUT             100     //timeout time in milliseconds
#define NET_SEND_RATE       100      //rate of successful transmission on network
#define CLI_TIME_WAIT_TIME  30      //time to wait on final ack

#define CLIENT_ISN          100         //client inital sequence number
#define SERVER_ISN          10000       //server intial sequence number
     
     
void     dg_cli(FILE *, FILE *, int, const SA *, socklen_t);
void     dg_echo(int, SA *, socklen_t);

#endif
