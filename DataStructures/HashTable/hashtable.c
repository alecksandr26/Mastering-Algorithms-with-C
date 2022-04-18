
#include "./hashtable.h"


/* chtbl_init: Initialize the chained hashtable
   h: Is the hash function that we need to create
   match: A function that we use to match keys
   destroy: To destroy the content data
   complexity: O(m) where m is the number of buckets that we want to have 
 */
int chtbl_init (CHTbl *htbl, int buckets, int (*h)(const void *key),
                int (*match)(const void *key1, const void *key2),
                void (*destroy)(void *data))
{
    int i;

    /* Allocate the array of lists memory */
    if ((htbl->table = (List *) malloc(buckets * sizeof(List))) == NULL)
        return -1;

    /* Initialize the buckets */
    htbl->buckets = buckets;
    for (i = 0; i < htbl->buckets; i++)
        list_init(&htbl->table[i], destroy);

    /* Encapsulate the functions */
    htbl->h = h;
    htbl->match = match;
    htbl->destroy = destroy;
    
    htbl->size = 0;
    
    return 0;
}

/* chtbl_destroy: To destroy the complete structure
   htbl: Is the structure
   complexity: Is O(n) where n is amount of buckets inside of the array
 */
void chtbl_destroy (CHTbl *htbl)
{
    int i;

    /* Basically what we doo is destroy each bucket */
    for (i = 0; i < htbl->buckets; i++)
        list_destroy(&htbl->table[i]);

    /* Basically here we free the memory */
    free(htbl->table);

    /* Here we set all the memory in zero */
    memset(htbl, 0, sizeof(CHTbl));
}



/* chtbl_insert: To insert an element into the chained hashtable
   htbl: Is the structure
   data: Is the data that we have inside of the structure
   complexity: O(1) Because it is a hash table
 */
int chtbl_insert (CHTbl *htbl, const void *data)
{
    void *temp;

    int bucket, retval;

    /* Do nothing if the data is already into the table */
    temp = (void *) data;
    if (chtbl_lookup(htbl, &temp) == 0)
        return 1;

    /* If the data isn't in the table */
    bucket = htbl->h(data) % htbl->buckets;

    /* Insert the element */
    if ((retval = list_ins_next(&htbl->table[bucket], NULL, data)) == 0)
        htbl->size++;

    return retval;
}



/* chtbl_remove: To remove the element matching "data" from the
   chained hashtable specified by htbl
   htbl: Is the data structure
   data: Is the pointer that will points to our data
   complexity: Is O(1) because again is a hash table
 */
int chtbl_remove (CHTbl *htbl, void **data)
{
    ListElemt *element, *prev;

    int bucket;

    /* Hash the data we use the data as a key */
    bucket = htbl->h(*data) % htbl->buckets;

    prev = NULL;

    /* Iterates on all the chained bucket */
    for (element = list_head(&htbl->table[bucket]); element != NULL;
         element = list_next(element)) {
        /* Try to find the data that matches */
        if (htbl->match(*data, list_data(element))) {
            /* remove it */
            if (list_rem_next(&htbl->table[bucket], prev, data) == 0) {
                htbl->size--;
                return 0;
            } else /* If something comes wrong */
                return -1;
        }
        prev = element;
    }

    /* Return that the data was not found */
    return -1;
}




/* chtbl_lookup: Determines wheter an element matches data in the
   chained hash table specified by htbl
   htbl: Is the structure
   data: Is where the data will get stored if match
   complexity: Is O(1)
 */
int chtbl_lookup (const CHTbl *htbl, void **data)
{
    ListElemt *element;
    int bucket;

    /* Here we execute our hash function */
    bucket = htbl->h(*data) % htbl->buckets;

    /* Iterate on all the buckets until we find the data that matchs */
    for (element = list_head(&htbl->table[bucket]); element != NULL; element = list_next(element)) {
        /* Return zero if something matches */
        if (htbl->match(*data, list_data(element))) {
            *data = list_data(element);
            return 0;
        }
    }

    return -1;
}


