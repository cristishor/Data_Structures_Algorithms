
/* Self-contained header file for timing a (set of) function(s). */
/* !!! WINDOWS ONLY !!! */

#ifndef H_RUNTIME_RUNTIME
#define H_RUNTIME_RUNTIME

#include <windows.h> // Windows platform only!
#include "utils.h"

static inline void startClock(const char functionName[MAX_CHAR_STRING]);
static inline void stopClock();

static LARGE_INTEGER StartingTime, EndingTime, ElapsedMicroseconds;
static LARGE_INTEGER Frequency;

static inline void startClock(const char functionName[MAX_CHAR_STRING])
{
  if (!QueryPerformanceFrequency(&Frequency)) {
    fprintf(stderr, "High-resolution performance counter not supported.\n");
    exit(-1);
  }

  if (functionName != NULL)
  {
    printf("Measuring \"%s\" ... ", functionName);
  }

  QueryPerformanceFrequency(&Frequency);
  QueryPerformanceCounter(&StartingTime);
}

static inline void stopClock()
{
  QueryPerformanceCounter(&EndingTime);
  ElapsedMicroseconds.QuadPart = EndingTime.QuadPart - StartingTime.QuadPart;

  ElapsedMicroseconds.QuadPart *= 1000000;
  ElapsedMicroseconds.QuadPart /= Frequency.QuadPart;

  double s = (double)ElapsedMicroseconds.QuadPart / 1000000.0;

  printf("Elapsed time: %.6f seconds\n", s);
}

#endif // !H_RUNTIME_RUNTIME
