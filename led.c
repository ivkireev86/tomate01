/*
 * led.c
 *
 * Created: 23.05.2017 23:28:59
 *  Author: ivkir
 */ 

#include <avr/io.h>

#include "led.h"


void led_init(void)
{
	/*All the 8 pins of PortB are declared output (LED array is connected)*/
	DDRB=0xFF;
	
	/*All the 8 LEDs of LED array are Off*/
	PORTB=0x00;	
}

void led_on(unsigned char led_num)
{
	PORTB |= 1 << led_num;
}

void led_off(unsigned char led_num)
{
	PORTB &= !(1 << led_num);	
}


