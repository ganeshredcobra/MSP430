#include <msp430x24x.h>
void main(void) 
{
    volatile int i;
    WDTCTL = WDTPW + WDTHOLD;
    P1DIR |= BIT0 + BIT6;
    for (;;)
    {
       P1OUT ^=BIT6 + BIT0;
       for (i = 0; i < 0x6000; i++);
     }
}
