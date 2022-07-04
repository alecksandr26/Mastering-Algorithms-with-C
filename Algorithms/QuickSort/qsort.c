#include <stdlib.h>
#include <string.h>


#include "qsort.h"

/* Include the issort */
#include "../InsertionSort/insertionsort.h"



/* compare_int: Used by the meian of three method */
static int compare_int(const void *int1, const void *int2)
{
    if (*(const int *) int1 > *(const int *) int2)
        return 1;
    
    else if (*(const int *) int1 < *(const int *) int2)
        return -1;
    
    return 0;
}



/* Create the partition and divide the data in two parts */
static int partition(void *data, int esize, int i, int k, int (*compare)
                     (const void *key1, const void *key2))
{
    char *a = data;
    void *pval, *temp;
    int r[3];


    /* Allocate the memory to the pivot val */
    if ((pval = malloc(esize)) == NULL)
        return -1;

    if ((temp = malloc(esize)) == NULL) {
        free(pval);
        return -1;
    }

    /* use the median of three method  to find the partition value */
    r[0] = (rand() % (k - i + 1)) + i;
    r[1] = (rand() % (k - i + 1)) + i;
    r[2] = (rand() % (k - i + 1)) + i;

    /* Get a pivot */
    inssort(r, 3, sizeof(int), &compare_int);
    memcpy(pval, &a[r[1] * esize], esize);
    printf("%i\n", *(int *) pval);
    /* create two partition around the partition value */
    i--;
    k++;

    while (1) {
        do { /* move to the left until an element is found in the wrong partition */
            k--;
        } while (compare(&a[k * esize], pval) > 0);
        

        do { /* move to the right until an element is found in the wrong partition */
            i++;
        } while (compare(&a[i * esize], pval) < 0);
        
        if (i >= k) /* stop when it gets cross */
            break;

        /* swap the elements */
        memcpy(temp, &a[i * esize], esize);
        memcpy(&a[i * esize], &a[k * esize], esize);
        memcpy(&a[k * esize], temp, esize);
    }

    free(pval);
    free(temp);

    return k;
}


/* qksort: Return 0 if sorting is successful, or -1 otherwise
 * data: The pointer to the set of data
 * size: Is the size of the data
 * esize: Is the size of each element
 * i: k: The arguments i and k define the current partition being sorted and initially should be 0 and size – 1.
 * compare: The function pointer compare specifies a user-defined function to compare elements. It should per- form in a manner similar to that described for issort.
 * complexity: Is O(logN * N) where N is the number of elements
 */
int qksort(void *data, int size, int esize, int i, int k, int (*compare)
           (const void *key1, const void *key2), void (*print_arr)(int arr[], int size))
{
    int j;

    while (i < k) {
        print_arr((int *) data, size);
        /* Selected the pivot and partition the list */
        if ((j = partition(data, esize, i, k,  compare)) < 0)
            return -1;
        if (qksort(data, size, esize, i, j, compare, print_arr) < 0)
            return -1;
        i = j + 1;
    }

    return 0;
}
