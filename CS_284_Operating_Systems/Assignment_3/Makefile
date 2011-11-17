# CS284 - Assignment 3 Makefile
# James Anderson 
# Some reminders:
# Commands start with TAB not spaces
# $@ is the name of the target
# $< is the first dependancy
# $? is all dependancys more recent than the target

CXX = g++

all: client server

sample: client1 server1

client : client.c shared.h
	$(CXX) $^ -lpthread -D_REENTRANT -o $@ 
    
server : server.c shared.h
	$(CXX) $^ -lpthread -D_REENTRANT -o $@ 

client1 : client1.c 
	$(CXX) $^ -lpthread -D_REENTRANT -lnsl -o $@ 
    
server1 : server1.c 
	$(CXX) $^ -lpthread -D_REENTRANT -lnsl -o $@

clean:
	rm -f client server

