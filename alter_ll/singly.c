#include "singly.h"
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
	while( lengthHead )
	{
		count++;
		lengthHead = lengthHead->next;
	}
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
		STUDENT_T* traverse;
		for(traverse = insertHead; Position - 2 ; traverse=traverse->next, --Position );
		student->next = traverse->next;
		traverse->next = student;
	}
	return insertHead;
}

STUDENT_T* DeleteStudent(STUDENT_T * deleteHead, int Position)
{
	if( NULL != deleteHead )
	{
		STUDENT_T *student = deleteHead;
		if ( 1 == Position )
		{
			deleteHead = deleteHead->next;
		}
		else
		{
			STUDENT_T *traverse = deleteHead;
			while( Position - 2 > 0 )
			{
				traverse = traverse->next;
				Position--;
			}
			student = traverse->next;
			traverse->next = student->next;
			student->next = NULL; 
		}
		free(student);
	}
	return deleteHead;
}

void DisplayStudents(STUDENT_T * displayHead)
{
	while( displayHead )
	{
		printf("Roll Number = %d\n", displayHead->m_iRollNo);
		displayHead = displayHead->next;
	}
}

void FreeStudentsList(STUDENT_T * freeHead)
{
	while(freeHead)
	{
		freeHead = DeleteStudent(freeHead, 1);
	}
}

STUDENT_T* AlternateReverse(STUDENT_T* reverseHead)
{
	STUDENT_T *t1 = reverseHead;
	STUDENT_T *t2 = reverseHead->next;
	STUDENT_T *t3 = t2->next;
	STUDENT_T *t4 = NULL;
	while(1)
	{
		t1->next = t3;
		t2->next = t1;
		if(t1 == reverseHead)
			reverseHead = t2;
		else
			t4->next = t2;

		if(t1->next == NULL || t3->next == NULL)
			break;
		t4 = t1;
		t1 = t3;
		t2 = t3->next;
		t3 = t2->next;
	}
	return reverseHead;
}
