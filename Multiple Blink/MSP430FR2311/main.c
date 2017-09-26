#include <msp430.h>

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer

    P1OUT &= ~BIT0;                         // Clear P1.0
    P1DIR |= BIT0;                          // Set P1.0 to output direction
    P2OUT &= ~BIT0;                         // Clear P2.0
    P2DIR |= BIT0;                          // Set P2.0 to output direction

    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings

    while(1)
    {
        P1OUT ^= BIT0;                      // Toggle P1.0 using exclusive-OR
		P2OUT ^= BIT0;						// Toggle P2.0 using exclusive OR
        __delay_cycles(400000);             // Delay to allow LED blink to be seen

    }
}
