#include "queue.h"
#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#include "assert.h"

void Enqueue(QUEUE_T *queue, TREENODE_T* data){
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
		queue->rear = ele;
		queue->front = ele;
#ifdef DEBUG
		printf("front=%p rear=%p\n", queue->front, queue->rear);
#endif
	}
	else
	{
		queue->rear->next = ele;
		queue->rear = ele;
#ifdef DEBUG
		printf("front=%p rear=%p\n", queue->front, queue->rear);
#endif
	}
}

void Display(QUEUE_T *queue)
{
	struct QueueElement *head = queue->front;
	while(head)
	{
		printf("%p\n", head->data);
		head = head->next;
	}
}

TREENODE_T* Dequeue(QUEUE_T *queue){
	assert(NULL != queue);
	if(queue->front)
	{
		struct QueueElement *del = queue->front;
		TREENODE_T *data = del->data;
		queue->front = queue->front->next;
		if(NULL == queue->front)
			queue->rear = NULL;
		free(del);
		return data;
	}
	return NULL;
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
	queue->front = NULL;
	queue->rear = NULL;
}
