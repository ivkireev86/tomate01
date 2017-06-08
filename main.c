/*
 * tomate01.c
 *
 * Created: 23.05.2017 2:29:30
 * Author : Ivan Kireev
 */ 

#include "config.h"

#include <avr/io.h>
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

	//blink 2 times per 1 second on start
	_delay_ms(1000);
	led_on(0);
	_delay_ms(1000);
	led_off(0);
	_delay_ms(1000);
	led_on(0);
	_delay_ms(1000);
	led_off(0);
	
	unsigned short int pump_timer = 2; 
	
	while (1)
	{
		//mq_check();
		;
		
		//sleep();
		;
	}
	
    //main loop
    while (1) 
    {
		if (pump_timer <= 1)
		{
			pump_on();
			
			for(unsigned char i = 0; i < 80; i++)
			{
				_delay_ms(500-50);
				led_on(0);
				_delay_ms(50);
				led_off(0);			
			}
			
			pump_off();
			pump_timer = PUMP_PERIOD-1;			
		}
		else
		{
			//blink on 0.1 second in 20 sec
			_delay_ms(20000-100);
			led_on(0);
			_delay_ms(100);
			led_off(0);
				
			pump_timer--;
		}
    }
}

