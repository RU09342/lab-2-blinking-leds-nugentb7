# Multiple Blink


# Compatible Microcontrollers
* MSP430G2553
* MSP430F5529
* MSP430FR2311
* MSP430FR5994
* MSP430FR6989

## Description
This folder contains code, written in C (register-level), to blink two LEDs with a 50% duty cycle on the MSP430 microcontrollers listed above. As in the Simple Blink, one LED is on P1.0 on
each of the development boards. The second LED is on different pins for each MSP430 microcontroller. By performing an exclusive or with P1 and BIT0 in an infinite loop, the output on P1.0 is toggled. This turns the LED on and off,
with a delay created to make the blinking visible to the human eye. The same is done for the second LED. However, each LED is toggled with different frequencies, controlled by a counter variable.

For example, the LED's on the MSP430G2553 are located on P1.0 and P1.6. To toggle both of these pins, the code performs an exclusive or: P1 ^- (BIT0 + BIT6).

Each of the source files contains further documentation, explaining what each line of code does.

While most of the code is the same for each microcontroller, there are some slight differences. For example, while the MSP430FRxxxx family requires the programmer to turn off
high-impedance mode, the MSP430G2553 and MSP430F5529 do not. Additionally, the pins for the LEDs vary between each board. This is accounted for in the code, using the correct pins
for each microcontroller.

