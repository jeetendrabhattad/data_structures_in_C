#ifndef DOUBLY_CIRCULAR_H
#define DOUBLY_CIRCULAR_H

struct Student
{
	int m_iRollNo;
	struct Student *next;
	struct Student *prev;
};

struct Student* CreateStudentsList(int noOfStudents);
struct Student* InsertStudent(struct Student * insertHead, int RollNo, int Position);
struct Student* DeleteStudent(struct Student * const deleteHead, int Position);
void DisplayStudents(struct Student * displayHead);
void FreeStudentsList(struct Student * freeHead);
_Bool IsValidPosition(struct Student *positionHead, int Position);
int GetLengthOfList(struct Student *lengthHead);
#endif
