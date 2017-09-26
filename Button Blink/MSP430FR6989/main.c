#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{


    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    PM5CTL0 &= ~LOCKLPM5;

    P1REN |= BIT1; //enable resistor on button

    P1DIR &= ~BIT1; //set P1.1 as input
    P1OUT |= BIT1;  //set as pullup resistor on button
    P1DIR |= BIT0;  //set P1.0 as output

    P1OUT &= ~BIT0; //clear P1.0

    static int value=0;
    while(1)
    {
        value = P1IN & BIT1;
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
