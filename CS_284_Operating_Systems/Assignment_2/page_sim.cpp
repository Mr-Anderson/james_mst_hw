/*******************************************************************************
 * @file myTCP.c
 * @author James Anderson <jra798>
 * @date 10/11/2011
 * @version 1.0
 * @brief reads in specified file and sends to specified IP then wites receved 
 * messages to output file
 ******************************************************************************/

#include	"page_sim.h"


int main(int argc, char **argv)
{

    // check to see if their are the correct number of arguments
    if (argc != 6)
    {
        fputs(" usage: page_sim <programlist file>   \r \n", stderr);
        fputs("<programtrace file> <page size>  \r \n", stderr);
        fputs(" <page replacement algorithum : lru/fifo/clock >  <prepaging/demandpaging : p/d> \r \n", stderr);
        exit(0);
    }
    
    //open program list file

    programlist_fp = fopen (argv[1] , "r");
    if (programlist_fp == NULL) perror ("Error opening program list file");
    
    programtrace_fp = fopen (argv[2] , "r");
    if (programtrace_fp == NULL) perror ("Error opening program trace file");
    
    page_size = (int) argv[3];
    //do page cration stuff
    
    cout<< "argv[6]:" << argv[4] << endl;
    
    //get mode
    if(argv[5] == "p" || argv[5] == "P") mode = prepaging;
    else if(argv[5] == "d" || argv[5] == "D") mode = demandpaging;
    else perror ("Cannot determine paging mode selection");
    
    //get algorithum
    if(argv[4] == "lru" || argv[4] == "LRU") algo == lru;
    else if(argv[4] == "fifo" || argv[4] == "FIFO") algo = fifo;
    else if(argv[4] == "clock" || argv[4] == "CLOCK") algo = clk;
    else perror ("Cannot determine paging algorithum selection");
    
    //read in program list
    unsigned long unq_name = 0;
    while(!feof(programlist_fp))
    {
        int name, size, pages;
        Program program;
        
        fscanf(programlist_fp, "%d", &name);
        fscanf(programlist_fp, "%d", &size);
        
        //cout<< "adding program "<< name << endl;
        
        pages = size/page_size;
        
        program.name = name;
        program.size = size;
        program.pages = pages;
        
        //create pages
        for(int i = 0; i < pages ; i++)
        {
            //create page
            Page page;
            page.name = unq_name;
            page.owner = name;
            page.in_memory = false;
            
            //add page to pagefile
            program.pagefile.push_back(page);
        }
        
        //add program to program list
        programs.push_back(program);
    }

/*     //read in programtrace and simulate 
    while(!feof(progratrace_fp))
    {
        int n;
        int name, size, pages;
        struct Page program;
        n = fscanf(programtrace_fp, "d", name);
        n = fscanf(programlist_fp, "d", size);
        
        pages = size/page_size;
        
        program.name = name;
        program.size = size;
        program.pages = pages;
        
        programs.push_back(program);
    } */
    
    fclose (programlist_fp);
    fclose (programtrace_fp);

}




