/*
 * general.h
 *
 * Created: 23.05.2017 22:38:10
 *  Author: Ivan Kireev
 */ 


#ifndef GENERAL_H_
#define GENERAL_H_

unsigned char general_status;
#define GSTATUS_INITIZLIZATION	0
#define GSTATUS_STANDBY			1
#define GSTATUS_PUMP_IN_WORK	2


void general_init(void);

void general_set_standby_mode(void);




#endif /* GENERAL_H_ */