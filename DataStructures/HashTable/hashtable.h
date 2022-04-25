
#ifndef CHTBL_H
#define CHTBL_H

#include <stdlib.h>
#include <strings.h>

/* We are going to use our linkedlist */
#include "../LinkedList/linkedlist.h"

typedef struct CHTbl_ {
    int buckets;
    int (*h)(const void *key);
    int (*match) (const void *key1, const void *key2);
    void (*destroy) (void *data);
    int size;
    List *table;
} CHTbl;

/* chtbl_init: Initialize the chained hashtable
   h: Is the hash function that we need to create
   match: A function that we use to match keys
   destroy: To destroy the content data
   complexity: O(m) where m is the number of buckets that we want to have
 */
int chtbl_init (CHTbl *htbl, int buckets, int (*h)(const void *key),
                int (*match)(const void *key1, const void *key2),
                void (*destroy)(void *data));


/* chtbl_destroy: To destroy the complete structure
   htbl: Is the structure
   complexity: Is O(n) where n is amount of buckets inside of the array
 */
void chtbl_destroy (CHTbl *htbl);


/* chtbl_insert: To insert an element into the chained hashtable
   htbl: Is the structure
   data: Is the data that we have inside of the structure
   complexity: O(1) Because it is a hash table
 */
int chtbl_insert (CHTbl *htbl, const void *data);


/* chtbl_remove: To remove the element matching "data" from the
   chained hashtable specified by htbl
   htbl: Is the data structure
   data: Is the pointer that will points to our data
   complexity: Is O(1) because again is a hash table
 */
int chtbl_remove (CHTbl *htbl, void **data);


/* chtbl_lookup: Determines wheter an element matches data in the
   chained hash table specified by htbl
   htbl: Is the structure
   data: Is where the data will get stored if match
   complexity: Is O(1)
 */
int chtbl_lookup (const CHTbl *htbl, void **data);


/* chtbl_size: simple returns the number of elements in the chained hash
   table specified by htbl
   htbl: Is the structure
   complexity: Is O(1)
 */
#define chtbl_size(htbl) ((htbl)->size)

#endif
