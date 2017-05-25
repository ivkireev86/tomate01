/*
 * tomate01.c
 *
 * Created: 23.05.2017 2:29:30
 * Author : Ivan Kireev
 */ 

#include <avr/io.h>

#define F_CPU 7372800  // 7.3728 MHz
//#define PUMP_PERIOD 60 * 4 //4 hours 
#define PUMP_PERIOD 10 //10 minutes

#include <util/delay.h>

#include "general.h"
#include "led.h"
#include "pump.h"

int main(void)
{
	//initialization
	general_init();
	led_init();
	pump_init();

	//blink 2 times per 1 second on start
	_delay_ms(1000);
	led_on(0);
	_delay_ms(1000);
	led_off(0);
	_delay_ms(1000);
	led_on(0);
	_delay_ms(1000);
	led_off(0);
	
	unsigned short int pump_timer = PUMP_PERIOD-1; 
	
    //main loop
    while (1) 
    {
		if (pump_timer == 0)
		{
			pump_on();
		}
		
		//blink on 0.3 second in minute
		_delay_ms(10000-300);
		led_on(0);
		_delay_ms(300);
		led_off(0);
		
		if (pump_timer == 0)
		{
			pump_off();
			pump_timer = PUMP_PERIOD-1;
		}
		else
		{
			pump_timer--;
		}
    }
}

