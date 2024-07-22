#ifndef H_VECT_COPY
#define H_VECT_COPY

static inline void VectCopy(const int* pSrc, int* pDst, int size);

static inline void VectCopy
(
  const int* pSrc,
  int* pDst,
  int size
)
{
  int ii;
  for (ii = 0; ii < size; ii++)
  {
    *pDst++ = *pSrc++;
  }
}

#endif // !H_VECT_COPY
