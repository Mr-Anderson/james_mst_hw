#!/bin/sh
# Author: James Anderson 
# Class: CS284
# Assignment: 2 run script


echo 'running page_sim'

./page_sim programlist.txt programtrace.txt 1 lru  p | awk 'NR < 4'

for page_size in 1 2 4 8 16
do
    for algo in lru fifo clock
    do
        for mode in d p
        do
            ./page_sim programlist.txt programtrace.txt $page_size $algo $mode |awk 'NR==4'
        done
    done
done
#valgrind --leak-check=yes 
