#include <AT89x52.h>

#define WR_BAR P3_3 
#define ALE P3_0


void SSegDisp(char x); 

void Delay (long x);

void main()
{
	for(;;)
	{
		WR_BAR = 1 ;
		ALE =0 ;

		Delay(100000);

		SSegDisp('H');
		Delay(100000);

		SSegDisp('E');	
		Delay(100000);

		SSegDisp('L');
		Delay(100000);

		SSegDisp('L');
		Delay(100000);

		SSegDisp('O');
		Delay(100000);

		SSegDisp(' ');

	}

}

void Delay (long x)
{
	long i;
	for(i=0;i<x;i++);
}

void SSegDisp(char x)
{
	WR_BAR = 1 ;
	ALE =0 ;
	P2 = 0xAA;
	P0 = 0x55;
	Delay(20000);
	ALE = 1 ;
	Delay(20000);
	ALE = 0 ;
	if(x == 'H')
	{
		P0 = 0x0001001;
	}
	else if(x == 'E')
	{
		P0 = 0x0000110;
	}
	else if(x == 'L')
	{
		P0 = 0x1000111;
	}
	else if(x == 'O')
	{
		P0 = 0x1000000;
	}
	else if(x == ' ')
	{
		P0 = 0x1111111;
	}
	Delay(20000);
	WR_BAR=0;
	Delay(20000);
	WR_BAR=1;
}
