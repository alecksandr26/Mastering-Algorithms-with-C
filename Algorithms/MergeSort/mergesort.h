#ifndef __MERGESORT_H__
#define __MERGESORT_H__


/* mgsort: Return 0 0 if sorting is successful, or –1 otherwise.
   data: The stream of data
   size: The number of elements
   esize: The size in bytes of the elements
   compare: Function to compare the elements
   complexity: Is O(log_2 n * n)
 */
int mgsort(void *data, int size, int esize, int i, int k, int (*compare)
           (const void *key1, const void *key2));





#endif
