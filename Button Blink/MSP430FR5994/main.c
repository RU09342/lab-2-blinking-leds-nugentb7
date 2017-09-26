#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    PM5CTL0 &= ~LOCKLPM5;

    P1DIR = BIT0; //set P1.0 as output
    P1OUT &= ~BIT0;  //clear P1.0 bit

    P5IN &= ~BIT6;  //reset P5.6
    P5REN |= BIT6;  //enable pullup
    P5OUT |= BIT6;  //select pull[up]/down
    P5DIR |= ~BIT6; //sets P5.6 as input


    while(1)
    {
		if (P5IN & BIT6) // if button is not pressed
        {
            P1OUT = 0x0000;
        }

        else  // if button is pressed
        {
            P1OUT = BIT0;
        }
    }
}




