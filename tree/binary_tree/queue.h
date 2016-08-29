#ifndef QUEUE_H_
#define QUEUE_H_
#include "binary_tree.h"

struct QueueElement
{
	TREENODE_T *data;
	struct QueueElement *next;
};

typedef struct Queue
{
	struct QueueElement *front;
	struct QueueElement *rear;
}QUEUE_T;

void Enqueue(QUEUE_T *queue, TREENODE_T *data);
TREENODE_T* Dequeue(QUEUE_T *queue);
_Bool IsEmpty(QUEUE_T *queue);
void FreeAll(QUEUE_T *queue);
void Display(QUEUE_T *queue);

#endif
