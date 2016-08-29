#include "singly.h"
#include <stdio.h>
#include <stdlib.h>

typedef enum
{
	INSERT = 1,
	DELETE,
	ALTERNATE_REV,
	DISPLAY,
	EXIT
}CHOICE_T;

int Menu()
{
	int choice;
	do
	{
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Reverse-Alter\n");
		printf("4. Display\n");
		printf("5. Exit\n");
		printf("Enter the Choice:-");
		scanf("%d", &choice);
	}while(choice < 0 || choice > 5);
	return choice;
}

void DemoSingly()
{
	struct Student *mcsHead = NULL;
	int noOfStudents;
	printf("\nEnter Number of Students to Create:-");
	scanf("%d", &noOfStudents);
	mcsHead = CreateStudentsList(noOfStudents);
	while(1)
	{
		switch(Menu())
		{
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
						mcsHead = DeleteStudent(mcsHead, Position);
					}
				}
				else
				{
					printf("\n List is Empty nothing to delete\n");
				}
			}
			break;
			case ALTERNATE_REV:
			{
				if( NULL != mcsHead )
				{
					mcsHead = AlternateReverse(mcsHead);
				}
			}
			break;
			case DISPLAY:
				DisplayStudents(mcsHead);
			break;
			case EXIT:
				FreeStudentsList(mcsHead);
				exit(0);
		}
	}
}

int main()
{
	printf("Singly LinkedList Demo\n");
	DemoSingly();
}
