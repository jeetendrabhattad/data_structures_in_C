#include "queue.h"
#include "stdio.h"

int main()
{
	QUEUE_T student;
	student.front = student.rear = NULL;
	Enqueue(&student, 1);
	Enqueue(&student, 2);
	Enqueue(&student, 3);
	Enqueue(&student, 4);

	printf("%d\n", Dequeue(&student));
	printf("%d\n", Dequeue(&student));
	printf("%d\n", Dequeue(&student));
	printf("%d\n", Dequeue(&student));
	printf("%d\n", Dequeue(&student));
}
