#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "rxsort.h"


/* rxsort: Return 0 if sorting is successful, or -1 ortherwise
   data: Is the pointer to the data
   size: The amount of data
   complexity: Is O(pn + pk) where n is the number of elements, k is the radix, and p is the number of digit position
 */
int rxsort(int *data, int size, int p, int k)
{
    int *counts, *temp;
    int index, pval, i, j, n;

    /* Alloc memory for the counts */
    if ((counts = (int *) malloc(k * sizeof(int))) == NULL)
        return -1;


    /* Alloc the memory of the temp */
    if ((temp = (int *)malloc(size * sizeof(int))) == NULL)
        return -1;


    /* Sort from the least significant position to the most significant */
    for (n = 0; n < p; n++) {
        for (i = 0; i < k; i++)
            counts[i] = 0;
        
        /* Calculate the position value */
        pval = (int) pow((double) k, (double) n);

        /* Calculate the occurrences of each digit value */
        for (j = 0; j < size; j++) {
            index = (int) (data[j] / pval) % k;
            counts[index]++;
        }

        /* Adjust each count */
        for (i = 1; i < k; i++)
            counts[i] += index[i - 1];

        /* Sort the array */
        for (j = size - 1; j >= 0; j--) {
            index = (int)(data[j] / pval) % k;
            temp[counts[index] - 1] = data[j];
            counts[index] = counts[index] - 1;
        }

        /* Copy and paste the memory sorted */
        memcpy(data, temp, size * sizeof(int));
    }

    free(counts);
    free(temp);

    return 0;
}
