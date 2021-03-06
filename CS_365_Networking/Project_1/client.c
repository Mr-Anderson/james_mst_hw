/*******************************************************************************
 * @file client.c
 * @author James Anderson <jra798>, Adam Honse <amhb59>
 * @date 10/11/2011
 * @version 1.0
 * @brief reads in specified file and sends to specified IP then wites receved 
 *  messages to output file
 ******************************************************************************/

#include	"unp.h"
#include	"myTCP.h"

int main(int argc, char **argv)
{

    FILE *in_fp; 
    FILE *out_fp;

    // check to see if their are the correct number of arguments
    if (argc != 5)
    {
        fputs(" usage: client <IPaddress> <Port> <InputFile> <OutputFile> \r \n", stderr);
        exit(0);
    }
    
    //Open input and output file
    in_fp=fopen (argv[3] , "r");
    out_fp=fopen (argv[4] , "w+");

    //if file opens 
    if (in_fp == NULL) perror ("Error opening file");
    else
    {
        
        int n;
        char sendline[MAXLINE], recvline[MAXLINE + 1];
        
        int port = atoi(argv[2]);
        
        struct in_addr ip;
        inet_pton(AF_INET, argv[1], &ip); 
        //Create new TCP pipe

        printf("IP in hex: %x Port: %u\n",ip.s_addr, port);
        tcp_client_init(ip.s_addr, port);
        do  
        {
            if(DEBUG) printf("Reading file\n");
            //read in file line
            n = fread(sendline, 1, MAXLINE ,in_fp);

            tcp_send(sendline, n);

            n = tcp_recv(recvline, MAXLINE);
            
            if(DEBUG) printf("Writing to file\n");
            fwrite(recvline ,1, n , out_fp);
        }while (!feof(in_fp));
        
        //closing file
        if(DEBUG) printf("closing file\n");
        fclose (in_fp);
        fclose (out_fp);
        
        tcp_client_close();
    }
    
    exit(0);
}

