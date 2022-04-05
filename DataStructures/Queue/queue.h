#ifndef __QUEUE_H_
#define __QUEUE_H_

#include <stdlib.h>
#include "../LinkedList/linkedlist.h"

typedef List Queue;

/* queue_init: To initialize a queue
 * queue: The struct of queue
 * destroy: The destroy function to delete the contained data from the nodes 
 * complexity: Is O(1)
*/
#define queue_init list_init

/* queue_destroy: To destroy a complete queue 
 * queue: The queue to destroy
 * complexity: Is O(n) where n is the amount of elements contained by the stack
*/
#define queue_destroy list_destroy

/* queue_enqueue: To enque a node to the queue
 * return 0 for successfully enque -1 for unseccessfully enque
 * queue: The queue struct that we were using
 * data: The data that we want to enque
 * complexity: Is O(1)
*/
int queue_enqueue (Queue *queue, const void *data);

/* queue_dequeue: To remove one node from the queue
 * return 0 for successfully dequeue operation -1 for unseccessfully dequeue
 * queue: The struct of queue
 * data: The pointer which is going to point to the dequeued data 
 * complexity: Is O(1)
*/
int queue_dequeue (Queue *queue, void **data);

/* queue_peek: To get the current data from the first element 
 * return the data from the first element
 * queue: The queue that we are using
 * complexity: Is O(1)
*/
#define queue_peek(queue) ((queue)->head == NULL ? NULL : (queue)->head->data)

/* queue_size: Return the amount of elements that we have inside of the queue 
 * return the amount of elements in the queue
 * queue: The queue that we are using
 * complexity: Is O(1)
 */
#define queue_size list_size

#endif 
