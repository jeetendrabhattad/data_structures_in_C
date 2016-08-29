#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"

void EvaluatePostfix()
{
	char expr[100];
	printf("\nEnter the postfix expression:-");
	// this results into reading upto '\n'
	scanf("%[^\n]s", expr);
	printf("\n Expression is %s\n", expr);
	int  i = 0;
	int result = 0;
	STACK_T stack;
    stack.STACK = NULL;
	InitStack(&stack, 10);
	//101 20 * 4 +
	char *token = strtok(expr," ");
    printf("Token=%s\n", token);
	int no;
	while(token)
	{
		if(isdigit(token[0]))
		{
			sscanf(token, "%d", &no);
			printf("no = %d\n", no);
			Push(&stack, no);
		}
		else
		{
			switch(token[0])
			{
				case '+':
					result = Pop(&stack)+Pop(&stack);
					printf("\n Addition is %d \n", result);
					Push(&stack, result);
				break;
				case '*':
					result = Pop(&stack)*Pop(&stack);
					printf("\n Multiplication is %d \n", result);
					Push(&stack, result);
				break;
				case '-':
				{
					int no2 = Pop(&stack);
					int no1 = Pop(&stack);
					result = no1 - no2;
					printf("\n Subtraction is %d \n", result);
					Push(&stack, result);
				}
				break;
				case '/':
				{
					int no2 = Pop(&stack);
					int no1 = Pop(&stack);
					result = no1/no2;
					printf("\n Divsion is %d \n", result);
					Push(&stack, result);
				}
				break;
			}
		}
		token = strtok(NULL, " ");
		printf("Token=%s\n", token);
	}
	printf("Final Result = %d\n", Pop(&stack));
	DeInitStack(&stack);
}

int main()
{
	EvaluatePostfix();
}
