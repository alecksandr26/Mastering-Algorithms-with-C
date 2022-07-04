#include <stdio.h>
#include "./csort.h"


int main()
{
    int arr[] = {10, 6, 7, 8, 1}, i;

    ctsort(arr, 5, 10);

    for (i = 0; i < 5; ++i)
        printf("%i ", arr[i]);
    
    puts("");
    
    return 0;
}





