#ifndef STACK_H_
#define STACK_H_

typedef struct Stack
{
	int data;
	struct Stack *next;
}STACK_T;

void Push(STACK_T **stack, int data);
int Pop(STACK_T **stack);
int Peep(STACK_T *stack);
_Bool IsEmpty(STACK_T *stack);
void FreeAll(STACK_T *stack);

#endif
