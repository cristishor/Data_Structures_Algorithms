#include "binary_search.h"

/* My first attempt at what i think it might be binary search? */
/* Blindly implemented for the selection problem.              */
/* Minor intervention from GPT + random some adjustments.      */
int binarySearch(int* array, int val, int li, int ri)
{
  if (li == ri) return li;

  int itarget;
  itarget = (li + ri) / 2;

  if (val >= array[itarget])
  {
    return binarySearch(array, val, itarget + 1, ri);
  }
  else
  {
    return binarySearch(array, val, li, itarget);
  }
}
