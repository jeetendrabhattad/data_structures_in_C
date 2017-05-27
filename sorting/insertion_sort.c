#include <stdio.h>
#include <stdlib.h>

void insertionSort(int * const array, const int n)
{
    if(array)
    {
        int j;
        int key;
        for( int i = 1 ; i < n ; i++ )
        {
            key = array[i];
            for(j = i - 1 ; j >= 0 && key < array[j] ; j--)
            {
                array[j+1] = array[j];
            }
            array[j+1] = key;
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
    printf("\nEnter Number of Elements to Sort using Insertion sort:");
    scanf("%d", &n);

    array = (int*)malloc(n*sizeof(int));
    printf("\n Enter %d elements:", n);
    for( int i = 0 ; i < n ; i++ )
        scanf("%d", &array[i]);
    Display(array, n);
    insertionSort(array, n);
    Display(array, n);
    
    free(array);
    return 0; 
}
