
/* THE SELECTION PROBLEM */

/* * * * * * * * * * * * * * */
/*                           */
/*          Summary          */
/*                           */
/* n numbers                 */
/*                           */
/* ? k'th largest            */
/*                           */
/* for k = n / 2             */
/*                           */
/* * * * * * * * * * * * * * */
#define _CRT_SECURE_NO_WARNINGS 1

#include "the_selection_problem.h"

#include "Algorithms/binary_search.h"

#include "../include/array_generator.h"
#include "../include/timer.h"
#include "../include/utils.h"

/* (0) Naive approach - way of comparing the worst case scenario (not to be used with large sets of inputs) */
static int naive()
{
  return 0;
}

/* (1) Blind first try */
static int blind(int* array, int size, int kth_num)
{
  /* Tried sorting the array w/ what i thought it was a binary search - implemented my first recrecursion in ages. */
  int i, j;
  int sortedArray[MAX_ARRAY_SIZE] = { 0 };
  int index;
  int value;

  for (int i = 0; i < size; i++)
  {
    value = array[i];
    index = divideEtSort(sortedArray, value, 0, i);
    for (j = i; j > index; j--)
    {
      sortedArray[j] = sortedArray[j - 1];
    }
    sortedArray[index] = value;
  }

  return sortedArray[kth_num - 1];
}

void test_selection_problem()
{
  int inputSize[] = {
    SMALL_ARRAY_SIZE,
      MID_ARRAY_SIZE,
    LARGE_ARRAY_SIZE
  };
  const char inputNames[][10] = {
  "S",
  "M",
  "L"
  };
  int inputCount = sizeof(inputSize) / sizeof(inputSize[0]);

  const char methodName[METHOD_COUNT][MAX_CHAR_STRING] = {
    "Naive approach",
    "Blind"
  };

  int* array;
  int arraySize;
  int Kth;
  int inIdx, mthdIdx;
  int result;

  array = GENERATE_ARRAY();

  /* We scroll through each input (different array sizes) */
  /* testing only for Kth = arraySize / 2                 */
  for (inIdx = 0; inIdx < inputCount; inIdx++)
  {
    arraySize = inputSize[inIdx];
    Kth = arraySize / 2;

    /* Then we try each method out */
    for (mthdIdx = 0; mthdIdx < METHOD_COUNT; mthdIdx++)
    {
      char testName[MAX_CHAR_STRING];
      sprintf(testName, "%d.%s w/ %s", inIdx, inputNames[inIdx], methodName[mthdIdx]);

      startClock(testName);
        switch (mthdIdx)
        {
          case NAIVE_APPROACH:
            // result = naive();
            // TO DO: TIMEOUT AFETR TOO MUCH TIME (multithread?)

            // TO DO actually: more to like - validate the correctness!
            break;

          case BLIND:
            result = blind(array, arraySize, Kth);
            // TO DO: VALIDATE THE SORTING ALGO
            break;

          default:
            fprintf(stderr, "Unrecognized method: (%d)", mthdIdx);
        }
      stopClock();
    }
    NEW_LINE();
  }
}
