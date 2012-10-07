/*button_press.c
ganeshredcobra@gmail.com
GPL
An external button connected to P1.4 is used in this example...
connect P1.43 to vcc through a resistor...
*/
#include <msp430g2553.h>

volatile unsigned int i;//to prevent optimization
void main(void)
{
	WDTCTL=WDTPW+WDTHOLD;
 	P1DIR|=0X01;//set all bits in P1 to input except BIT0
	for(;;)
	{
	  if((P1IN & BIT4)==0)//while pusing S1
		P1OUT=0X01;//LED ON
	  else
		P1OUT=0x00;//LED OFF		 
	}
}

