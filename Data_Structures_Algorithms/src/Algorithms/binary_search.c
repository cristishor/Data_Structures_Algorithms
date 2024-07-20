#include "binary_search.h"

/* My first attempt at what i think it might be binary search? */
/* Blindly implemented for the selection problem.              */
/* Minor intervention from GPT + random some adjustments.      */
int divideEtSort(int* sortedArray, int val, int li, int ri)
{
  if (li == ri) return li;

  int itarget;
  itarget = (li + ri) / 2;

  if (val >= sortedArray[itarget])
  {
    return divideEtSort(sortedArray, val, itarget + 1, ri);
  }
  else
  {
    return divideEtSort(sortedArray, val, li, itarget);
  }
}
