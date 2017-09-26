#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
    P1OUT &= ~0b0011;                         // &=~ performs a bit clear on P1.0 and P1.1[BIT0 is defined in header file as 0x0001]
    P1DIR |= 0b0011;                          // Set P1.0 and P1.1 to output direction [1b'0 is input and 1'b1=output]


    PM5CTL0 &= ~LOCKLPM5; //turns off high-impedance input mode as described in Digital I/O chapter of Family User Guide

    while(1)
    {
        P1OUT ^= 0b0011;        // Exclusive or used to toggle LEDs on/off (same as P1OUT ^= 0x01)
        __delay_cycles(100000); // Delay to allow LEDs to blink
    }

	return 0;
}
