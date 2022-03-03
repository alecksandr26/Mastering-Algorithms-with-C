#ifndef __DOUBLY_LINKED_LIST_H_
#define __DOUBLY_LINKED_LIST_H_

#include <stdlib.h>
#include <string.h>

/* This is a simple node */
typedef struct DListElmt_ {
	
	/* The data that we were saving */
	void *data;
	
	/* The pointerts of the previous node and the next node */
	struct DListElmt_ *next;
	struct DListElmt_ *prev;
} DListElmt;

/* This is the structure which is going to handle all the doubly linked list */
typedef struct DList_ {
	int size;
	DListElmt *head;
	DListElmt *tail;
	
	/* match: Is the function to know if key1 is equal to key2 */
	int (*match) (const void *key1, const void *key2);
	void (*destroy) (void *data);
} DList;

/* dlist_init: Here we initialize my list and also I pass the function to destroy my objects 
 * list: Is the struct that deals with the linked nodes of data 
 * destroy: Is the function that is going to free the information that we were saving
 * complexity: Is O(1)
*/
void dlist_init (DList *list, void (*destroy)(void *data));

/* dlist_destroy: To basically destroy a list 
 * list: Is the list that we want to destroy 
 * complexity: Is O(N)
*/
void dlist_destroy (DList *list);

/* dlist_ins_next: Is a function to insert a node next to another node, it going to return "0" if
 * everything goes well return "-1" if something comes wrong
 * list: Is the list that we were working on it 
 * element: Is the node which we are going to use to be able to insert the next node
 * data: Is the data that we want to plot
 * complexity: Is O(1) 
*/
int dlist_ins_next (DList *list, DListElmt *element, const void *data);

/* dlist_ins_prev: It insert a new node previous one, it returns "0" if everything comes well 
 * otherwise returns "-1" if something comes wrong 
 * list: Is the list that we were working on it
 * element: Is the next node from which we want to plot a new previous one node
 * data: Is the data that we want to plot
 * complexity: Is O(1)
*/
int dlist_ins_prev (DList *list, DListElmt *element, const void *data);

/* dlist_remove: Is going to remove the selected element from the list, the Return Value 
 * will be 0 if removing the element is successful, or –1 otherwise
 * list: Is the list that we were working
 * element: Is the element that we want to delete or remove 
 * data: Is a double pointer that we use to dump the removed data if we pass a null pointer
 * the function will executes the destroy fucntion
 * complexity: Is O(1)
*/
int dlist_remove (DList *list, DListElmt *element, void **data);

/* dlist_size: Is going to return the size of the list 
 * list: Is the list that we are using 
 * complexity: Is O(1)
*/
#define dlist_size(list) ((list)->size)

/* dlist_head: Is going to return the head pointer of the linked list 
 * list: Is the list that we were working on it 
 * complexity: Is O(1)
*/
#define dlist_head(list) ((list)->head)

/* dlist_tail: Is going to return the tail pointer of the linked list
 * list: Is the list that we were working on it
 * complexity: Is O(1)
*/
#define dlist_tail(list) ((list)->tail)

/* dlist_is_head: Return "0" if the passed pointer is the head otherwise returns "-1" 
 * element: Is the element that we want to know if it is the head
 * complexity: Is O(1)
*/
#define dlist_is_head(element) ((element)->prev == NULL ? 1 : 0)

/* dlist_is_tail: Return "0" if the passed pointer is the tail otherwise return "-1"
 * element: Is the element that we want to know if is the tail
 * complexity: Is O(1)
*/
#define dlist_is_tail(element) ((element)->next == NULL ? 1 : 0)

/* dlist_data: Return the data from one element 
 * element: Is the element from we want to get the data 
 * complexity: Is O(1)
*/
#define dlist_data(element) ((element)->data)

/* dlist_next: It going to return the next element from given one 
 * element: The element from we want to get the next element 
 * complexity: Is O(1)
*/
#define dlist_next(element) ((element)->next)

/* dlist_prev: It returns the previous node from a given node 
 * element: Is the element from where we want to get the previous element
 * complexity: Is O(1)
*/
#define dlist_prev(element) ((element)->prev)

#endif
