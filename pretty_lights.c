/*hello-world.c
ganeshredcobra@gmail.com
GPL
*/
#include <msp430g2553.h>

//volatile unsigned int i;//to prevent optimization
void main(void)
{
	
	WDTCTL=WDTPW+WDTHOLD;
 	P1DIR=BIT0|BIT6;
	int buttonpushed=0;
	int blinkmode=0;
	int blinkmask=BIT0;
	P1OUT &=~BIT6;
	for(;;)
	{
		volatile int i;
		for(i=0;i<20000;i++);
		if((P1IN & BIT3)==0)
	  	{
			if(!buttonpushed)
				{
					buttonpushed=1;
					blinkmode=(blinkmode+1)%4;
					if(blinkmode==0)
						{
							blinkmask=BIT0;
							P1OUT&=~BIT6;						
						}
					else if(blinkmode==1)
						{
							blinkmask=BIT6;
							P1OUT&=~BIT0;
						}
					else if(blinkmode==2)
						{
							blinkmask=BIT0|BIT6;
							P1OUT |= BIT0|BIT6;						
						}
					else
						{
							blinkmask=BIT0|BIT6;
							P1OUT &=~BIT0;	
							P1OUT |= BIT6;	
						}
				}	

	
		}
		else
		{
			buttonpushed=0;
		}
		P1OUT ^= blinkmask;
	}

}
