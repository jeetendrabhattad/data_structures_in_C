#include "queue.h"


short InitQ(struct Queue* queue)
{
	if(NULL == queue)
		return 0;
	queue->front = 0;
	queue->rear = 0;
	memset(queue->QUEUE, -1, MAX_SIZE*sizeof(int));
	return 1;
}

void AddQ(struct Queue* queue, const int data)
{
	queue->QUEUE[ queue->rear = (queue->rear+1)%MAX_SIZE ] = data;		   
}

int DelQ(struct Queue* queue)
{
	return queue->QUEUE[ queue->front = (queue->front+1)%MAX_SIZE ];
}

short isFull(struct Queue* queue) 
{
	if(NULL != queue)
	{
		return (queue->rear+1)%MAX_SIZE == queue->front;
	}
	return 0;
}

short isEmpty(struct Queue* queue) 
{
	if(NULL != queue)
	{
		return queue->front == queue->rear;
	}
	return 0;

}

