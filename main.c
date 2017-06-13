/*
 * tomate01.c
 *
 * Created: 23.05.2017 2:29:30
 * Author : Ivan Kireev
 */ 

#include "config.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <util/delay.h>

#include "general.h"
#include "mq.h"
#include "led.h"
#include "pump.h"
#include "timer.h"

int main(void)
{
	//initialization
	general_init();
	mq_init();
	led_init();
	pump_init();
	timer_init();
	
	sei();	//interrupt enable
	set_sleep_mode(SLEEP_MODE_IDLE);
	sleep_enable();

	mq_push(1<<5, led_status_blink_start);
	mq_push(4<<5, general_set_standby_mode);	
	mq_push(30<<5, pump_flud40s);
	
	while (1)
	{
		while(mq_check()) {
			;
		}

		sleep_cpu();
	}
}
