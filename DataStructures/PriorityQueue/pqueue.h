#ifndef __PRIORITY_QUEUE_H__
#define __PRIORITY_QUEUE_H__

/* this object uses the heap file */
#include "../Heap/heap.h"


typedef Heap PQueue;

/* pqueue_init:
   pqeue: Is the data structure
   compare: To compare the data this function should
   return 1 if key1 > key2, 0 if key1 = key2, and –1 if key1 < key2
   destroy: To destroy the objects 
   complexity: Is O(1)
 */
#define pqueue_init heap_init

/* pqueue_destroy:
   pqueue: The data structure
   complexity: Is O(n) where n is the number of elements
 */
#define pqueue_destroy heap_destroy



/* pqueue_insert:
   pqueue: The data structure
   data: Is the data to insert
   complexity: Is O(lg n) where n is the number of elements
 */
#define pqueue_insert heap_insert



/* ppqueue_extra: To 
   pqueue: Is the data structure
   data: A pointer to point to the data
   complexity: Is O(lg n) where n is the number of elements
 */
#define pqueue_extract heap_extract



/* pqueue_peek: To get the top node or elements
   pqueue: The data structure 
   complexity: Is O(1) 
 */
#define pqueue_peek(pqueue) ((pqueue)->tree == NULL ? NULL : (pqueue)->tree[0])


/* pqueue_size: To return the size of the queue
   pqueue: Is the data structure
   complexity: Is O(1)
 */
#define pqueue_size heap_size


#endif
