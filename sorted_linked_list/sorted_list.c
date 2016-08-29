#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	struct Node* next;
	int data;
}NODE_T;

typedef enum
{
	INSERT=1,
	SEARCH,
	DISPLAY,
	EXIT
}LL_OPERATIONS_T;

int Menu()
{
	int choice = 0;
	//insert, search, display, exit
	do
	{
		printf("1.Insert\n");
		printf("2.Search\n");
		printf("3.Display\n");
		printf("4.Exit\n");
		printf("Enter your choice\n");
		scanf("%d", &choice);
	}while(choice < 1 || choice > 4);
	return choice;
}

NODE_T* Insert(NODE_T *start, int data)
{
	NODE_T *temp = (NODE_T*)malloc(sizeof(NODE_T));
	if(NULL == temp)
	{
		printf("Failed to allocate memory, have to suicide !!!!");
		exit(-1);
	}

	temp->next = NULL;
	temp->data = data;
	if(NULL == start)
	{
		start = temp;
	}
	else
	{
		if(data <= start->data)
		{
			temp->next = start;
			start = temp;
		}
		else
		{
			NODE_T *traverse = start;
			while(traverse->next && traverse->next->data < data)
					traverse = traverse->next;
			temp->next = traverse->next;
			traverse->next = temp;
		}
	}
	return start;
}
NODE_T* CreateAscendingSortedLinkedList(int noOfNodes)
{
	NODE_T *start = NULL;
	int data;
	for( int i = 0 ; i < noOfNodes ; i++ )
	{
		printf("Enter Data to be added:-");
		scanf("%d", &data);
		start = Insert(start, data);
	}
	return start;
}

void Display(NODE_T *displayHead)
{
	while(displayHead)
	{
		printf("Data = %d\n", displayHead->data);
		displayHead = displayHead->next;
	}
}

int Search(NODE_T *searchHead, int data)
{
	while(searchHead && searchHead->data <= data)
	{
		if(data == searchHead->data)
				return 1;
		searchHead = searchHead->next;
	}
	return 0;
}

void FreeAllNodes(NODE_T *freeHead)
{
	NODE_T *temp;
	while(freeHead)
	{
		temp = freeHead;
		freeHead = freeHead->next;
		free(temp);
	}
}

void SimulateSortedSinglyLinkedList()
{
	NODE_T *head = NULL;
	int noOfNodes = 0;
	int ch;
	printf("Enter how many nodes you want to create initially:-");
	scanf("%d", &noOfNodes);
	head = CreateAscendingSortedLinkedList(noOfNodes);

	while(ch=Menu())
	{
		switch(ch)
		{
			case INSERT:
			{
				int data;
				printf("Enter data to insert:-");
				scanf("%d", &data);
				head = Insert(head, data);
			}
			break;
			case SEARCH:
			{
				int data;
				printf("Enter data to search:-");
				scanf("%d", &data);
				if(Search(head, data))
				{
					printf("Data %d found\n", data);
				}
				else
				{
					printf("Data %d not found\n", data);	
				}
			}
			break;
			case DISPLAY:
				Display(head);
				break;
			case EXIT:
				FreeAllNodes(head);
				exit(0);
		}
	}
}

int main()
{
	printf("Welcome to demo of Sorted Singly Linked List\n");
	SimulateSortedSinglyLinkedList();
	return 0;
}
