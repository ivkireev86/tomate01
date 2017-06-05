/*
 * timer.h
 *
 * Created: 04.06.2017 20:18:30
 *  Author: Ivan Kireev
 */ 


#ifndef TIMER_H_
#define TIMER_H_

//Tick time
unsigned char t_tick;		//00-31. non BCD
//Local time
unsigned char t_seconds;	//00-59. BCD
unsigned char t_minutes;	//00-59. BCD
unsigned char t_hours;		//00-23. BCD
unsigned char t_day;		//1-7.   BCD

void timer_init(void);


#endif /* TIMER_H_ */