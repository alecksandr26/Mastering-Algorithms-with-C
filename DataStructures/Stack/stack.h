#ifndef __STACK_H_
#define __STACK_H_

#include <stdlib.h>
#include <string.h>

/* In simple view an stack is a linked list so here I include the list header */
#include "../LinkedList/linkedlist.h"

/* And here I declare my stack */
typedef List Stack;

/* stack_init: To initializes the the data structure
 * stack: Is the stack that we are using 
 * destroy: Is the function that we are going to use to destroy the data
 * complexity: O(1)
*/
#define stack_init list_init

/* stack_destroy: To destroy the data structure 
 * stack: The data structure that we are using 
 * complexity: Is O(n) where n is the amount of elements in the stack
*/
#define stack_destroy list_destroy

/* stack_push: To push data into the data structure returns 1 if everything is okay
 * stack: The data structure that we were using
 * data: The data that we want to stack
 * complexity: Is O(1)
*/
int stack_push (Stack *stack, const void *data);

/* stack_pop: To get back some data removing it from the stack returns 1 if everything is okay
 * stack: The data structure that we are using
 * data: This is were we are going to catch the pointer to the removed data
 * complexity: is O(1)
*/
int stack_pop (Stack *stack, void **data);

/* stack_peek: It is going to return the top element from the data structure 
 * stack: The data structure that we were using
 * complexity: O(1)
*/
#define stack_peek(stack) ((stack)->head == NULL ? NULL : (stack)->head->data)

/* stack_size: It is going to return the size of the stack 
 * stack: Is the data structure 
 * complexity: Is O(1)
*/
#define stack_size list_size



#endif
