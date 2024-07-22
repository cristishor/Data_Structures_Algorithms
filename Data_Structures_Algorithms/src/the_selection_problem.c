
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
#include "Algorithms/bubble_sort.h"

#include "../include/array_generator.h"
#include "../include/vect_copy.h"
#include "../include/timer.h"
#include "../include/utils.h"

/* (0) Naive approach - way of comparing the worst case scenario (not to be used with large sets of inputs) */
/* METHOD: IN_PLACE */
static int naive(int* array, int size, int kth_num)
{
  bubbleSort(array, size);
  return array[kth_num - 1];
}

/* (1) Blind first try */
/* METHOD: out_of_place */
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
    index = binarySearch(sortedArray, value, 0, i);
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

  enum selection_problem_methods {
    NAIVE_APPROACH = 0,
    BLIND,
    METHOD_COUNT
  };
  const char methodName[METHOD_COUNT][MAX_CHAR_STRING] = {
    "Naive approach",
    "Blind"
  };

  int* array;
  int* scratchArray;
  int arraySize;
  int Kth;
  int inIdx, mthdIdx;
  int result;

  array = GENERATE_ARRAY();
  scratchArray = (int*)calloc(MAX_ARRAY_SIZE, sizeof(int));

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
            VectCopy(array, scratchArray, arraySize);
            result = naive(scratchArray, arraySize, Kth);
            // TO DO: TIMEOUT AFETR TOO MUCH TIME (multithread?)
            break;

          case BLIND:
            result = blind(scratchArray, arraySize, Kth);
            break;

          default:
            fprintf(stderr, "Unrecognized method: (%d)", mthdIdx);
        }
      stopClock();

      // VALIDATE RESULT

    }
    NEW_LINE();
  }
}
