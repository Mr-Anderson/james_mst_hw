#ifndef PAGE_SIM_H
#define PAGE_SIM_H
////////////////////////////////////////////////////////////////////////////////
/// @file page_sim.h
/// @author James Anderson <jra798>
/// @date 10/11/2011
/// @version 1.0
/// @brief header file for page file simulator
////////////////////////////////////////////////////////////////////////////////

#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "math.h"
#include "fstream"
#include "iostream"
#include "time.h"
#include <vector>
#include <queue>

#define MEMORY_SIZE 512

using namespace std;


//global variables for storing args
FILE *programlist_fp;

FILE *programtrace_fp;

int page_size;

enum page_replacement_algo { lru, fifo, clk}; 

page_replacement_algo algo;

enum paging_mode { prepaging, demandpaging}; 

paging_mode mode;

unsigned long  program_clock;

int page_faults;

bool memory_full;

int clock_hand;

struct Page
{
    int name;
    int owner;
    bool in_memory;
    int memory_location;
    
    // for lru and clock
    unsigned long access_t ;
    
    //for clock
    bool used ;
};

struct Program
{
    int name;
    int size;
    int pages;
    vector <Page> pagefile;
};

unsigned long total_pages = 0;


vector <Program> programs;

vector <Page *> main_memory;

queue <Page *> fifo_queue;


#endif
