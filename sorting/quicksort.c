#include<stdio.h>
#include<stdlib.h>

void quicksort (int[], int, int);

int
main ()
{
  int *x, size, i;

  printf ("Enter size of the array: ");
  scanf ("%d", &size);
  x = malloc(size*sizeof(int));

  printf ("Enter %d elements: ", size);
  for (i = 0; i < size; i++)
    scanf ("%d", &x[i]);

  quicksort (x, 0, size - 1);

  printf ("Sorted elements: ");
  for (i = 0; i < size; i++)
    printf (" %d", x[i]);

  free(x);
  return 0;
}

void
quicksort (int x[], int lb, int ub)
{
  int pivot, down, temp, up;

  if (lb < ub)
  {
      pivot = lb;
      up = lb;
      down = ub;

      while (up < down)
	  {
	     while (x[up] <= x[pivot]
					  && up < ub)
	        up++;
	     while (x[down] > x[pivot])
	        down--;

	     if (up < down)
	     {
	        temp = x[up];
	        x[up] = x[down];
	        x[down] = temp;
	     }
	  }
	  if( up >= down )
      {	  
         temp = x[pivot];
         x[pivot] = x[down];
         x[down] = temp;
      }

      quicksort (x, lb, down - 1);
      quicksort (x, down + 1, ub);
    }
}
