#include <at89x52.h>
#include <intrins.h>
#include <stdio.h>

#define OE P3_0
#define WE P3_1

void writeRAM(char add, char dat);
char readRAM(char add);
void Delay (long x);


void main()
{

	OE = 1;
	WE = 1; 

	P1 = 0x23;
	writeRAM(0x00,0xFF);
	Delay(20000);
	P1 = 0x25;


	writeRAM(0x04,0xAB);
	Delay(20000);
	P1 = 0x25;


	writeRAM(0x0A,0x05);
	Delay(20000);
	P1 = 0x27;


	writeRAM(0x0C,0x7D);
	Delay(20000);
	P1 = 0x29;

	Delay(20000);
	P1 = readRAM(0x00);
	Delay(20000);


	P1 = readRAM(0x04);
	Delay(20000);


	P1 = readRAM(0x0A);
	Delay(20000);


	P1 = readRAM(0x0C);
	Delay(20000);
}


void writeRAM(char add, char dat)
{
	OE = 1;
	WE = 1;

	P2 = add;
	P0 = dat;

	Delay(20000);
	WE = 0;
	Delay(20000);
	WE = 1;

}

char readRAM(char add)
{
	char temp;	

	OE = 1;
	WE = 1;

	P2 = add;

	Delay(20000);
	OE = 0;
	Delay(20000);

	temp = P0 ;
		
	OE = 1;


	return temp;	

}

void Delay (long x)
{
	long i;
	for(i=0;i<x;i++);
}
