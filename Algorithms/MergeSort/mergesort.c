#include <stdlib.h>
#include <string.h>
#include "./mergesort.h"


/* merge: Simple function to merge */
static int merge(void *data, int esize, int i, int j, int k, int (*compare)
                 (const void *key1, const void *key2))
{
    char *a, *m;
    int ipos, jpos, mpos;

    a = data;

    /* Our iterators */
    ipos = i;
    jpos = j + 1;
    mpos = 0;
    
    /* alloc temp memory */
    if ((m = (char *) malloc(esize *((k - i) + 1))) == NULL)
        return - 1;

    /* Merge */
    while (ipos <= j || jpos <= k) {
        /* The remaining  numbers */
        if (ipos > j) {
            while (jpos <= k) {
                memcpy(&m[mpos * esize], &a[jpos * esize], esize);
                jpos++;
                mpos++;
            }
            continue;
        }
        else if (jpos > k) {
            while (ipos <= i) {
                memcpy(&m[mpos * esize], &a[ipos * esize], esize);
                ipos++;
                mpos++;
            }
            continue;
        }

        /* Merge the elements */
        if (compare(&a[ipos * esize], &a[jpos * esize]) < 0) {
            memcpy(&m[mpos * esize], &a[ipos * esize], esize);
            ipos++;
            mpos++;
        } else {
            memcpy(&m[mpos * esize], &a[jpos * esize], esize);
            jpos++;
            mpos++;
        }
    }

    /* Paste the memory */
    memcpy(&a[i * esize], m, esize  * ((k - i) + 1));
    
    free(m);

    return 0;
}



/* mgsort: Return 0 0 if sorting is successful, or –1 otherwise.
   data: The stream of data
   size: The number of elements
   esize: The size in bytes of the elements
   compare: Function to compare the elements
   complexity: Is O(log_2 n * n)
 */
int mgsort(void *data, int size, int esize, int i, int k, int (*compare)
           (const void *key1, const void *key2))
{
    int j;
    if (i < k) {
        /* divide in two */
        j = (int) ((i + k - 1) / 2);

        /* Recursive sort the two divisions */
        if (mgsort(data, size, esize, i, j, compare) < 0)
            return -1;
        
        if (mgsort(data, size, esize, j + 1, k, compare) < 0)
            return -1;

        /* After merge the two pieces */
        if (merge(data, esize, i, j, k, compare) < 0)
            return -1;
    }
    return 0;
}







