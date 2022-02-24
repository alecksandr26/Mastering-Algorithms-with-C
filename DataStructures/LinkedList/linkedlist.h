#ifndef __LINKED_LIST_H_
#define __LINKED_LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This is the node structrue will contain the data */
typedef struct ListElemt_ {
	void *data;
	struct ListElemt_ *next;
} ListElemt;


/* This is the list structure that will manage all the list */
typedef struct List_ {
	int size;
	int (*math) (const void *key1, const void *key2);
	void (*destroy) (void *data);
	ListElemt *head;
	ListElemt *tail;
} List;


/* These all the methods */

/* list_init: Will initlize the list this must be the first function to execute to be able
 * to execute more functions 
 * list: receive a list object
 * destroy: We need to receive a fucntion that destroy one element inside of the array 
*/
void list_init (List *list, void (*destroy)(void *data));

/* list_destroy: This function will delete all structure after execute this function 
 * no other operations with the structre is going to be permited the runtime is O(n).
 * list: Its your list object 
*/
void list_destroy (List *list);

/* list_ins_next: This function will insert a new element from another element
 * runtime complexity of this operation is O(1), if it returns "0" is else something comes wrong.
 * list: Is the structure object.
 * elem: This is the element that we want to have previos
 * data: Is the data to we are going to have after the selected element
*/
int list_ins_next (List *list, ListElemt *elem, const void *data);

/* list_rem_next: It goins to remove the next element from an element from the list
 * the runtime complexity is O(1), also returns "0" if everything done well.
 * list: The list structure
 * elem: Is the element from where we are going to delete the next it
 * data: To catch the pointer from where the data is stored 
*/
int list_rem_next (List *list, ListElemt *elem, void **data);

/* list_size: Is just a function that returns the size of the list 
 * list: The structure of the list 
*/
#define list_size(list) ((list)->size)

/* list_head: Is going to return the head element from the list 
 * list: Is the structure of the list 
*/
#define list_head(list) ((list)->head)

/* list_tail: It going to return the tail from the list 
 * list: Is the list structure 
*/
#define list_tail(list) ((list)->tail)

/* list_is_head: It going to return "0" if the element send it is the head else 
 * return other thing
 * elem: Is the element 
*/
#define list_is_head(list, element) ((element) == (list)->head ? 1 : 0)

/* list_is_tail: return "0" if is the tail else return another thing */
#define list_is_tail(element) ((element)->next == NULL ? 1 : 0)

/* list_data: will return the data contents in a element it has a runtime 
 * complexity O(1).
 * elem: The element that we want to extract its data
*/
#define list_data(element) ((element)->data)

/* list_next: It returns the next element from given one, the runtime 
 * complexity is O(1).
 * elem: Is the element 
*/
#define list_next(element) ((element)->next)

#endif
