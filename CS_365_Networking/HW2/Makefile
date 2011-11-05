#James Anderson
#CS365
#HW2
#Makefile

CXX = g++

all: udpcli01   udpserv01

udpcli01: udpcli01.c
    # Commands start with TAB not spaces

	$(CXX) $(LDFLAGS) -o $@ $^
	
udpcli.c : dg_cli.c

udpserv01: udpserv01.c 
	$(CXX) $(LDFLAGS) -o $@ $^

udpserv01.c : dg_cli.c

clean:
	rm -f udpcli01 udpserv01

