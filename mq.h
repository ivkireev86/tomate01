/*
 * mq.h
 *
 * Created: 04.06.2017 21:08:11
 *  Author: Ivan Kireev
 */ 


#ifndef MQ_H_
#define MQ_H_

typedef unsigned char t_mq_time;
typedef void    (*t_mq_task)(void);

void mq_init(void);
void mq_push(t_mq_time, t_mq_task);	//push new message to queue
unsigned char mq_check(void);					//run one task if time is come
unsigned char get_queue_size(void);
unsigned char get_queue_max_len(void);

#endif /* MQ_H_ */
