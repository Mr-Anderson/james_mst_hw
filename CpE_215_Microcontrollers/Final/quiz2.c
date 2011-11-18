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

		SSegDisp('8');
		Delay(100000);

		SSegDisp('5');	
		Delay(100000);

		SSegDisp('4');
		Delay(100000);

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

	if(x == '8')
	{
		P2 = 0xAB;
		P0 = 0x23;
		Delay(20000);
		ALE = 1 ;
		Delay(20000);
		ALE = 0 ;
		P0 = 00000000;
	}
	else if(x == '5')
	{
		P2 = 0xAB;
		P0 = 0x24;
		Delay(20000);
		ALE = 1 ;
		Delay(20000);
		ALE = 0 ;
		P0 = 00010010;
	}
	else if(x == '4')
	{
		P2 = 0xAB;
		P0 = 0x25;
		Delay(20000);
		ALE = 1 ;
		Delay(20000);
		ALE = 0 ;
		P0 = 00011001;
	}
	Delay(20000);
	WR_BAR=0;
	Delay(20000);
	WR_BAR=1;
}
