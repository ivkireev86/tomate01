/*
 * general.c
 *
 * Created: 23.05.2017 23:23:04
 *  Author: Ivan Kireev
 */ 

#include "general.h"

void general_init(void)
{
	general_status = GSTATUS_INITIZLIZATION;	
}

void general_set_standby_mode(void)
{
	if (general_status == GSTATUS_INITIZLIZATION)
	{
		general_status = GSTATUS_STANDBY;
	}
}
