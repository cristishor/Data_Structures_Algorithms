
/* Self-contained header file for generating heap allocated random value arrays. */

#ifndef H_ARRAY_GENERATOR
#define H_ARRAY_GENERATOR

#include "utils.h"

//  ┌--┌- What you came for -┐─-┐
//  |  |  |  |   |  |  |  |  |  |
//  ↓  ↓  ↓  ↓   ↓  ↓  ↓  ↓  ↓  ↓

static inline int* generateRandArray(int length, int maxRandVal);

/* Default array generation to 10,000 elements. */
#define GENERATE_ARRAY() generateRandArray(LARGE_ARRAY_SIZE, DECENTLY_SIZED_MAX_RAND_VAL)

#define GENERATE_ARRAY_SIZE(size) generateRandArray(size, DECENTLY_SIZED_MAX_RAND_VAL)

// ↑  ↑  ↑  ↑  ↑   ↑  ↑  ↑  ↑  ↑  ↑  ↑  ↑  ↑  ↑
// |  |  |  |  |   |  |  |  |  |  |  |  |  |  |
// └──└─ What you came for ─┘─-┘─-┘─-┘─-┘─-┘─-┘

/* -+-+-+-+-+-+-+-+-+- Implementation -+-+-+-+-+-+-+-+-+- */

static inline int* generateRandArray(
  int   length,
  int   maxRandVal
)
{
  int* array;
  int i, rdm;
  int lower, upper;
  lower = 1;
  upper = maxRandVal;

  array = (int*)malloc(MAX_ARRAY_SIZE * sizeof(int));
  if (array == NULL)
  {
    fprintf(stderr, "Memory allication failed.\n");
    exit(-1);
  }

  for (i = 0; i < length; i++)
  {
    rdm = (rand() % (upper - lower + 1)) + lower;
    array[i] = rdm;
  }

  return array;
}

#endif // !H_ARRAY_GENERATOR
