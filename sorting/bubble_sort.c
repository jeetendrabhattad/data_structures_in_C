#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int * const array, const int n)
{
    if(array)
    {
        for( int i = 0 ; i < n ; i++ )
        {
            for( int j = 0 ; j < n-i-1 ; j++ )
            {
                if(array[j] > array[j+1])
                {
                    int t = array[j];
                    array[j] = array[j+1];
                    array[j+1] = t;
                }
            }
        }
    }
}

void Display(const int *const array, const int n)
{
    printf("\n Displaying %d elements:", n);
    for( int i = 0 ; i < n ; i++ )
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int *array;
    int n;
    printf("\nEnter Number of Elements to Sort using Bubble Sort:");
    scanf("%d", &n);

    array = (int*)malloc(n*sizeof(int));
    printf("\n Enter %d elements:", n);
    for( int i = 0 ; i < n ; i++ )
        scanf("%d", &array[i]);
    Display(array, n);
    bubbleSort(array, n);
    Display(array, n);
    
    free(array);
    return 0; 
}
