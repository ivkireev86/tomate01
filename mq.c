/*
 * mq.c
 *
 * Created: 04.06.2017 21:16:18
 *  Author: Ivan Kireev
 */ 


#define MQ_SIZE 16

struct mq_msg
{
	mq_time_t     due_time;
	mq_task       task;
};

mq_msg mq_queue[MQ_SIZE]

void mq_init(void)
{
	for (unsigned char i = 0; i < MQ_SIZE; i++)
	{
		mq_queue[i].due_time = 0;
	}
}