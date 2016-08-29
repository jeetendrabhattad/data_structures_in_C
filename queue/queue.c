#include "queue.h"
#include <stdlib.h>

_Bool InitQueue( Queue* const qu, int size)
{
	if(NULL == qu)
		return 0;
	qu->front = -1;
	qu->rear = -1;

#ifdef CIRCULAR
	qu->front = 0;
	qu->rear = 0;
#endif

	qu->size = size;
	qu->Q = (int*)malloc(sizeof(int)*size);

	if( NULL == qu->Q )
		exit(-1);
	return 1;
}

void DeInitQueue( Queue* const qu )
{
	if( qu )
	{
		if( qu->Q )
        {
			free(qu->Q);
            qu->Q = NULL;
        }
	}
}

void EnQueue(Queue* const qu, const int data)
{
#ifdef CIRCULAR
	qu->rear = (qu->rear+1)%(qu->size);
#else
	qu->rear++;
#endif
	qu->Q[qu->rear] = data;
}

int DeQueue(Queue* const qu)
{
#ifdef CIRCULAR
	qu->front = (qu->front+1)%(qu->size);
#else
	qu->front++;
#endif
	return qu->Q[qu->front];
}

_Bool IsQueueFull(Queue* const qu) 
{
	if(NULL != qu)
	{
#ifdef CIRCULAR
		return (qu->rear + 1)%(qu->size) == qu->front;
#else
		return qu->rear == (qu->size-1);
#endif
	}
	return 0;
}

_Bool IsQueueEmpty( Queue* const qu) 
{
	if(NULL != qu)
	{
		return qu->rear == qu->front;
	}
	return 0;
}

