//test mynetwork

#include "myNetwork.h"
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	myNetwork net;
	
	net.init(1337);

	char my_ip[INET_ADDRSTRLEN];

	net.getMyIP(my_ip);
	printf("IP: %s\n", my_ip);
}
