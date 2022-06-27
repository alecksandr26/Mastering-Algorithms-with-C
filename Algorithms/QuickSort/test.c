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

/* comapre: my function to compare two values */
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
    int arr[] = {5, 4, 3, 2, 1};
    print_arr(arr, 5);
    printf("%i\n", qksort((void *) arr, 5, sizeof(int), 0, 4, &compare));
    print_arr(arr, 5);
    return 0;
}
