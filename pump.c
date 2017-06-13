/*
 * pump.c
 *
 * Created: 25.05.2017 21:54:18
 *  Author: Ivan Kireev
 */ 

#include <avr/io.h>

#include "pump.h"
#include "mq.h"

void pump_init(void)
{
	/*C7 are declared output (pump key connected)*/
	DDRC=0x80;
		
	/*A7 if off by default*/
	PORTC &= !(0x80); //pump off
}

void pump_flud_cb(void)
{
	PORTC &= !(0x80);	//pump off
}

void pump_flud40s(void)
{
	PORTC |= 0x80;  //pump on
	mq_push(40<<5, pump_flud_cb);
}