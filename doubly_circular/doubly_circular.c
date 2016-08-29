#include "doubly_circular.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

STUDENT_T* CreateStudentsList(int noOfStudents)
{
	STUDENT_T *head = NULL;
	
	for( int i = 1 ; i <= noOfStudents ; i++ )
	{
		int RollNo;
		printf("Enter RollNO :-");
		scanf("%d", & RollNo);
		head = InsertStudent(head, RollNo, i);
	}
	return head;
}

int GetLengthOfList(STUDENT_T *lengthHead)
{
	int count = 0;
	if( NULL == lengthHead )
		return count;
	STUDENT_T *traverse = lengthHead;
	do
	{
		count++;
		traverse = traverse->next;
	}while( traverse != lengthHead );
	return count;
}

_Bool IsValidPosition(STUDENT_T *positionHead, int Position)
{
	int length = GetLengthOfList(positionHead);
	if( Position < 1 || Position > (length + 1))
		return false;
	return true;
}

STUDENT_T* InsertStudent(STUDENT_T *insertHead, int RollNo, int Position)
{
	STUDENT_T *student = (STUDENT_T*)malloc(sizeof(STUDENT_T));
	student->m_iRollNo = RollNo;
	student->next = NULL;
	student->prev = NULL;
	if( 1 == Position )
	{
		if( NULL == insertHead )
		{
			insertHead = student;
			insertHead->next = insertHead->prev = insertHead;
		}
		else
		{
			student->next = insertHead;
			student->prev = insertHead->prev;
			insertHead->prev->next = student;
			insertHead->prev = student;	
			insertHead = student;
		}
	}
	else
	{
		STUDENT_T* traverse;
		for(traverse = insertHead; Position - 2 > 0 ; traverse=traverse->next, --Position );
		student->next = traverse->next;
		student->prev = traverse;
		traverse->next->prev = student;
		traverse->next = student;
	}
	return insertHead;
}

STUDENT_T* DeleteStudent(STUDENT_T * deleteHead, int Position)
{
	if( NULL != deleteHead )
	{
		STUDENT_T *student = NULL;
		if ( 1 == Position )
		{
			student = deleteHead;
			deleteHead = deleteHead->next;
			deleteHead->prev = student->prev;
			student->prev->next = deleteHead;
			student->next = student->prev = NULL;
		}
		else
		{
			student = deleteHead;
			while( Position - 1 > 0 )
			{
				student = student->next;
				Position--;
			}
			printf("Deleting %d\n", student->m_iRollNo);
			printf("student->prev %p student->next %p\n", student->prev, student->next);
			student->prev->next = student->next;
			student->next->prev = student->prev;
			printf("student->prev->next %p student->next->prev %p\n", student->prev->next, student->next->prev);
			student->next = student->prev = NULL;
		}
		free(student);
	}
	return deleteHead;
}

void DisplayStudents(STUDENT_T * displayHead)
{
	if( NULL == displayHead )
	{
		printf("List is empty nothing to display\n");
		return;
	}
	STUDENT_T *traverse = displayHead;
	do
	{
		printf("Roll Number = %d\n", traverse->m_iRollNo);
		traverse = traverse->next;
	}while( traverse != displayHead );
}

void FreeStudentsList(STUDENT_T * freeHead)
{
	if(NULL != freeHead)
	{
		// if it contains only 1 node, free it directly
		if(freeHead != freeHead->next)
		{
			do
			{
				freeHead = DeleteStudent(freeHead, 1);
			}while(freeHead->next != freeHead);
		}
		free(freeHead);
		freeHead = NULL;
	}
}
