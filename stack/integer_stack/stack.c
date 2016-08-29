#include "stack.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

_Bool InitStack(STACK_T* const st, int size)
{
	// STACK_ALREADY_CREATED
	if(NULL != st && NULL == st->STACK)
	{
		//(*st).iTop = -1;
        st->iTop = -1;
		st->iSize = size;
		st->STACK = (int *)malloc(sizeof(int)*size);
		if( NULL != st->STACK )
			return true;
	}
	return false;
}

void DeInitStack(STACK_T* const st)
{
	if(NULL != st)
	{
		if( NULL != st->STACK )
		{
			free(st->STACK);
            st->STACK=NULL;
		}
	}
}

void Push(STACK_T* const st, int data)
{
	if( st && st->STACK && !IsFull(st))
	{
		st->STACK[++st->iTop] = data;
	}
}

int Pop(STACK_T* const st)
{
	int temp = -1;
	if( st && st->STACK && !IsEmpty(st))
	{
		temp = st->STACK[st->iTop];
		st->iTop--;
	}
	return temp;
}

_Bool IsFull(STACK_T* const st)
{
	if( st )
		return st->iTop+1 == st->iSize;

	return false;
}

_Bool IsEmpty(STACK_T* const st)
{
	if( st )
		return st->iTop == -1;
	return false;
}

int Peep(STACK_T* const st)
{
	if( st && st->STACK && !IsEmpty(st) )
		return st->STACK[st->iTop];
	return -1;
}

// gcc -DSTANDALONE stack.c :- this will result into defining macro STANDALONE.
#ifdef STANDALONE
int main()
{
	STACK_T st;
	st.STACK = NULL;

 	//accept size from user
	if(!InitStack(&st, 20))
			printf("STACK_T un-initialized !!!\n");
	if(!InitStack(NULL, 20))
			printf("STACK_T un-initialized !!!\n");

	Push(&st, 10);
	printf("Pop = %d\n", Pop(&st));	
	
	STACK_T st1;
	st1.STACK = NULL;
 	//accept size from user
	int size;
	printf("Enter size of stack:-");
	scanf("%d",&size);
	InitStack(&st1, size);
	if(!InitStack(&st1, size))
			printf("Failed to initialize already initialized\n");
	Push(&st1, 50);
	printf("Pop = %d\n", Pop(&st1));
	
	printf("st %p st1 %p\n", st.STACK, st1.STACK);
	DeInitStack(&st);
	DeInitStack(&st1);
	return 0;
}
#endif
