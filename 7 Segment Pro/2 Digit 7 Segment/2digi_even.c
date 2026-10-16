#include<p18f4580.h>
#define S1 PORTDbits.RD0
#define S2 PORTDbits.RD1


void Delay(int);
void main()
{
	char arr[]={0x03f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
	
	int i, div, mod;
	TRISC = 0x00;
	TRISDbits.RD0 = 0;
	TRISDbits.RD1 = 0;

	while(1)
	{
		
		for(i=2; i<100; i++)
		{ 
			if(i%2==0)
			{
				S1=0; //enable
				S2=1; //disable
				div=i/10;
				PORTC=arr[div];
				Delay(100);

				S1=1; //enable
				S2=0; //disable
				mod=i%10;
				PORTC=arr[mod];
				Delay(100);
			}
		}
 	}
}

void Delay(int a)
{
	int i,j;
	for(i=0; i<a; i++) 
		for(j=0; j<a; j++);	
}