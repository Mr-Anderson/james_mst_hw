/*******************************************************************************
 * @file myTCP.c
 * @author James Anderson <jra798>
 * @date 10/11/2011
 * @version 1.0
 * @brief reads in specified file and sends to specified IP then wites receved 
 * messages to output file
 ******************************************************************************/

#include	"page_sim.h"

//removes the specified page from memory and loads another
void pagefault(Page* remove, Page* load)
{
    remove->in_memory = false;
    load->in_memory = true;
    
    load->memory_location = remove->memory_location;
    
    // set clock and other vars for algos
    if(algo == lru)
    {
        load->access_t = program_clock;
        program_clock++;
    }
    else if (algo == clk)
    {
        load->used = true;
    }
    else if (algo == fifo)
    {
        fifo_queue.pop();
        fifo_queue.push(load);
    }
}

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
    
    page_size =  atoi(argv[3]);
    //do page cration stuff
    
    cout<< "argv[6]:" << argv[4] << endl;
    
    //get mode
    if(argv[5] == "p" || argv[5] == "P") mode = prepaging;
    else if(argv[5] == "d" || argv[5] == "D") mode = demandpaging;
    else
    { 
    perror ("Cannot determine paging mode selection");
    cout<<"mode:"<<mode<<endl;
    }
    
    
    
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
            
            total_pages++;
            
            //add page to pagefile
            program.pagefile.push_back(page);
        }
        
        //add program to program list
        programs.push_back(program);
    }
    
    //empty main memory
    
    //set program clock to empty
    program_clock =0;
    
    //alocate default memory load
    int default_load = MEMORY_SIZE/(page_size * programs.size());
    for(int i=0; i < programs.size(); i++)
    {
        for(int j=0; j < default_load; j++)
        {
            Page *page_p = &programs[i].pagefile[j];
            
            //set tracking bits
            page_p->in_memory = true;
            page_p->memory_location = main_memory.size();
            
            // set clock and other vars for algos
            if(algo == lru)
            {
                page_p->access_t = program_clock;
                program_clock++;
            }
            else if (algo == clk)
            {
                page_p->used = false;
            }
            else if (algo == fifo)
            {
                fifo_queue.push(page_p);
            }
            
            //push into main memory
            main_memory.push_back(page_p);
            
        }
    }
    //fill last couple memory locations with null
    //since pagesize is in powers of 2 this should always fill exactly
    while((main_memory.size() * page_size) < MEMORY_SIZE)
    {
        Page *page_p = NULL;
        main_memory.push_back(page_p);
    }
    
    if(main_memory.size() == (MEMORY_SIZE / page_size))
    {
        memory_full = true;
    }
    else
    {
        memory_full == false;
    }
    
    //initialize page fault counter
    page_faults =0;
    clock_hand = 0;
    
     //read in programtrace and simulate 
    while(!feof(programtrace_fp))
    {
        int program, location, pages;
        Program *program_p;
        Page *page_p;
        
        //read 
        fscanf(programtrace_fp, "%d", &program);
        fscanf(programlist_fp, "%d", &location);
        
        //calculate page location
        location = location/page_size;
        
        //find program
        program_p = &programs[program];
        
        //find page
        page_p = &program_p->pagefile[location];
        
        // check to see if page is in memory
        if(page_p->in_memory)
        {
            // set clock and other vars for algos
            if(algo == lru)
            {
                page_p->access_t = program_clock;
                program_clock++;
            }
            else if (algo == clk)
            {
                page_p->used = true;
            }
            //nothing to do for fifo
        }
        else
        {
            //page fault
            page_faults++;
            
            int load_num;
            //check demand or prepaging
            if (mode = demandpaging)
            {
                load_num = 1;
            }
            else
            {
                load_num = 2;
            }
            
            for(int j = 0; j < load_num; j++)
            {
                 // handel page fault
                if(memory_full)
                {
                    //look for page to replace
                    Page *replace_p = NULL;
                    if(algo == lru)
                    {
                        // set lowest time to a memory time
                        unsigned long lowest_time = main_memory[0]->access_t;
                        replace_p = main_memory[0];
                        //check all memory for lowest time
                        for(int i = 0; i < main_memory.size(); i++)
                        {
                            if(main_memory[i]->access_t < lowest_time)
                            {
                                lowest_time = main_memory[i]->access_t;
                                replace_p = main_memory[i];
                            }
                        }
                    }
                    else if (algo == clk)
                    {
                        while(replace_p == NULL)
                        {
                            //check clock hand
                            if(!main_memory[clock_hand]->used )
                            {
                                //select this one
                                replace_p=main_memory[clock_hand];
                            }
                            else
                            {
                                //set used bit to true
                                main_memory[clock_hand]->used = true;
                                
                                //increment hand
                                if(clock_hand >= (main_memory.size()-1))
                                {
                                    clock_hand = 0;
                                }
                                else
                                {
                                    clock_hand++;
                                }
                                
                            }
                        }
                        
                    }
                    else if (algo == fifo)
                    {
                        
                        replace_p = fifo_queue.front();
                    }
                    
                    pagefault(replace_p, page_p);
                }
                else
                {
                    //fill up remaining memory
                    
                    //set tracking bits
                    page_p->in_memory = true;
                    page_p->memory_location = main_memory.size();
                    
                    if(algo == lru)
                    {
                        page_p->access_t = program_clock;
                        program_clock++;
                    }
                    else if (algo == clk)
                    {
                        page_p->used = true;
                    }
                    else if (algo == fifo)
                    {
                        fifo_queue.push(page_p);
                    }
                    
                    //push into main memory
                    main_memory.push_back(page_p);
                    
                    if(main_memory.size() == (MEMORY_SIZE / page_size))
                    {
                         memory_full = true;
                    }
                }
                //increment page for prepaging
                page_p = &program_p->pagefile[location + 1];
            }
        }
    } 
    
    fclose (programlist_fp);
    fclose (programtrace_fp);

}






