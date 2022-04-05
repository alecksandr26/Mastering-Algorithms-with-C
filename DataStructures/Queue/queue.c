#include "./queue.h"


/* queue_enqueue: To enque a node to the queue
 * return 0 for successfully enque -1 for unseccessfully enque
 * queue: The queue struct that we were using
 * data: The data that we want to enque
 * complexity: Is O(1)
*/
int queue_enqueue (Queue *queue, const void *data)
{
	return list_ins_next(queue, list_tail(queue), data);
}

/* queue_dequeue: To remove one node from the queue
 * return 0 for successfully dequeue operation -1 for unseccessfully dequeue
 * queue: The struct of queue
 * data: The pointer which is going to point to the dequeued data 
 * complexity: Is O(1)
*/
int queue_dequeue (Queue *queue, void **data)
{
	return list_rem_next(queue, NULL, data);
}
