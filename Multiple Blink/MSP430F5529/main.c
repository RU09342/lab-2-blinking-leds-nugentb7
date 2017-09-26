#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    volatile unsigned int i; // volatile tells compiler that i may change at any time

    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    P1OUT &= ~BIT0;	 // clear P1.0
    P4OUT &= ~BIT7;	 // clear P4.7
    P1DIR |= BIT0;   // Set P1.0 to output direction [1b'0 is input and 1'b1=output]
    P4DIR |= BIT7;   // Set P4.7 to output direction

    while(1)
    {
        P1OUT ^= BIT0;        // Exclusive or used to toggle LEDs on/off (same as P1OUT ^= 0x01)
		P4OUT ^= BIT7;	 
       __delay_cycles(100000);      // Delay to allow LEDs blinking to be seen
        		

    }

    return 0;
}
