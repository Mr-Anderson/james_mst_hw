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



#define MAXLINE          4096
/* max text line length */

#define SERV_PORT        9877   
#define SA  struct sockaddr

//tcp parameter defines
#define WINDOW_SIZE         1024 //sender receiver buffer sizeof
#define MSS             256  //the maximum number of bytes in the data field of a TCP segment
#define W               4    // max windows

#define CLIENT_ISN      0     //client inital sequence number
#define SERVER_ISN      1000  //server intial sequence number
     
     
void     dg_cli(FILE *, FILE *, int, const SA *, socklen_t);
void     dg_echo(int, SA *, socklen_t);

#endif
