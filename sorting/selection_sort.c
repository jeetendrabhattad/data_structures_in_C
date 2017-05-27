#include <stdio.h>
#include <stdlib.h>

void selectionSort(int * const array, const int n)
{
    if(array)
    {
        for( int i = 0 ; i < n ; i++ )
        {
            for( int j = i+1 ; j < n ; j++ )
            {
                if(array[i] > array[j])
                {
                    int t = array[i];
                    array[i] = array[j];
                    array[j] = t;
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
    printf("\nEnter Number of Elements to Sort using Selection sort:");
    scanf("%d", &n);

    array = (int*)malloc(n*sizeof(int));
    printf("\n Enter %d elements:", n);
    for( int i = 0 ; i < n ; i++ )
        scanf("%d", &array[i]);
    Display(array, n);
    selectionSort(array, n);
    Display(array, n);
    
    free(array);
    return 0; 
}
