#ifndef STACK_H
#define STACK_H

typedef struct
{
	int *STACK;
	int iTop;
	int iSize;
}Stack;

bool InitStack(Stack* const stack, int size);
void DeInitStack(Stack* const stack);
bool Push(Stack* const stack, int data);
int Pop(Stack* const stack);
int IsFull(Stack* const stack);
int IsEmpty(Stack* const stack);
#endif
