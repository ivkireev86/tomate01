/*
 * timer.c
 *
 * Created: 04.06.2017 20:19:36
 *  Author: Ivan Kireev
 * Description:
 *  - Timer 1 tick each 1/32 seconds
 *  - Timer 1 wake up CPU when interrupt
 *  - Timer 1 manage local time.
 */ 

#include "timer.h"
#include <avr/interrupt.h>

//Tick time
unsigned char _t_tick;		//00-31. non BCD


void timer_init(void)
{
	//Set time and date
	_t_tick		= 0;		//00-31. non BCD
	//Local time
	t_seconds	= 0x00;		//00-59. BCD
	t_minutes	= 0x00;		//00-59. BCD
	t_hours		= 0x00;		//00-23. BCD
	t_day		= 0x01;		//1-7.   BCD
	//Scheduler
	t_sheduler_time = 1;
	
	//Set timer mode and period
	;
	
	//Timer on
	;
}

ISR(TIMER2_OVF_vect)
{
	_t_tick++;
	if (_t_tick >= 32) {
		_t_tick = 0;
		t_seconds++;
		t_sheduler_time++;
	
		if (t_sheduler_time==0) {
			t_sheduler_time++;
		}
		
		if (t_seconds >= 60) {
			t_seconds = 0;
			t_minutes++;
	
			if (t_minutes >= 60) {
				t_minutes =0;
				t_hours++;
	
				if (t_hours >= 24) {
					t_hours = 0;
					t_day++;
	
					if (t_day > 7) {
						t_day = 1;
					}
				}
			}
		}
	}
}