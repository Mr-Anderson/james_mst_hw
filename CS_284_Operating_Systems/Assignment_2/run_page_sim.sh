#!/bin/sh
# Author: James Anderson 
# Class: CS284
# Assignment: 2 run script

echo 'running page_sim'
valgrind --leak-check=yes ./page_sim programlist.txt programtrace.txt 2 fifo d
