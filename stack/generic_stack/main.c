#include "stack.h"
#include <stdio.h>

void Display(StackElement ele)
{
	switch(ele.type)
	{
		case INTEGER:
			printf("Integer Data %d\n", ele.element.iVal);
		break;
		case FLOAT:
			printf("Float Data %f\n", ele.element.fVal);
		break;
		case STRING:
			printf("String Data %s\n", ele.element.pVal);
		break;
	}
}

void SimulateGenericStack()
{
	Stack st;
	st.iTop = -1; // h.w Init method
 				// accept size and pass that to init.
	StackElement ele;
	ele.type = INTEGER;
	ele.element.iVal = 1000;
	push(&st, ele);
	
	ele.type = FLOAT;
	ele.element.fVal = 10.04f;
	push(&st, ele);

	ele = pop(&st);
	Display(ele);
	
	ele = pop(&st);
	Display(ele);
}

int main()
{
	SimulateGenericStack();
}
