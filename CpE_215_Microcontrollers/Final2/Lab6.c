#include <at89x52.h>
#include <intrins.h>
#include <stdio.h>

#define DATA P0
#define RW P1_0
#define EN P1_1
#define RS P1_2
#define ON P1_3
#define BLON P1_4
#define dbg_led P1_7


void initialize();
void clear_display();
void set_entry();
void function_set();
void display_on();
void next_line();
void writeInstruction(char dat);
void writeData(char dat);
void Delay(long x);


void main()
{
	initialize();

	writeData(0x4A); //J
	writeData(0x61); //a
	writeData(0x6D); //m
	writeData(0x65); //e
	writeData(0x73); //s
	
	next_line();
	
	writeData(0x41); //A
	writeData(0x6E); //n
	writeData(0x64); //d
	writeData(0x65); //e
	writeData(0x72); //r	
	writeData(0x73); //s
	writeData(0x6F); //o
	writeData(0x6E); //n

	while(1)
	{
		writeInstruction(0x1C);
		writeInstruction(0x1C);
		writeInstruction(0x1C);
		writeInstruction(0x18);
		writeInstruction(0x18);
		writeInstruction(0x18);
	}
}

void initialize()
{
	ON = 1;
	BLON = 0;
	clear_display();
	set_entry();
	function_set();
	display_on();
	
}

void clear_display()
{
	writeInstruction(0x01);
}

void set_entry()
{
	writeInstruction(0x06);
}

void function_set()
{
	writeInstruction(0x38);
}

void display_on()
{
	writeInstruction(0x0E);
}

void next_line()
{
	writeInstruction(0xC0);
}

void writeInstruction(char dat)
{
	RS = 0;
	RW = 0;
	EN = 1;
	Delay(20000);
	DATA = dat;
	Delay(20000);
	EN = 0;
}

void writeData(char dat)
{
	RS = 1;
	RW = 0;
	EN = 1;
	Delay(20000);
	DATA = dat;
	Delay(20000);
	EN = 0;
}


void Delay (long x)
{
	long i;
	for(i=0;i<x;i++);
}
