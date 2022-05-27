#include <stdio.h>
#include "./bistree.h"


int compare (int *key1, int *key2)
{
    return *key1 == *key2;
}


void destroy (int *num)
{
    /* destroy the data */
}


/* testing the avl tree */
int main ()
{
    BisTree mytree;
    int n;
    
    
    bistree_init(&mytree, &compare, &destroy);

    n = 1;
    bistree_insert(&mytree, &n);
    
    
    return 0;
}


