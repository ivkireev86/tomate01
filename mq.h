/*
 * mq.h
 *
 * Created: 04.06.2017 21:08:11
 *  Author: Ivan Kireev
 */ 


#ifndef MQ_H_
#define MQ_H_

typedef unsigned short t_mq_time;	//should be unsigned, 0 means NA
typedef void    (*t_mq_task)(void);

void mq_init(void);
void mq_push(t_mq_time p_offset, t_mq_task p_task);	//push new message to queue
unsigned char mq_check(void);						//run one task if time is come. return 1 if task was done, 0 if no task in queue
unsigned char get_queue_size(void);
unsigned char get_queue_max_len(void);

#endif /* MQ_H_ */
