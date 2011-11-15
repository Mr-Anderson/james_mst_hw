 /******************************************************************************
 * @file server.c
 * @author James Anderson <jra798>
 * @date 10/11/2011
 * @version 1.0
 * @brief contains shared defines and includes for Assignment 3 Project
 ******************************************************************************/
 
#incude <signal.h>
#incude <sys/socket.h>
#include <unistd.h>
#include <vector>
#include <stdio>
#include <stdlib.h>

#define SERVER_PORT              9877 //defines operating port
#define CLIENT_SUPPORT    10 //defines number of clients that can connect


