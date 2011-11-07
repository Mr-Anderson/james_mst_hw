#!/bin/sh
# Author: James Anderson 
# Class: CS284
# Assignment: 2 run script

make
./client 131.151.89.121  9877 testfile.jpg recv.jpg

#valgrind --leak-check=yes 
