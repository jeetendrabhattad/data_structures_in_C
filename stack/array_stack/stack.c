#include "stack.h"

void push(STACK *stack, const int data)
{

}

int pop(STACK *stack)
{

}

int peep(STACK *stack)
{

}

int isEmpty(const STACK * const st)
{
	if( st )
		return st->top == -1;
	return -1;
}

int isFull(const STACK * const st)
{	
	if( st )
		return st->top == st->size;
	return -1;
}

void init(STACK *st, int size)
{
	if(st)
	{
		st->size = size;
		(*st).stack = (int*)malloc(size*sizeof(int));
		st->top = -1;
	}	
}

void DeInit(STACK *st)
{
	if(st && st->stack)
	{
		free(st->stack);
		st->stack = NULL;
	}
}
