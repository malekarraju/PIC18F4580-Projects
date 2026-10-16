#include<p18f4580.h>

void Delay(int);

void main()
{
	TRISC = 0x00;
	
	while(1)
	{
		PORTC = 0x01;
		Delay(100);
		PORTC = 0x00;
		Delay(100);

		PORTC = 0x02;
		Delay(100);
		PORTC = 0x00;
		Delay(100);

		PORTC = 0x04;
		Delay(100);
		PORTC = 0x00;
		Delay(100);

		PORTC = 0x08;
		Delay(100);
		PORTC = 0x00;
		Delay(100);

		PORTC = 0x10;
		Delay(100);
		PORTC = 0x00;
		Delay(100);

		PORTC = 0x20;
		Delay(100);
		PORTC = 0x00;
		Delay(100);

		PORTC = 0x40;
		Delay(100);
		PORTC = 0x00;
		Delay(100);

		PORTC = 0x80;
		Delay(100);
		PORTC = 0x00;
		Delay(100);
	}
}

void Delay(int a)
{
	int i, j;
	for(i=0; i<a; i++)
		for(j=0; j<a; j++);
}


/*
#include<p18f4580.h>

#define LED PORTCbits 
#define ON 1
#define OFF 0

void Delay(int);

void main()
{
	TRISC = 0x00;
	
	while(1)
	{
		LED.RC0 = ON;
		Delay(100);
		LED.RC0 = OFF;
		Delay(100);

		LED.RC1 = ON;
		Delay(100);
		LED.RC1 = OFF;
		Delay(100);

		LED.RC2 = ON;
		Delay(100);
		LED.RC2 = OFF;
		Delay(100);

		LED.RC3 = ON;
		Delay(100);
		LED.RC3 = OFF;
		Delay(100);

		LED.RC4 = ON;
		Delay(100);
		LED.RC4 = OFF;
		Delay(100);

		LED.RC5 = ON;
		Delay(100);
		LED.RC5 = OFF;
		Delay(100);

		LED.RC6 = ON;
		Delay(100);
		LED.RC6 = OFF;
		Delay(100);

		LED.RC7 = ON;
		Delay(100);
		LED.RC7 = OFF;
		Delay(100);
	}
}

void Delay(int a)
{
	int i, j;
	for(i=0; i<a; i++)
		for(j=0; j<a; j++);
}	
*/ 

