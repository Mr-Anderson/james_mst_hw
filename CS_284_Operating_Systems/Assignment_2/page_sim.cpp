/*******************************************************************************
 * @file myTCP.c
 * @author James Anderson <jra798>
 * @date 10/11/2011
 * @version 1.0
 * @brief reads in specified file and sends to specified IP then wites receved 
 * messages to output file
 ******************************************************************************/

#include	"myTCP.h"


int main(int argc, char **argv)
{

    // check to see if their are the correct number of arguments
    if (argc != 6)
    {
        fputs(" usage: page_sim <programlist file> <programtrace file> <page size> <page replacement algorithum : lru/fifo/clock > <prepageing/demandpaging : p/d> \r \n", stderr);
        exit(0);
    }
    
    //open program list file

    programlist_fp = fopen (argv[1] , "r");
    if (programlist_fp == NULL) perror ("Error opening program trace file");
    
    programtrace_fp = fopen (argv[2] , "r");
    if (programtrace_fp == NULL) perror ("Error opening program list file");
    
    
    //Open input and output file
    in_fp=fopen (argv[3] , "r");
    out_fp=fopen (argv[4] , "w+");


}




