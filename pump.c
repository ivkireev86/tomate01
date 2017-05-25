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
	/*A7 are declared output (pump key connected)*/
	DDRA=0x80;
		
	/*A7 if off by default*/
	PORTA &= 0x7F;
}

void pump_on(void)
{
	PORTA |= 0x80;
}

void pump_off(void)
{
	PORTA &= 0x7F;
}