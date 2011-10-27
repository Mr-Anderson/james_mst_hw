# James Anderson 
# My first make file
# Some reminders:
# Commands start with TAB not spaces
# $@ is the name of the target
# $< is the first dependancy
# $? is all dependancys more recent than the target

CXX = g++

all: client server

client: client.c unp.h myTCP.c myNetwork.c
	$(CXX) $< -o $@ 

server: server.c unp.h myTCP.c myNetwork.c
	$(CXX) $< -o $@ 

clean:
	rm -f client server

