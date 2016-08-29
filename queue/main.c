#include "queue.h"

typedef enum
{
	ENQUEUE = 1,
	DEQUEUE,
	EXIT
}QUEUE_OPERATIONS_T;

int menu()
{
	int choice;
	do
	{
		printf("1. EnQueue\n");
		printf("2. DeQueue\n");
		printf("3. Exit\n");
		printf("\n Enter Choice:- ");
		scanf("%d", &choice);
	}while(choice < 1 || choice > 3);
	return choice;
}

void SimulateQueue()
{
	Queue qu;
	int ret = -1;
	int data;
	int size;

	printf("\nEnter the size of Queue:-");
	scanf("%d", &size);
	if(0 == InitQueue(&qu, size))
	{
		printf("Failed to Initailize the Queue\n");
		exit(0);	
	}

	while(1)
	{
		switch(menu())
		{
			case ENQUEUE:
				if(IsQueueFull(&qu))
				{
					printf("Queue is Full, cannot add\n");
					break;
				}
				printf("Enter Data to add to qu :-\n");
				scanf("%d", &data);	
				EnQueue(&qu, data);
				break;
			case DEQUEUE:
				if(IsQueueEmpty(&qu))
				{
					printf("Queue is Empty, cannot delete\n");
					break;
				}
	
				data = DeQueue(&qu);
				printf("Data = %d\n", data);
				break;
			case EXIT:
				exit(0);
		}
	}
}

int main()
{
	SimulateQueue();
	return 0;
}
