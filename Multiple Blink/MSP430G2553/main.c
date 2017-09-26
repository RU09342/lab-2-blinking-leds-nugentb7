#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    P1OUT &= ~(BIT0 + BIT6);                         // &=~ performs a bit clear on P1.0 and P1.6[BIT0 is defined in header file as 0x0001]
    P1DIR |= (BIT0 + BIT6);                          // Set P1.0 and P1.6 to output direction [1b'0 is input and 1'b1=output]


    while(1)
    {
        P1OUT ^= (BIT0 + BIT6);        // Exclusive or used to toggle LEDs on/off (same as P1OUT ^= (0b01 | 0b1000000)
        __delay_cycles(100000);        // Delay to allow LEDs blink to be seen
    }

    return 0;
}

