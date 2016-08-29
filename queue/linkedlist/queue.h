#ifndef QUEUE_H_
#define QUEUE_H_

struct QueueElement
{
	int data;
	struct QueueElement *next;
};

struct Student{
    int rollNo;
    char Name[10];
    float marks[3];
    char address[20];
};
struct Student sybcs[100];
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
