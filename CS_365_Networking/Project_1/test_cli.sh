#!/bin/sh
# Author: James Anderson , Adam Honse <amhb59>
# Class: CS284
# Assignment: 2 run script

make
./client 131.151.154.27  9877 testfile.pdf recv.pdf

#valgrind --leak-check=yes 
