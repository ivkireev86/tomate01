/*
 * pump.c
 *
 * Created: 25.05.2017 21:54:18
 *  Author: Ivan Kireev
 */ 

#include <avr/io.h>

#include "pump.h"

void pump_init(void)
{
	/*C7 are declared output (pump key connected)*/
	DDRC=0x80;
		
	/*A7 if off by default*/
	PORTC &= 0x7F;
}

void pump_on(void)
{
	PORTC |= 0x80;
}

void pump_off(void)
{
	PORTC &= 0x7F;
}