#include<p18f4580.h>

void Delay(int);

void main()
{
	char arr[]={0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};
	int i, j;

	TRISC = 0x00;
	TRISD = 0x00;

	while(1)
	{
		for(i=0; i<=9; i++)
		{	
			PORTC = arr[i];
			Delay(100);
			
			for(j=0; j<=9; j++)
			{
				PORTD = arr[j];
				Delay(50);
				if(j==9) PORTD = arr[0];
		    } 
		}
	}
}

void Delay(int a)
{
	int i, j;
	for(i=0; i<a; i++)
		for(j=0; j<a; j++);
}