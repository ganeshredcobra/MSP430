/*button_press.c
ganeshredcobra@gmail.com
GPL
on board button S2 is used in this example...
connect P1.3 to vcc through a resistor...
*/
#include <msp430g2553.h>

volatile unsigned int i;//to prevent optimization
void main(void)
{
	WDTCTL=WDTPW+WDTHOLD;
 	P1DIR|=0X01;//set all bits in P1 to input except BIT0
	for(;;)
	{
	  P1OUT=0x01;//BIT 0 LED ON
	  while((P1IN & BIT3)==0)//while pusing S1
		P1OUT=0X00;//LED OFF		 
	}
}

