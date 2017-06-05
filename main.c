/*
 * tomate01.c
 *
 * Created: 23.05.2017 2:29:30
 * Author : Ivan Kireev
 */ 

#include <avr/io.h>

//#define F_CPU 7372800  // 7.3728 MHz
#define F_CPU 32768  // 32.768 KHz
#define PUMP_PERIOD 3 * 60 * 4 //4 hours 
//#define PUMP_PERIOD 3 * 10 //10 minutes

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
	
	unsigned short int pump_timer = 2; 
	
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

