/*
 * mq.c
 *
 * Created: 04.06.2017 21:16:18
 *  Author: Ivan Kireev
 */ 

#include "mq.h"

#define _MQ_SIZE 16

typedef struct
{
	t_mq_time	due_time;
	t_mq_task	task;
} _msg;
_msg _queue[_MQ_SIZE];

unsigned char _queue_max_len;

void mq_init(void)
{
	for (unsigned char i = 0; i < _MQ_SIZE; i++)
	{
		_queue[i].due_time = 0;
	}
}

void mq_push(t_mq_time time, t_mq_task task)
{
	;
}

unsigned char mq_check(void)
{
	;
}

unsigned char get_queue_size(void)
{
	;
}

unsigned char get_queue_max_len(void)
{
	return _queue_max_len;
}


