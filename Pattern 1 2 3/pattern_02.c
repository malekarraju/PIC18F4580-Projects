#include<p18f4580.h>

void Delay(int);

void main()
{
	TRISC = 0x00;
	
	while(1)
	{
		PORTC = 0x03;
		Delay(100);
		PORTC = 0x00;
		Delay(100);

		PORTC = 0x0C;
		Delay(100);
		PORTC = 0x00;
		Delay(100);

		PORTC = 0x30;
		Delay(100);
		PORTC = 0x00;
		Delay(100);

		PORTC = 0xC0;
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
		LED.RC1 = ON;
		Delay(100);
		LED.RC0 = OFF;
		LED.RC1 = OFF;
		Delay(100);

		LED.RC2 = ON;
		LED.RC3 = ON;
		Delay(100);
		LED.RC2 = OFF;
		LED.RC3 = OFF;
		Delay(100);

		LED.RC4 = ON;
		LED.RC5 = ON;
		Delay(100);
		LED.RC4 = OFF;
		LED.RC5 = OFF;
		Delay(100);

		LED.RC6 = ON;
		LED.RC7 = ON;
		Delay(100);
		LED.RC6 = OFF;
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