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
	Stack stack;
	InitStack(&stack, 10);
	//101 20 * 4 +
	char *token = strtok(expr," ");
	printf("Token=%s\n", token);
	int no;
	if(isdigit(token[0]))
	{
		sscanf(token, "%d", &no);
		printf("no = %d\n", no);
	}
	while(token)
	{
		token = strtok(NULL, " ");
		printf("Token=%s\n", token);
	}

	while(expr[i] != '\0')
	{
		if(isdigit(expr[i]))
		{
			printf("\n Pushing %d", expr[i]-48);
			Push(&stack, expr[i]-48);	
			i++;
			while(expr[i] != ' ' && isdigit(expr[i]))
			{
				result = Pop(&stack);
				result = result*10 + (expr[i]-48);
				printf("\nLogic result = %d", result);	
				Push(&stack, result);
				i++;
			}
		}
		else
		{
			switch(expr[i])
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
		i++;
	}
	printf("Final Result = %d\n", Pop(&stack));
	DeInitStack(&stack);
}

int main()
{
	EvaluatePostfix();
}
