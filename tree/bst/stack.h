#ifndef STACK_H
#define STACK_H
#include "bst.h"

typedef struct
{
	TREENODE_T *STACK;
	int iTop;
	int iSize;
}STACK_T;

// interface of stack
_Bool InitStack(STACK_T* const st, int size);
void DeInitStack(STACK_T* const st);
void Push(STACK_T* const st, TREENODE_T data);
TREENODE_T Pop(STACK_T* const st);
_Bool IsFull(STACK_T* const st);
_Bool IsEmpty(STACK_T* const st);
TREENODE_T Peep(STACK_T* const st);
#endif
