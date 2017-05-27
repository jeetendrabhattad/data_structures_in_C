#ifndef QUEUE_H_
#define QUEUE_H_

struct QueueElement
{
	int data;
	struct QueueElement *next;
};

typedef struct Queue
{
	struct QueueElement *front;
	struct QueueElement *rear;
}QUEUE_T;

void Enqueue(QUEUE_T *queue, int data);
int Dequeue(QUEUE_T *queue);
_Bool IsEmpty(QUEUE_T *queue);
void FreeAll(QUEUE_T *queue);

#endif
