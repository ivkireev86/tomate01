/*
 * led.h
 *
 * Created: 23.05.2017 23:08:50
 *  Author: Ivan Kireev
 */ 


#ifndef LED_H_
#define LED_H_

void led_init(void);

void led_on(unsigned char led_num);
void led_off(unsigned char led_num);

#endif /* LED_H_ */