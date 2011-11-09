# James Anderson , Adam Honse <amhb59>
# My first make file
# Some reminders:
# Commands start with TAB not spaces
# $@ is the name of the target
# $< is the first dependancy
# $? is all dependancys more recent than the target

CXX = g++

all: client server

client: client.c myTCP.cpp myNetwork.c
	$(CXX) $^ -lpthread -fno-stack-protector -fpermissive -w -o $@ 

server: server.c myTCP.cpp myNetwork.c
	$(CXX) $^ -lpthread -fpermissive -fno-stack-protector -w -o $@ 

clean:
	rm -f client server

