 /******************************************************************************
 * @file server.c
 * @author James Anderson <jra798>
 * @date 10/11/2011
 * @version 1.0
 * @brief contains shared defines and includes for Assignment 3 Project
 ******************************************************************************/
 
#include <signal.h>
#include <unistd.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h> 
#include <sys/socket.h>  /* define socket */ 
#include <netinet/in.h>  /* define internet socket */ 
#include <netdb.h>
#include <time.h>

#define SERVER_PORT              9877 //defines operating port
#define CLIENT_SUPPORT           10 //defines number of clients that can connect
#define MAX_BUFFER_SIZE          512 //

