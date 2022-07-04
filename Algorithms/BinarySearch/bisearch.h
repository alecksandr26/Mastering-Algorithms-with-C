#ifndef __BISEARCH_H__
#define __BISEARCH_H__


/* bisearch: Return 0 if successful, or -1 otherwise
   sorted: A sorted array of data
   target: The element that we want to find
   size: The number of elements
   esize: Element size
   compare: To compare elements
   complexity: Is O(logn) where n is the number of elements
 */
int bisearch(void *sorted, void *target, int size, int esize,
             int (*compare)(const void *key1, const void *key2));





#endif
