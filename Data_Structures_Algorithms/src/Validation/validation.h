#ifndef H_VALIDATION
#define VALIDATION

#include "../../include/utils.h"

extern void algorithmValidation();

typedef enum algorithmType {
  NO_ALGO_T = 0,
  SORT_T,
  SEARCH_T,

  ALGO_TYPE_COUNT
}algorithmType;

typedef enum algorithmEnum {
  BINARY_SEARCH,

  BUBBLE_SORT,

  ALGORITHM_COUNT
}algorithmEnum;

typedef struct validationState {
  int* inArray;
  int* outArray;
  int arraySize;
  int isOutArrInplace;

  int algorithm;
  int algorithmType;
} validationState;

#endif // !H_VALIDATION
