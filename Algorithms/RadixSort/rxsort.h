#ifndef __RADIX_SORT_H__
#define __RADIX_SORT_H__



/* rxsort: Return 0 if sorting is successful, or -1 ortherwise
   data: Is the pointer to the data
   size: The amount of data
   complexity: Is O(pn + pk) where n is the number of elements, k is the radix, and p is the number of digit position
 */
int rxsort(int *data, int size, int p, int k);




#endif



