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
        fputs(" usage: page_sim <programlist file> <programtrace file> <page size> <page replacement algorithum : lru/fifo/clock > <prepaging/demandpaging : p/d> \r \n", stderr);
        exit(0);
    }
    
    //open program list file

    programlist_fp = fopen (argv[1] , "r");
    if (programlist_fp == NULL) perror ("Error opening program list file");
    
    programtrace_fp = fopen (argv[2] , "r");
    if (programtrace_fp == NULL) perror ("Error opening program trace file");
    
    page_size = argv[3];
    //do page cration stuff
    
    //get mode
    if(argv[5] == p || argv[5] == P) mode = prepaging;
    else if(argv[5] == d || argv[5] == D) mode = demandpaging;
    else perror ("Cannot determine paging mode selection");
    
    if(argv[4] == lru || argv[4] == LRU)
    {
        algo == lru;
        // do lru stuff
    }
    else if(argv[4] == fifo || argv[4] == FIFO) 
    {
        algo = fifo;
        // do fifo stuff
    }
    else if(argv[4] == clock || argv[4] == CLOCK) 
    {
        algo = clock;
    }
    else perror ("Cannot determine paging algorithum selection");
    


}




