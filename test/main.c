#include "doubly_circular.h"
#include <stdio.h>
#include <stdlib.h>

typedef enum
{
	CREATE = 1,
	INSERT,
	DELETE,
	DISPLAY,
	EXIT
}CHOICE_T;

int Menu()
{
	int choice;
	do
	{
		printf("1. Create\n");
		printf("2. Insert\n");
		printf("3. Delete\n");
		printf("4. Display\n");
		printf("5. Exit\n");
		printf("Enter the Choice:-");
		scanf("%d", &choice);
	}while(choice < 0 || choice > 5);
	return choice;
}

void DemoDoublyCircular()
{
	struct Student *mcsHead = NULL;
	while(1)
	{
		switch(Menu())
		{
			case CREATE:
			{
				if(NULL == mcsHead)
				{
					int noOfStudents;
					printf("\nEnter Number of Students to Create:-");
					scanf("%d", &noOfStudents);
					mcsHead = CreateStudentsList(noOfStudents);
				}
				else
				{
					printf("List is already created, use insert to add\n");
				}
			}
			break;
			case INSERT:
			{
				int Position;
				int RollNo;
				printf("\nEnter Position to Insert:-");
				scanf("%d", &Position);
				if(IsValidPosition(mcsHead, Position))
				{
					printf("\nEnter RollNo to Insert:-");
					scanf("%d", &RollNo);
					mcsHead = InsertStudent(mcsHead, RollNo, Position);
				}
				else
				{
					printf("\nInvalid Position Cannot Insert.....\n");
				}
			}
			break;
			case DELETE:
			{
				if( NULL != mcsHead )
				{
					int Position;
					printf("\nEnter Position to Delete:-");
					scanf("%d", &Position);
					if(Position < 0 || Position > GetLengthOfList(mcsHead))
					{
						printf("\nInvalid Position Cannot Delete.....\n");
					}
					else
					{
						if(mcsHead->next == mcsHead)
						{
							free(mcsHead);
							mcsHead = NULL;
						}
						else
							mcsHead = DeleteStudent(mcsHead, Position);
					}
				}
				else
				{
					printf("\n List is Empty nothing to delete\n");
				}
			}
			break;
			case DISPLAY:
				DisplayStudents(mcsHead);
			break;
			case EXIT:
				FreeStudentsList(mcsHead);
				exit(0);
			break;
		}
	}
}

int main()
{
	printf("Doubly Circular LinkedList Demo\n");
	DemoDoublyCircular();
}
