/*
 * mq.h
 *
 * Created: 04.06.2017 21:08:11
 *  Author: Ivan Kireev
 */ 


#ifndef MQ_H_
#define MQ_H_

#define mq_time_t unsigned char
void    *mq_task(void);

void mq_init(void);
void mq_push(mq_time_t, mq_task);	//push new message to queue
char mq_check();					//run one task if time is come
char get_queue_size();
char get_queue_max_len();

#endif /* MQ_H_ */
