#include "bubble_sort.h"

/* Jus bubble sort (he's trying his best, ok?) */

void bubbleSort(int* array, int size)
{
  int i, j;
  int aux;

  for (i = 0; i < size - 1; i++)
  {
    for (j = 0; j < size - 1; j++)
    {
      if (array[j] > array[j + 1])
      {
        aux = array[j + 1];
        array[j + 1] = array[j];
        array[j] = aux;
      }
    }
  }
}
