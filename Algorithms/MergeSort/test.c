#include <stdio.h>
#include "./mergesort.h"

/* compare */
int compare(const int *key1, const int *key2)
{
    if (*key1 > *key2)
        return 1;
    else if (*key1 == *key2)
        return 0;
    return -1;
}




int main()
{
    int arr[] = {5, 4, 3, 2, 1}, i;

    mgsort(arr, 5, sizeof(int), 0, 5, &compare);


    for (i = 0; i < 5; ++i)
		printf("%i ", arr[i]);
	
	puts("");
    
    
    return 0;
}


