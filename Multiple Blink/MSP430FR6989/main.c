#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    P1OUT &= ~0b0001;                         // &=~ performs a bit clear on P1.0[BIT0 is defined in header file as 0x0001]
    P1DIR |= 0b0001;                          // Set P1.0 and P1.1 to output direction [1b'0 is input and 1'b1=output]
    P9OUT &= ~BIT7;							  // bit clear on P9.7
    P9DIR |= BIT7;							  // set P9.7 to output direction

    PM5CTL0 &= ~LOCKLPM5; //turns off high-impedance input mode as described in Digital I/O chapter of Family User Guide

    while(1)
    {
        P1OUT ^= 0b0001;        // Exclusive or used to toggle LEDs on/off (same as P1OUT ^= 0x01)
        P9OUT ^= BIT7;			
        __delay_cycles(100000);             // Delay to allow LEDs blink to be seen
    }

    return 0;
}
