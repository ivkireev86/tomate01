/*
 * mq.c
 *
 * Created: 04.06.2017 21:16:18
 *  Author: Ivan Kireev
 
 Scheduler logic.
execution:
----------------  ----------------  ----------------  ----------------  
_s______________  __s_____________  ___s____________  ____s___________
___d____________  ___d____________  ___D____________  ___d____________ 
-wait 2 sec-----  -wait 1 sec-----  -execute now----  -wait 14 sec----

planing:
----------------  ----------------  ----------------  ----------------  ----------------
__s_____________  _____________s__  _s______________  _____________s__  ___s____________
_offset 4_______  _offset 4_______  __offset 12_____  _offset 12______  _offset 0_______
______d_________  __d_____________  _______________d  __________d_____  ___d____________ 
 
 */ 

#include "mq.h"
#include "timer.h"

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

void mq_push(t_mq_time p_offset, t_mq_task p_task)
{
	unsigned int f_done = 0;
	unsigned int queue_len = 0;
	
	t_mq_time p_time = t_sheduler_time + p_offset;
	if (p_time < t_sheduler_time) {
		p_time++; //skip 0
	}
	
	for (unsigned char i = 0; i < _MQ_SIZE; i++)
	{
		if (_queue[i].due_time == 0)
		{
			if (f_done == 0)
			{
				_queue[i].task = p_task;
				_queue[i].due_time = p_time;
			
				queue_len++;
				f_done = 1;
			}
		}
		else
		{
			queue_len++;
		}
	}
	
	//Save max queue length
	if (_queue_max_len < queue_len) {
		_queue_max_len = queue_len;
	}
}

unsigned char mq_check(void)
{
	for (unsigned char i = 0; i < _MQ_SIZE; i++)
	{
		if (_queue[i].due_time == t_sheduler_time){
			_queue[i].task();
			_queue[i].due_time = 0;
			
			return 1;
		}
	}
	
	return 0;
}

unsigned char get_queue_size(void)
{
	unsigned int queue_len = 0;
	
	for (unsigned char i = 0; i < _MQ_SIZE; i++)
	{
		if (_queue[i].due_time != 0)
		{
			queue_len++;
		}
	}
	
	return queue_len;
}

unsigned char get_queue_max_len(void)
{
	return _queue_max_len;
}


