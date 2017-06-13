/*
 * led.c
 *
 * Created: 23.05.2017 23:28:59
 *  Author: Ivan Kireev
 */ 

#include <avr/io.h>

#include "led.h"
#include "mq.h"
#include "general.h"


void led_init(void)
{
	/*All the 8 pins of PortB are declared output (LED array is connected)*/
	DDRB=0xFF;
	
	/*All the 8 LEDs of LED array are Off*/
	PORTB=0x00;	
}

void led_B0_on(void)
{
	PORTB |= 0x01;
}

void led_B0_off(void)
{
	PORTB &= !(0x01);	
}

void led_status_blink_cb(void)
{
	led_B0_off();
	
	t_mq_time time_off;
	switch(general_status)
	{
		case GSTATUS_STANDBY:
		time_off = (20<<5) - 3;
		break;
		case GSTATUS_PUMP_IN_WORK:
		time_off = 3;
		break;
		case GSTATUS_INITIZLIZATION:
		time_off = 1<<5;
		break;
		default:
		time_off = 20;
	};
	
	mq_push(time_off, led_status_blink_start); //19.9 sec
}

void led_status_blink_start(void)
{
	led_B0_on();
	
	t_mq_time time_on;
	switch(general_status)
	{
		case GSTATUS_STANDBY:
		case GSTATUS_PUMP_IN_WORK:
			time_on = 3;
			break;
		case GSTATUS_INITIZLIZATION:
			time_on = 1<<5;
			break;
		default:
			time_on = 3;
	};
	
	mq_push(time_on, led_status_blink_cb);	//0.1 sec
}



