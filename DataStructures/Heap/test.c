/* Lets test this library */
#include <stdio.h>

#include "heap.h"


/* compare: This function should return 1 if key1 > key2, 0 if
   key1 = key2, and –1 if key1 < key2 for a top-heavy heap.  */
int compare(int *key1, int *key2)
{
    if (*key1 > *key2)
        return 1;
    
    else if (*key1 == *key2)
        return 0;
    
    return -1;
}


/* destroy: To destroy a piece of data */
void destroy(int *key1)
{
    /* Do nothing */
}



int main()
{
    Heap myheap;
    int nums[] = {6, 0, 5, -1, -2, 1, 3};
    int *ptr;

    heap_init(&myheap, &compare, &destroy);

    
    heap_insert(&myheap, nums + 1);
    heap_insert(&myheap, nums + 2);
    heap_insert(&myheap, nums);

    heap_extract(&myheap, &ptr);
    printf("%i\n", *ptr);
    heap_insert(&myheap, nums + 3);
    heap_insert(&myheap, nums + 4);
    heap_insert(&myheap, nums + 6);
    
    heap_extract(&myheap, &ptr);
    printf("%i\n", *ptr);
    
    heap_extract(&myheap, &ptr);
    printf("%i\n", *ptr);
    
    
    
    return 0;
}



