#!/bin/sh
# Author: James Anderson 
# Class: CS284
# Assignment: 2 run script

make
./client 127.0.0.1  9877 testfile.pdf recv.pdf

#valgrind --leak-check=yes 
