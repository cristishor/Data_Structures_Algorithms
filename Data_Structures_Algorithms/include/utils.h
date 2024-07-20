
/* Main header file for hosting cross-header defines, includes and other useful settings. */

#ifndef H_DSA_UTILS
#define H_DSA_UTILS

#include <stdio.h>
#include <stdlib.h>

/*
*/
/* -+-+-+-+-+-+-+-+-+-+-+-+-+- DEFINES -+-+-+-+-+-+-+-+-+-+-+-+-+- */

/* Maximum possible (agreed) array size - used for memory allocation */
#define MAX_ARRAY_SIZE 0x7FFF /* 32,767 */

/* Maximum possible integer value of an array element (to be sorted) */
#define DECENTLY_SIZED_MAX_RAND_VAL 0x7FFF /* 32s,767 */

/* Various pre-defined array sizes */
#define SMALL_ARRAY_SIZE 100
#define   MID_ARRAY_SIZE 1000
#define LARGE_ARRAY_SIZE 10000

/* Maximum size of a character string */
#define MAX_CHAR_STRING 255

/*
*/
/* -+-+-+-+-+-+-+-+-+-+-+-+-+-  MACROS  -+-+-+-+-+-+-+-+-+-+-+-+-+- */

#define NEW_LINE() printf("\n")
#define END_OF_EXECUTION() \
    do { \
        printf("\n------------------------------------------------\n                  End of execution.\n------------------------------------------------\n\n"); \
        exit(0); \
    } while (0)

#endif // !H_DSA_UTILS
