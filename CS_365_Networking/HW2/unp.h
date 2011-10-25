/*							*/
/* 	relevant part in unp.h 	*/
/*							*/

#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "fstream"
#include "iostream"
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>




#define	MAXLINE			 4096
/* max text line length */

#define	SERV_PORT		 9877	
#define	SA	struct sockaddr
	 
void	 dg_cli(FILE *, int, const SA *, socklen_t);
void	 dg_echo(int, SA *, socklen_t);
