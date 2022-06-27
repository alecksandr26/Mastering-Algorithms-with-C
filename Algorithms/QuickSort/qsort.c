#include <stdlib.h>
#include <string.h>


#include "qsort.h"




/* qsort: Return 0 if sorting is successful, or -1 otherwise
 * data: The pointer to the set of data
 * size: Is the size of the data
 * esize: Is the size of each element
 * i: k: The arguments i and k define the current partition being sorted and initially should be 0 and size – 1.
 * compare: The function pointer compare specifies a user-defined function to compare elements. It should per- form in a manner similar to that described for issort.
 * complexity: Is O(logN * N) where N is the number of elements
 */
int qsort(void *data, int size, int esize, int i, int k, int (*compare)
           (const void *key1, const void *key2))
{
    return 0;
}



