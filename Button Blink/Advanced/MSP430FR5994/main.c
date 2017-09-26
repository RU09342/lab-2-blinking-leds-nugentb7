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

    int buttonState = 0;
    int lastButtonState = 0;
    int count = 0;
    while(1)
    {
        if (P5IN & BIT6) //if button is not pressed
        {
            buttonState = 0;
        }

        else //if button is pressed
        {
            buttonState = 1;
        }


        if ((buttonState != lastButtonState) && (buttonState == 1))
        {
            if (count == 3) //reset count to loop from fast to off
            {
                count = 0;
            }

            else  // increment count
            {
            count = count +1;
            }
        }

        if (count == 0) //chose output and delay
        {
            P1OUT = 0;
        }

        else if (count == 1)  //chose output and delay
        {
            __delay_cycles(100000);
            P1OUT ^= BIT0;
        }

        else if (count == 2) //chose output and delay
        {
            __delay_cycles(75000);
            P1OUT ^= BIT0;
        }

        else if (count == 3) //chose output and delay
        {
            __delay_cycles(50000);
            P1OUT ^= BIT0;
        }


        lastButtonState = buttonState; //save end buttonstate to check for edge on next loop around
    }
}


