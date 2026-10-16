// 7 Segment Display (CC) Controlled by Switch (Pull-Up Resistor)

#include<p18f4580.h>
#define SWITCH PORTCbits.RC0 

void Delay(int);
void main()
{
	char arr[]={0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
	int count=0;

	TRISCbits.RC0 = 1;
    TRISD = 0x00;

	while(1)
	{
		if(SWITCH == 0)
		{   
				PORTD = arr[count];
				Delay(100);

				if(count==9) count=0;
				else count++;				
		}
	}
}	

void Delay(int a)
{
	int i, j;
  	for(i=0; i<a; i++)
		for(j=0; j<a; j++);
}