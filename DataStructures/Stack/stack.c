#include "./stack.h"

/* Its importnat to include the linkedlist.c file to compile this program!!! */

/* stack_push: To push data into the data structure 
 * stack: The data structure that we were using
 * data: The data that we want to stack
 * complexity: Is O(1)
*/
int stack_push (Stack *stack, const void *data)
{
	return list_ins_next(stack, NULL, data);
}

/* stack_pop: To get back some data removing it from the stack returns 1 if everything is okay
 * stack: The data structure that we are using
 * data: This is were we are going to catch the pointer to the removed data
 * complexity: is O(1)
*/
int stack_pop (Stack *stack, void **data)
{
	return list_rem_next(stack, NULL, data);
}
