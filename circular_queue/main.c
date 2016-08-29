#include "queue.h"

int menu()
{
	int choice;
	do
	{
		printf("1. AddQ\n");
		printf("2. DelQ\n");
		printf("3. Exit\n");
		printf("\n Enter Choice:- ");
		scanf("%d", &choice);
	}while(choice < 1 || choice > 3);
}

void SimulateQueue()
{
	struct Queue queue;
	int ret = -1;
	int data;
	if(0 == InitQ(&queue))
	{
		printf("Failed to Initailize the Queue\n");
		exit(0);	
	}

	while(1)
	{
		switch(menu())
		{
			case 1:
				if(isFull(&queue))
				{
					printf("Queue is Full, cannot add\n");
					break;
				}
				printf("Enter Data to add to queue :-\n");
				scanf("%d", &data);	
				AddQ(&queue, data);
				break;
			case 2:
				if(isEmpty(&queue))
				{
					printf("Queue is Empty, cannot delete\n");
					break;
				}
	
				data = DelQ(&queue);
				printf("Data = %d\n", data);
				break;
			case 3:
				exit(0);
		}
	}
}

int main()
{
	SimulateQueue();
	return 0;
}
