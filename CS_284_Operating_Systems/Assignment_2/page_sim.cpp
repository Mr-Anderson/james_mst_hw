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
void pagefault(Page *remove, Page *load)
{
    main_memory[remove->memory_location] = load;

    pages_in_mem++;
    remove->in_memory = false;
    load->in_memory = true;
    pages_in_mem--;

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
    
    //cout<< "argv[6]:" << argv[4] << endl;
    
    //get mode
    if(string(argv[5]) == "p" || string(argv[5]) == "P") mode = prepaging;
    else if(string(argv[5]) == "d" || string(argv[5]) == "D") mode = demandpaging;
    else perror ("Cannot determine paging mode selection");
    
    cout<<"mode:"<<mode<<endl;
    
    
    //get algorithum
    if(string(argv[4]) == "lru" || string(argv[4]) == "LRU") algo = lru;
    else if(string(argv[4]) == "fifo" || string(argv[4]) == "FIFO") algo = fifo;
    else if(string(argv[4]) == "clock" || string(argv[4]) == "CLOCK") algo = clk;
    else perror ("Cannot determine paging algorithum selection");
    
    cout<< "algo:" << algo <<endl;
    
    //read in program list
    unsigned long unq_name = 0;
    for(;;)
    {
        int name, size, pages;
        Program program;
        
        fscanf(programlist_fp, "%d %d", &name, &size);
        if(feof(programlist_fp)) break;
        
        //cout<< "adding program "<< name << endl;
        
        pages = size/page_size;
        
        if (size%page_size != 0)
        {
            pages++;
        }
        
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
    
    pages_in_mem = 0;
    
    //alocate default memory load
    int default_load = MEMORY_SIZE/(page_size * programs.size());
    //cout<<"default load:" << default_load<<endl;
    //cout<< "programs:" <<programs.size()<<endl; 
    for(int i=0; i < programs.size(); i++)
    {
        for(int j=0; j < default_load; j++)
        {
            Page *page_p = &programs[i].pagefile[j];
            
            pages_in_mem++;
            
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
    memory_full = true;
    while((main_memory.size() * page_size) < MEMORY_SIZE)
    {
        memory_full = false;
        Page *page_p = NULL;
        main_memory.push_back(page_p);
    }
    
    
    //initialize page fault counter
    page_faults =0;
    clock_hand = 0;
    
    //read in programtrace and simulate 
    for(;;)
    {
        int program, location, pages;
        Program *program_p;
        Page *page_p;
        
        //cout<<"running program trace"<< endl;
        
        //read 
        fscanf(programtrace_fp, "%d %d", &program, &location);
        //break if at end of file
        if(feof(programtrace_fp)) break;
        
        //calculate page location
        location = (location/page_size) ;
        
        //find program
        program_p = &programs[program];
        
        if (location == program_p->pagefile.size())
        {
            cout<<"aaarg trying to acces wrong page"<<endl;
        }
        
        //cout<<"seting to program "<<program<< "and page" << location << "/" << program_p->pagefile.size()<< endl;
        //find page
        page_p = &program_p->pagefile[location];
        
        // check to see if page is in memory
        if(page_p->in_memory )
        {
            //cout<<"in memory"<< endl;
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
            //cout<<"page fault"<< endl;
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
                //cout<<"adding page"<< endl;
                
                 // handel page fault
                if(memory_full)
                {
                    //cout<<"memory full"<< endl;
                    //look for page to replace
                    Page *replace_p = NULL;
                    if(algo == lru)
                    {
                        //cout<<"running lru"<< endl;
                        // set lowest time to a memory time
                        unsigned long lowest_time = main_memory[0]->access_t;
                        replace_p = main_memory[0];
                        //check all memory for lowest time
                        for(int i = 0; i < main_memory.size(); i++)
                        {
                            //cout<<"main memory"<< i << "/"<< main_memory.size() << endl;
                            if(main_memory[i]->access_t < lowest_time)
                            {
                                lowest_time = main_memory[i]->access_t;
                                replace_p = main_memory[i];
                            }
                        }
                    }
                    else if (algo == clk)
                    {
                        //cout<<"running clock"<< endl;
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
                                main_memory[clock_hand]->used = false;
                                
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
                        //cout<<"running fifo"<< endl;
                        replace_p = fifo_queue.front();
                    }
                    
                    //cout<<"replacing page"<< endl;
                    pagefault(replace_p, page_p);
                }
                else
                {
                    //fill up remaining memory
                    //cout<<"fill remaining"<< endl;
                    
                    pages_in_mem++;
                    
                    //set tracking bits
                    page_p->in_memory = true;
                    page_p->memory_location = main_memory.size();
                    
                    if(algo == lru)
                    {
                        //cout<<"lru"<< endl;
                        page_p->access_t = program_clock;
                        program_clock++;
                    }
                    else if (algo == clk)
                    {
                        //cout<<"clk"<< endl;
                        page_p->used = true;
                    }
                    else if (algo == fifo)
                    {
                        //cout<<"fifo"<< endl;
                        fifo_queue.push(page_p);
                    }
                    
                    //cout<<"push onto memeory"<< endl;
                    //push into main memory
                    for(int k = 0; k < main_memory.size(); k++)
                    {
                        if(main_memory[k] == NULL )
                        {
                            main_memory[k] = page_p;
                            break;
                        }
                    }
                    
                    //check to see if memory is full
                    memory_full = true;
                    for(int k = 0; k < main_memory.size(); k++)
                    {
                        if(main_memory[k] == NULL )
                        {
                             memory_full = false;
                        }
                    }
                }
                //increment page for prepaging
                page_p = &program_p->pagefile[location + 1];
            }
        }
    } 
    
    cout<< "pages in mem:" <<pages_in_mem<<endl; 
    cout<< "memory size:" << main_memory.size()<<endl;
    cout<< "page faults:" <<page_faults<<endl; 
    
    fclose (programlist_fp);
    fclose (programtrace_fp);

}






