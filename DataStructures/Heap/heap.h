#ifndef __HEAP__H__
#define __HEAP__H__

#include <stdlib.h>
#include <string.h>

/* The data structure */
typedef struct Heap_ {
    int size;
    
    int (*compare) (const void *key1, const void *key2);
    void (*destroy) (void *data);

    void **tree;
} Heap;

/* heap_init: Initializes the heap specified by heap. 
   head: The data structure
   compare: This function should return 1 if key1 > key2,
            0 if key1 = key2, and –1 if key1 < key2 for a top-heavy heap.
   destroy: To destroy the data structure
   complexity: Is O(1)
 */
void heap_init (Heap *heap, int (*compare)(const void *key1, const void *key2),
               void (*destroy)(void *data));

/* heap_destroy: destroy everything
   heap: The data structure
   complexity: Is O(n) where n is the number of nodes
 */
void heap_destroy (Heap *heap);


/* heap_insert: To insert a new node to the heap
   heap: Is the data structure
   data: The data to insert
   complexity: Is O(logN) where N is the number o nodes 
 */
int heap_insert (Heap *heap, const void *data);


/* heap_extract: To dump the root value
   heap: Is the data structure
   data: The pointer to allocate the result
   complexity: Is O(logN) where N is the number of nodes
 */
int heap_extract (Heap *heap, void **data);


/* heap_size: Return the number of
   heap: Is the data structure
   complexity: Is O(1)
 */
#define heap_size(heap) ((heap)->size)

#endif







