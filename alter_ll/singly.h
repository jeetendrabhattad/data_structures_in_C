#ifndef SINGLY_H
#define SINGLY_H

typedef struct Student
{
	int m_iRollNo;
	struct Student *next;
}STUDENT_T;

STUDENT_T* CreateStudentsList(int noOfStudents);
STUDENT_T* InsertStudent(STUDENT_T * insertHead, int RollNo, int Position);
STUDENT_T* DeleteStudent(STUDENT_T * const deleteHead, int Position);
void DisplayStudents(STUDENT_T * displayHead);
void FreeStudentsList(STUDENT_T * freeHead);
_Bool IsValidPosition(STUDENT_T *positionHead, int Position);
int GetLengthOfList(STUDENT_T *lengthHead);
STUDENT_T* AlternateReverse(STUDENT_T*);
#endif
