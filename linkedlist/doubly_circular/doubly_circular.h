#ifndef DOUBLY_CIRCULAR_H
#define DOUBLY_CIRCULAR_H

typedef struct Student
{
	int m_iRollNo;
	struct Student *next;
	struct Student *prev;
}STUDENT_T;

STUDENT_T* CreateStudentsList(int noOfStudents);
STUDENT_T* InsertStudent(STUDENT_T * insertHead, int RollNo, int Position);
STUDENT_T* DeleteStudent(STUDENT_T * const deleteHead, int Position);
void DisplayStudents(STUDENT_T * displayHead);
void FreeStudentsList(STUDENT_T * freeHead);
_Bool IsValidPosition(STUDENT_T *positionHead, int Position);
int GetLengthOfList(STUDENT_T *lengthHead);
#endif
