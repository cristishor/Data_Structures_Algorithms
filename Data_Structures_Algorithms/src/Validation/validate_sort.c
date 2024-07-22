
/* Function to test the result of a sorting function. */

#include "validate_sort.h"
#include "stdint.h"

extern int isArraySorted(int* array, int size)
{
  int i;
  for (i = 0; i < size - 1; i++)
  {
    if (array[i] > array[i+1]) return 0;
  }
  return 1;
}
