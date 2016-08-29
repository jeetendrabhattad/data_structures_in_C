#include "stack.h"
#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#include "assert.h"

void Push(STACK_T **stack, int data){
	STACK_T *element = (STACK_T*)malloc(sizeof(STACK_T));
	if(NULL == element)
	{
		printf("Failed to create new element...Stack is Full.\n");
		return;
	}
	element->data = data;
	element->next = *stack;
	*stack = element;
}

int Pop(STACK_T **stack){
	if( !IsEmpty(*stack) )
	{
		int data = (*stack)->data;
		STACK_T *del = *stack;
		if(NULL != (*stack)->next)
			*stack = (*stack)->next;
		else
			*stack = NULL;
		free(del);
		return data;
	}
	else
		printf("Stack is Empty\n");
	return -1;
}

int Peep(STACK_T *stack){
	assert(stack != NULL);
	return stack->data;
}

_Bool IsEmpty(STACK_T *stack){
	return NULL == stack;
}

void FreeAll(STACK_T *stack){
	while(stack)
	{
		Pop(&stack);
	}
}

#ifdef STANDALONE
int main()
{
	STACK_T *top = NULL;
	printf("Pop = %d\n", Pop(&top));
	Push(&top, 10);
	Push(&top, 11);
	Push(&top, 12);
	Push(&top, 13);
	Push(&top, 14);
	Push(&top, 15);

	printf("Pop = %d\n", Pop(&top));
	printf("Pop = %d\n", Pop(&top));
	printf("Pop = %d\n", Pop(&top));
	printf("Pop = %d\n", Pop(&top));
	//printf("Pop = %d\n", Pop(top));
	//
	FreeAll(top);
}
#endif
