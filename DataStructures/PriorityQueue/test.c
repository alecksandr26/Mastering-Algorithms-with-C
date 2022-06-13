#include <stdio.h>

#include "pqueue.h"


/* compare: To compare the keys */
int compare(int *key1, int *key2)
{
    if (*key1 > *key2)
        return 1;
    else if (*key1 == *key2)
        return 0;

    return -1;
}


void destroy(int *key1)
{
    // nothing
}


int main()
{
    PQueue pq;
    
    pqueue_init(&pq, &compare, &destroy);
    
    
    return 0;
}

