#include "queue.h"
#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#include "assert.h"

void Enqueue(QUEUE_T *queue, int data){
	assert(NULL != queue);
	struct QueueElement *ele = (struct QueueElement*)malloc(sizeof(struct QueueElement));
	if(NULL == ele)
	{
		printf("Failed to allocate memory for new queue-element. Queue is full\n");
		return;
	}
	ele->data = data;
	ele->next = NULL;

	if(NULL == queue->rear)
	{
		printf("Adding %d\n", ele->data);
		queue->rear = ele;
		queue->front = ele;
		printf("front=%p rear=%p\n", queue->front, queue->rear);
	}
	else
	{
		queue->rear->next = ele;
		queue->rear = ele;
		printf("front=%p rear=%p\n", queue->front, queue->rear);
	}
}

int Dequeue(QUEUE_T *queue){
	assert(NULL != queue);
	if(queue->front)
	{
		struct QueueElement *del = queue->front;
		int data = del->data;
		queue->front = queue->front->next;
		if(NULL == queue->front)
			queue->rear = NULL;
		free(del);
		return data;
	}
	return -1;
}

_Bool IsEmpty(QUEUE_T *queue){
	assert(NULL != queue);
	return queue->rear == NULL && queue->front == NULL;
}

void FreeAll(QUEUE_T *queue){
	if(queue)
	{
		while(queue->front)
			Dequeue(queue);
	}
}
