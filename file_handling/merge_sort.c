#include<stdio.h>
#include<stdlib.h>
void merge (int[], int [], int, int, int);
void partition (int[], int [], int, int);

void
partition (int arr[], int result[], int min, int max)
{
  int mid;
  if (min < max)
    {
      mid = (min + max) / 2;
      partition (arr, result, min, mid);
      partition (arr, result, mid + 1, max);
      merge (arr, result, min, mid, max);
    }
}

void
merge (int arr[], int result[], int min, int mid, int max)
{
  int i, j, k;
  i = min;
  j = mid+1;
  int m = 0;
  while( i <= mid && j <= max)
  {
  	if(arr[i] < arr[j])
	{
		result[m] = arr[i];
		i++;
	}
	else
	{
		result[m] = arr[j];
		j++;
	}
	m++;
  }
  while( i <= mid )
  {
     result[m] = arr[i];
     i++;
	 m++;
  }
  while( j <= max )
  {
     result[m] = arr[j];
     j++;
     m++;
  }

  for ( i = min, j = 0 ; i <= max ; i++, j++)
  {
	arr[i] = result[j];
  }
}
