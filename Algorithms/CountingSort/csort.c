#include <stdlib.h>
#include <string.h>


/* ctsort: return 0 if sorting is successful, or -1 otherwise
   data: Stream of data
   size: The size of elements
   k: k is the maximun number 
   complexity: is O(n + k) where n is the number of elements and k is the maximun number inside of the set
 */
int ctsort(int *data, int size, int k)
{
    int *counts, *temp;
    int i, j;


    if ((counts = (int *) malloc(k * sizeof(int))) == NULL)
        return -1;
    
    if ((temp = (int *) malloc(size * sizeof(int))) == NULL) {
        free(counts);
        return -1;
    }


    /* Init the counts */
    for (i = 0; i < k; i++)
        counts[i] = 0;


    /* Count all the numbers */
    for (j = 0; j < size; j++)
        counts[data[j] - 1]++;

    /* Sum the previous */    
    for (i = 1; i < k; i++)
        counts[i] += counts[i - 1];


    /* And then sort */
    for (j = size - 1; j > -1; j--) {
        temp[counts[data[j] - 1] - 1] = data[j];
        counts[data[j] - 1]--;
    }
    
    /* copy the memory */
    memcpy(data, temp, size * sizeof(int));
    
    free(counts);
    free(temp);
    
    return 0;
}






