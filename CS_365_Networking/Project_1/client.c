/*******************************************************************************
 * @file client.c
 * @author James Anderson <jra798>
 * @date 10/11/2011
 * @version 1.0
 * @brief reads in specified file and sends to specified IP then wites receved 
 *  messages to output file
 ******************************************************************************/

#include	"unp.h"
#include	"myTCP.h"

int main(int argc, char **argv)
{

    // check to see if their are the correct number of arguments
    if (argc != 5)
    {
        fputs(" usage: client <IPaddress> <Port> <InputFile> <OutputFile> \r \n", stderr);
        exit(0);
    }
    
    //Create new TCP pipe
    myTCP tcp(argv[1], argv[2]);

    //Open input and output file
    in_pf=fopen (argv[3] , "r");
    out_pf=fopen (argv[4] , "w+");

    //if file opens 
    if (in_pf == NULL) perror ("Error opening file");
    else
    {
        int n;
        char sendline[MAXLINE], recvline[MAXLINE + 1];
        
        while (!feof(in_fp)) 
        {
            //read in file line
            n = fread(sendline, 1, MAXLINE ,in_fp);
           
            tcp.send(sendline, n);

            n = tcp.recv(recvline, MAXLINE);
            
            fwrite(recvline ,1, n , out_fp);
        }

        fclose (in_pf);
        fclose (out_pf);
    }
    
    exit(0);
}

