#ifndef STACK_H
#define STACK_H

#define STACKSIZE 100
typedef enum
{
	INTEGER = 1,
	FLOAT,
	STRING,
	DOUBLE,
}TYPE_T;

typedef struct
{
	TYPE_T type; // what kind of data has been stored in element
	union{
		int iVal;
		float fVal;
		char *pVal;
		double dVal;
	}element;
}StackElement;

// H.W
// Take StackElement *STACK;
//		int iSize;
typedef struct{
	int iTop;
	StackElement items[STACKSIZE]; // static stack of 100 elements
}Stack;

void push(Stack *s, StackElement element);
StackElement pop(Stack *s);

#endif
