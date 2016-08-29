#include "singly.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Student* CreateStudentsList(int noOfStudents)
{
	struct Student *head = NULL;
	
	for( int i = 1 ; i <= noOfStudents ; i++ )
	{
		int RollNo;
		printf("Enter RollNO :-");
		scanf("%d", & RollNo);
		head = InsertStudent(head, RollNo, i);
	}
	return head;
}

int GetLengthOfList(struct Student *lengthHead)
{
	int count = 0;
	while( lengthHead )
	{
		count++;
		lengthHead = lengthHead->next;
	}
	return count;
}

_Bool IsValidPosition(struct Student *positionHead, int Position)
{
	int length = GetLengthOfList(positionHead);
	if( Position < 1 || Position > (length + 1))
		return false;
	return true;
}

struct Student* InsertStudent(struct Student *insertHead, int RollNo, int Position)
{
	struct Student *student = (struct Student*)malloc(sizeof(struct Student));
	student->m_iRollNo = RollNo;
	student->next = NULL;
	if( 1 == Position )
	{
		if( NULL == insertHead )
		{
			insertHead = student;
		}
		else
		{
			student->next = insertHead;
			insertHead = student;
		}
	}
	else
	{
		struct Student* traverse;
		for(traverse = insertHead; travers->next && Position - 2 ; traverse=traverse->next, --Position )
            ;
        if(Position - 2 == 0)
        {
	    	student->next = traverse->next;
		    traverse->next = student;
        }
        else
        {
            printf("Wrong Position Entered\n");
            free(student);
        }
	}
	return insertHead;
}

struct Student* DeleteStudent(struct Student * deleteHead, int Position)
{
	if( NULL != deleteHead )
	{
		struct Student *student = deleteHead;
		if ( 1 == Position )
		{
			deleteHead = deleteHead->next;
		}
		else
		{
			struct Student *traverse = deleteHead;
			while(traverse->next && Position - 2 )
			{
				traverse = traverse->next;
				Position--;
			}
            if(Position - 2 == 0)
            { 
			    student = traverse->next;
    			traverse->next = student->next;
	    		student->next = NULL; 
            }
            else
            {
                printf("Invalid Position\n");
                return deleteHead;
            }
		}
		free(student);
	}
	return deleteHead;
}

void DisplayStudents(struct Student * displayHead)
{
	while( displayHead )
	{
		printf("Roll Number = %d\n", displayHead->m_iRollNo);
		displayHead = displayHead->next;
	}
}

void FreeStudentsList(struct Student * freeHead)
{
	while(freeHead)
	{
		freeHead = DeleteStudent(freeHead, 1);
	}
}
