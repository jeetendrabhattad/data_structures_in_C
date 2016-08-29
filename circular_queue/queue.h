#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

struct Queue
{
	int QUEUE[MAX_SIZE];
	int front;
	int rear;	
};

short InitQ(struct Queue* queue);
void AddQ(struct Queue* queue, const int data);
int DelQ(struct Queue* queue);
short isFull(struct Queue* queue);
short isEmpty(struct Queue* queue);

