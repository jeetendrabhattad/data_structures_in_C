#ifndef STACK_H
#define STACK_H

typedef struct
{
	int *STACK;
	int iTop;
	int iSize;
}STACK_T;

// interface of stack
_Bool InitStack(STACK_T* const st, int size);
void DeInitStack(STACK_T* const st);
void Push(STACK_T* const st, int data);
int Pop(STACK_T* const st);
_Bool IsFull(STACK_T* const st);
_Bool IsEmpty(STACK_T* const st);
int Peep(STACK_T* const st);
#endif
