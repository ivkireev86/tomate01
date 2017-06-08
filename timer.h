/*
 * timer.h
 *
 * Created: 04.06.2017 20:18:30
 *  Author: Ivan Kireev
 */ 

#include "mq.h"

#ifndef TIMER_H_
#define TIMER_H_

//Local time
unsigned char t_seconds;	//00-59. BCD
unsigned char t_minutes;	//00-59. BCD
unsigned char t_hours;		//00-23. BCD
unsigned char t_day;		//1-7.   BCD

//Scheduler
t_mq_time     t_sheduler_time;

void timer_init(void);


#endif /* TIMER_H_ */