CXX = g++

all: udpcli01   udpserv01

udpcli01: udpcli01.c
    # Commands start with TAB not spaces

	$(CXX) $(LDFLAGS) -o $@ $^

udpserv01: udpserv01.c
	$(CXX) $(LDFLAGS) -o $@ $^

clean:
	rm -f udpcli01 udpserv01

