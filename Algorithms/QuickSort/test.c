#include <stdio.h>


#include "qsort.h"


void print_arr(int arr[], int size)
{
    int i;

    printf("Arr: ");
    for (i = 0; i < size; ++i)
        printf("%i ", arr[i]);
    printf("\n");
}

/* compare: my function to compare two values */
int compare(const int *int1, const int *int2)
{
    if (*int1 > *int2)
        return 1;
    else if (*int1 == *int2)
        return 0;
    return -1;
}


int main()
{
    int arr[] = {24, 52, 11, 94, 28, 36, 14, 80};
    print_arr(arr, 8);
    printf("%i\n", qksort((void *) arr, 8, sizeof(int), 0, 7, &compare, &print_arr));
    print_arr(arr, 8);
    return 0;
}
