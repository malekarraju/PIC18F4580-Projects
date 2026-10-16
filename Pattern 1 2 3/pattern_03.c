
#include<p18f4580.h>
#define x 100

void Delay(int);

void main()
{
	TRISC = 0x00;
	TRISDbits.RD0 = 0;
	
	while(1)
	{
		PORTC = 0x07;
		Delay(x);

		PORTC = 0x38;
		Delay(x);

		PORTC = 0xc0;
		PORTD = 0x01;
		Delay(x);
		PORTDbits.RD0 = 0;
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

#define LED_D PORTDbits
#define LED PORTCbits 
#define ON 1
#define OFF 0

void Delay(int);

void main()
{
	TRISC = 0x00;
	TRISDbits.RD0 = 0;
	
	while(1)
	{
		LED.RC0 = ON;
		LED.RC1 = ON;
		LED.RC2 = ON;
		Delay(100);
		LED.RC0 = OFF;
		LED.RC1 = OFF;
		LED.RC2 = OFF;
		Delay(100);

		LED.RC3 = ON;
		LED.RC4 = ON;
		LED.RC5 = ON;
		Delay(100);
		LED.RC3 = OFF;
		LED.RC4 = OFF;
		LED.RC5 = OFF;
		Delay(100);

		LED.RC6 = ON;
		LED.RC7 = ON;
		LED_D.RD0 = ON;
		Delay(100);
		LED.RC6 = OFF;
		LED.RC7 = OFF;
		LED_D.RD0 = OFF;
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