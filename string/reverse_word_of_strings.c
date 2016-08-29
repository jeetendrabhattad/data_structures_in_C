#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

void ReverseString(const char *const input_string, char *const output_string)
{
	char *ptr = input_string + strlen(input_string) - 1;
	char *outptr = output_string;
	
	while(ptr != input_string)
	{
		*outptr++ = *ptr--;
	}
	*outptr++ = *ptr;
	*outptr = '\0';
}

void ReverseStringWords(const char *const input_string, char *const output_string)
{
	char *ptr = strtok(input_string, " ");
	char *outptr = output_string;
	while(ptr)
	{
		printf("Token = %s\n", ptr);
		char *subptr = ptr + strlen(ptr) - 1;
		while(subptr != ptr)
		{
			*outptr++ = *subptr--;
		}
		*outptr++ = *subptr;
		*outptr = ' ';
		ptr = strtok(NULL, " ");
	}
	*outptr = '\0';
}

int main()
{
	char *input_string = NULL;
	char *output_string = NULL;
	unsigned int length = 0;

	printf("\nEnter string:-");
	getline(&input_string, &length, stdin);
	output_string = (char*)malloc(sizeof(char)*length);	
	printf("Input string is %s of length %d\n", input_string, length);
	ReverseStringWords(input_string, output_string);

	printf("\nOriginal String is %s\nReverse string is %s\n", input_string, output_string);
	free(input_string);
	free(output_string);
	return 0;
}
