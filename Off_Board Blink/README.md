# Off Board Blink


## Brendan Nugent

## Compatible Microcontroller
* MSP430G2553

## Description
The Off-Board Blink exercise consisted of programming the MSP430G2553 to blink and LED and then removing the integrated circuit from its DIP socket.
By doing so, one can use the chip on a breadboard, supplying it with between 1.8 and 3.6V on the correct pin. This is the recommended supply from the datasheet and, as previously mentioned,
the chip may be damaged without considering the manufacturer recommendations. A pullup resistor must be placed between reset and Vcc.

Moreover, from each of the output pins (P1.0 and P1.6), is a 100 ohm, current limiting resistor. These resistors each go to an LED. With the output pins toggling, just like on
the launchpad, the LEDs will blink. For a visual representation, see the image included in the 'Advanced' folder, along with this README.

 