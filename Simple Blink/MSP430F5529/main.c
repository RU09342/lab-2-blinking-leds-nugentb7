#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{

    volatile unsigned int i;				// volatile tells the compiler that i may change at any time

    WDTCTL = WDTPW | WDTHOLD;               // stop watchdog timer

    P1DIR |= BIT0;                          // Set P1.0 to output direction [1b0 is input and 1b1=output]

    while(1)
    {
        P1OUT ^= BIT0;                      // Exclusive or used to toggle LED on/off (same as P1OUT ^= 0x01)

        __delay_cycles(100000);             // Creates delay so the blink is visible
    }


    return 0;
}
