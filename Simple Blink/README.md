# Simple Blink

## Brendan Nugent

## Compatible Microcontrollers
* MSP430G2553
* MSP430F5529
* MSP430FR2311
* MSP430FR5994
* MSP430FR6989

## Description
This folder contains code, written in C (register-level), to blink an LED with a 50% duty cycle on the MSP430 microcontrollers listed above. The LED is on P1.0 on
each of the development boards. By performing an exclusive or with P1 and BIT0 in an infinite loop, the output on P1.0 is toggled. This turns the LED on and off,
with a delay created to make the blinking visible to the human eye.

Each of the source files contains further documentation, explaining what each line of code does.

While most of the code is the same for each microcontroller, there are some slight differences. For example, while the MSP430FRxxxx family requires the programmer to turn off
high-impedance mode, the MSP430G2553 and MSP430F5529 do not.