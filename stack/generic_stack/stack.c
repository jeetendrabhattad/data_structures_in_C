#include "stack.h"


void push(Stack *s, StackElement element)
{
	s->items[++s->iTop] = element;
}

StackElement pop(Stack *s)
{
	StackElement ele = s->items[s->iTop];
	s->iTop--;
	return ele;
}

// implement peep, isempty, isfull
