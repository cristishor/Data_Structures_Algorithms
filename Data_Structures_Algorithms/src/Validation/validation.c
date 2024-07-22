
/* Validation functions */

#include "validation.h"

#include "../../include/vect_copy.h"
#include "../../include/timer.h"
#include "../../include/array_generator.h"

#include "validate_sort.h"
#include "../Algorithms/bubble_sort.h"
#include "../Algorithms/binary_search.h"

extern void algorithmValidation()
{
  validationState sValidation;
  int* inArray;
  int* outArray;
  const char string[256];

  inArray = GENERATE_ARRAY();
  outArray = (int*)malloc(LARGE_ARRAY_SIZE * sizeof(int));

  sValidation.inArray  = inArray;
  sValidation.outArray = outArray;
  sValidation.arraySize = LARGE_ARRAY_SIZE;

  /* --------------------------------------------- */

  printf("Running validation process of the algorithms...\n");

  /* --------------------------------------------- */

  /* I.Sorting algo's */
  sValidation.algorithmType = SORT_T;

  /* (1) Bubble sort  */
  memset(outArray, 0, LARGE_ARRAY_SIZE * sizeof(int));
  sValidation.isOutArrInplace = 1;
  sValidation.algorithm = BUBBLE_SORT;
  if (unitaryValidation(sValidation))
  {
    printf("   OK - Bubble sort\n");
  }
  else
  {
    printf(" FAIL - Bubble sort\n");
  }

  /* --------------------------------------------- */

  /* II. Search algo's */
  sValidation.isOutArrInplace = 0;
  sValidation.algorithmType = SEARCH_T;

  /* (1) Binary search */
  memset(outArray, 0, LARGE_ARRAY_SIZE * sizeof(int));
  sValidation.algorithm = BINARY_SEARCH;
  if (unitaryValidation(sValidation))
  {
    printf("   OK - Binary search\n");
  }
  else
  {
    printf(" FAIL - Binary search\n");
  }

  /* --------------------------------------------- */

  printf(" -> Validation complete.\n\n");

}

int unitaryValidation(validationState sValidation)
{
  int*  inArray;
  int* outArray;
  int arrSize;

  int* pInArr = NULL;

  inArray  = sValidation.inArray;
  outArray = sValidation.outArray;
  arrSize = sValidation.arraySize;

  int result;

  /* Init */
  if (sValidation.isOutArrInplace)
  {
    VectCopy(inArray, outArray, arrSize);
    pInArr = inArray;   // Save the state of the input buffer to preserve the data
    inArray = outArray; // Swapt the input pointer to point to the output memory location (already allocated)
  }

  int* targetedIndex = NULL;
  int searchesNum = 10;
  int targetValue;
  if (sValidation.algorithmType == SEARCH_T)
  {
    srand(420);
    targetedIndex = generateRandArray(searchesNum, arrSize);
  }

  /* Validation process */
  switch (sValidation.algorithmType)
  {
    case SORT_T:
      switch (sValidation.algorithm)
      {
        case BUBBLE_SORT:
          bubbleSort(inArray, arrSize);
          break;

        default:
            fprintf(stderr, "Invalid algorithm: cannot be validated!");
            exit(-1);
      }
      result = isArraySorted(inArray, arrSize);
      break;

    case SEARCH_T:
      for (int i = 0; i < searchesNum; i++)
      {
        int targetIdx = targetedIndex[i];
        targetValue = inArray[targetIdx];
        int returnValue = 0;

        switch (sValidation.algorithm)
        {
          case BINARY_SEARCH:
            returnValue = binarySearch(inArray, targetValue, 0, arrSize);
            break;

          default:
            fprintf(stderr, "Invalid algorithm: cannot be validated!");
            exit(-1);
        }
        
        if (returnValue != targetValue)
        {
          result = 0;
          break;
        }
      }
      result = 1;
      break;

    case NO_ALGO_T:
    default:
      fprintf(stderr, "Invalid algorithm type: cannot be validated!");
      exit(-1);
  }

  /* Deinit */
  if (sValidation.isOutArrInplace)
  {
    sValidation.inArray = pInArr;
  }

  return result;
}
