# James Anderson 
# My first make file
# Some reminders:
# Commands start with TAB not spaces
# $@ is the name of the target
# $< is the first dependancy
# $? is all dependancys more recent than the target

CXX = g++

all: udpcli01   udpserv01

udpcli01: udpcli01.c unp.h dg_cli.c
	$(CXX) $< -o $@ 

udpserv01: udpserv01.c unp.h dg_echo.c
	$(CXX) $< -o $@ 

clean:
	rm -f udpcli01 udpserv01

