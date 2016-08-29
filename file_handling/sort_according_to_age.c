#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int age;
	float salary;
	char name[20];
}EMPLOYEE_T;

void RecordHandling()
{
	FILE *fp = fopen("employee.txt", "r");
	FILE *fp_sorted = NULL;
	if(NULL == fp)
	{
		printf("Failed to open file, doing suicide\n");
		exit(-1);
	}
	EMPLOYEE_T employee_record[20];
	int age_array[20] = {0};
	int sorted_age_array[20] = {0};
	int no_of_records = 0;
	char line[80];
	int i = 0;
	while(fgets(line, 80, fp))
	{
		sscanf(line, "%s %d %f", employee_record[i].name, &employee_record[i].age, &employee_record[i].salary);
		printf("name=%s, age=%d, salary = %f\n", employee_record[i].name, employee_record[i].age, employee_record[i].salary);
		age_array[i] = employee_record[i].age;
		i++;
	}
	no_of_records = i;
	partition (age_array, sorted_age_array, 0, no_of_records-1);

	fp_sorted=fopen("employee_sorted_age.txt", "w");
	if(NULL == fp_sorted)
	{
		printf("Failed to create sorted file, have to suicide hard luck try next time\n");
		exit(-1);
	}
	i = 0;
	int j = 0;
   	while(i < no_of_records)
	{
		if(sorted_age_array[i] == employee_record[j].age)
		{
			char output_string[80]={0};
			sprintf(output_string, "%s %d %f\n", employee_record[j].name, employee_record[j].age, employee_record[j].salary);
			fwrite(output_string, strlen(output_string), 1, fp_sorted);
			i++;
		}
		j++;
		if(j == no_of_records)
			j = 0;
	}
}

int main()
{
	RecordHandling();
	return 0;
}
