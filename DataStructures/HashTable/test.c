#include <stdio.h>
#include <stdlib.h>

#include "./hashtable.h"

/* Here we need to declare our functions for the hash table */
int hash (const int *key)
{
    int sum, i;
    unsigned char *temp = key;

    for (i = 0; i < 4; ++i)
        sum += *(temp + i);

    return sum;
}

/* To find that it match */
int match (const int *key1, const int *key2)
{
    return *key1 == *key2;
}

/* To destroy */
void destroy (int *data)
{
    free(data);
}


int main ()
{
    CHTbl ht;

    chtbl_init(&ht, 100, &hash, &match, &destroy);

    int *ptr;
    int d = 1;
    int d2 = 2;
    int d3 = 3;

    /* To test remove */
    int dr = 1;
    ptr = &dr;

    chtbl_insert(&ht, &d);
    chtbl_insert(&ht, &d2);
    chtbl_insert(&ht, &d3);
    
    chtbl_remove(&ht, &ptr);
    printf("%i\n", *ptr);

    *ptr = 0;
    if (chtbl_lookup(&ht, &ptr) != -1)
        puts("It is in the table");
    else
        puts("It is not in the table");

    printf("%i\n", *ptr);
    
    return 0;
}

