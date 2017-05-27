#include <stdio.h>
#include <stdlib.h>

int recursiveBinarySearch(const int *const array, const int lb, const int ub, const int searchElement)
{
    if(lb < ub)
    {
        int mid = (lb+ub)/2;
        if(array[mid] == searchElement)
            return 1;
        if(array[mid] > searchElement)
            return recursiveBinarySearch(array, lb, mid, searchElement);
        else
            return recursiveBinarySearch(array, mid+1, ub, searchElement);
    }
    return 0;
}

int binarySearch(const int *const array, const int size, const int searchElement)
{
    int lb = 0;
    int ub = size;
    while(lb < ub)
    {
        int mid = (lb+ub)/2;
        if(array[mid] == searchElement)
            return 1;
        if(array[mid] > searchElement)
            ub = mid;
        else
            lb = mid+1;
    }
    return 0;
}

int main()
{
    int n;
    int *array = NULL;
    int element;

    printf("\nHow many elements ?");
    scanf("%d", &n);
    
    array = (int*)malloc(n*sizeof(int));
    printf("\nEnter %d elements:-", n);
    for(int i = 0 ; i < n ; i++)
        scanf("%d", &array[i]);

    printf("\nEnter element to search:-");
    scanf("%d", &element);
    if(recursiveBinarySearch(array, 0, n, element))
    {
        printf("\n%d found in array.", element);
    }
    else
    {
        printf("\n%d not found in array.", element);
    }
    free(array);
    return 0;
}
