
#ifndef __LINKED_LIST_H_
#define __LINKED_LIST_H_

#include <stdio.h>
#include <stdlib.h>

/* This is the node structrue will contain the data */
typedef struct ListElemt_ {
	void *data;
	struct ListElemt *next;
} ListElemt;


/* This is the list structure that will manage all the list */
typedef struct List_ {
	int size;
	int (*math) (const void *key1, const void *key2);
	void (*destroy) (const void *data);
} List;


/* These all the methods */

/* list_init: Will initlize the list this must be the first function to execute to be able
 * to execute more functions 
 * list: receive a list object
 * destroy: We need to receive a fucntion that destroy one element inside of the array 
*/
void list_init (List *list, void (*destroy)(void *data));

/* list_destroy: This function will delete all structure after execute this function 
 * no other operations with the structre is going to be permited.
 * list: Its your list object 
*/
void list_destroy (List *list);

/* list_ins_next: This function will insert a new element from another element
 * runtime complexity of this operation is O(1).
 * list: Is the structure object.
 * elem: This is the element that we want to have previos
 * data: Is your data that you want to save inside of the element.
 */
int list_ins_next (List *list, ListElemt *elem, const void *data);





#endif



