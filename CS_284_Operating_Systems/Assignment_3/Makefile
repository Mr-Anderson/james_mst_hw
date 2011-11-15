# CS284 - Assignment 3 Makefile
# James Anderson 
# Some reminders:
# Commands start with TAB not spaces
# $@ is the name of the target
# $< is the first dependancy
# $? is all dependancys more recent than the target

CXX = g++

all: client server

client: client.c client.h shared.h
	$(CXX) $< -lpthread -D_REENTRANT -o $@ 
    
server: server.c server.h shared.h
	$(CXX) $< -lpthread -D_REENTRANT -o $@ 

clean:
	rm -f client server

