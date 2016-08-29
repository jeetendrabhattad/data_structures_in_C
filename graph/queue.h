#ifndef _QUEUE_H
#define _QUEUE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int *Q;
	int front;
	int rear;	
	int size;
}Queue;

_Bool InitQueue( Queue* const qu, int size);
void DeInitQueue( Queue* const qu );
void EnQueue( Queue* const qu, const int data );
int DeQueue( Queue* const qu );
_Bool IsQueueFull( Queue* const qu );
_Bool IsQueueEmpty( Queue* const qu );
#endif
