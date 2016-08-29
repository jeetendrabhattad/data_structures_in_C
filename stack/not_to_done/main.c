#include <stdio.h>

int STACK[100];
int top = -1;

void push(int data)
{
	STACK[++top] = data;
}

int pop()
{
	int data = STACK[top];
	top--;
	return data;
}

int peep()
{
	return STACK[top];
}

int isEmpty()
{
	return top == -1;
}

int isFull()
{
	return top == 99;
}

int main()
{
	//menu 
	int data;
	printf("Enter Data to push:-\n");
	scanf("%d", &data);
	if( !isFull() )
		push(data);

	printf("Data after poping is %d\n", pop());
	return 0;
}
