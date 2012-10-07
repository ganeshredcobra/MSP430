/*hello-world.c
ganeshredcobra@gmail.com
GPL
*/
#include <msp430g2553.h>

volatile unsigned int i;//to prevent optimization
void main(void)
{
	WDTCTL=WDTPW+WDTHOLD;
 	P1DIR=0X01;//set P1.0 to output
	for(;;)
	{
	  P1OUT ^=0x01;//toggel P1.0 using exclusive OR
	  i=50000;//delay
	  do(i--);
	  while(i!=0);
	}
}

