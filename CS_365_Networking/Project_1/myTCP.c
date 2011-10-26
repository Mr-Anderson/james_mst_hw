#ifndef MYTCP_C
#define MYTCP_C
/*******************************************************************************
 * @file myTCP.c
 * @author James Anderson <jra798>
 * @date 10/11/2011
 * @version 1.0
 * @brief reads in specified file and sends to specified IP then wites receved 
 * messages to output file
 ******************************************************************************/

#include	"myTCP.h"



void myTCP::void sendto(int sid, const void *buffer, size_t bufferLength,
                        int flag, sockaddr *addr, socklen_t addrLength)
{
    
    
    
};

int myTCP::recvfrom(int sid, const void *buffer , size_t bufferLength, 
				    int flag, sockaddr *addr, int addrLength);
{
  
    
    
};
#endif
