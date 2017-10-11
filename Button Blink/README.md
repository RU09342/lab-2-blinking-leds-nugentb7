# Button Blink

## Brendan Nugent

# Compatible Microcontrollers
* MSP430G2553
* MSP430F5529
* MSP430FR2311
* MSP430FR5994
* MSP430FR6989

## Description
While in Simple Blink and Multiple Blink, an internal input was generated to toggle the LEDs, in Button Blink, the on-board button is configured and used as a switch. To turn the LED on,
the button must be pressed and, when it is released, the LED will turn back off. To properly configure the button as a switch, the button uses a pull-up resistor. This means that, when 
the button is not pressed, the input will be read as a high state.

To further this exercise, there is a program under the 'Advanced' folder which allows a user to control the speed of the LED blinking through the button.
One button press will turn the LED on to 'slow'. A second button press will turn the LED to 'medium', and another to 'fast'. After this, the speed will loop back to 'off'.
Further documentation exists in the source file.

While most of the code is the same for each microcontroller, there are some slight differences. For example, while the MSP430FRxxxx family requires the programmer to turn off
high-impedance mode, the MSP430G2553 and MSP430F5529 do not. Additionally, the pins for the LEDs, as well as for the buttons, vary between each board. This is accounted for in the code, using the correct pins
for each microcontroller.

## Extra Tasks
Advanced Button Blink (Speed control)