#include <stdlib.h>
#include <string.h>

#include "bisearch.h"


/* bisearch: Return index if target the found, or -1 otherwise
   sorted: A sorted array of data
   target: The element that we want to find
   size: The number of elements
   esize: Element size
   compare: To compare elements
   complexity: Is O(logn) where n is the number of elements
 */
int bisearch(void *sorted, void *target, int size, int esize,
             int (*compare)(const void *key1, const void *key2))
{
    int left, middle, right;

    left = 0;
    right = size - 1;
    while (left <= right) {
        middle = (left + right) / 2;
        switch (compare((char *) sorted + (esize * middle), target)) {
        case -1:
            left = middle - 1;
            break;
        case 0:
            return middle;
        }
    }
    return -1;
}





