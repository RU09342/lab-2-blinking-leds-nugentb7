#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{


    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    P1REN |= BIT3; //enable resistor

    P1DIR &= ~BIT3; //set P1.3 as input
    P1OUT |= BIT3;  //set as pullup resistor
    P1DIR |= BIT0;  //set P1.0 as output

    P1OUT &= ~BIT0; // clear P1.0

    static int value=0;
    while(1)
    {
        value = P1IN & BIT3;
        if (value==0) // if button is pressed turn on
        {
            P1OUT |= BIT0;
        }

        else
        {
            P1OUT  &= ~BIT0;
        }
    }
}
