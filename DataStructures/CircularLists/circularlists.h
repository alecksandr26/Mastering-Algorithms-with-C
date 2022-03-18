#ifndef __CIRCULAR_LISTS_H_
#define __CIRCULAR_LISTS_H_

#include <stdlib.h>
#include <string.h>

/* CListElmt The element */
typedef struct CListElmt_ {
	void *data;
	struct CListElmt_ *next;
} CListElmt;

/* CList_ the list  */
typedef struct CList_ {
	int size;
	int (*match)(const void *key1, const void *key2);
	void (*destroy)(void *data);
	CListElmt *head;
} CList;

/* clist_init: To initlize a new list
 * list: Is the list that we want to use 
 * destroy: The function that is going to destroy our element that we want to save
 * Complexity: O(1)
 */
void clist_init (CList *list, void (*destroy)(void *data));

/* clist_destroy: To delete the list 
 * list: The list that you want
 * complexity: O(1)
*/
void clist_destroy (CList *list);

/* clist_ins_next: To insert a node from another node 
 * list: The list that you want
 * element: element or node from where we want to insert a new node
 * data: The data that we want to save 
 * complexity: O(1)
*/
int clist_ins_next (CList *list, CListElmt *element, const void *data);

/* clist_rem_next: To remove one node from another node
 * list: the list that we are using
 * element: The node where we want to remove another node
 * data: The pointer to catch the data that we want to delete
 * complexity: O(1)
*/
int clist_rem_next (CList *list, CListElmt *element, void **data);

/* clist_size: Return the size of the list
 * list: The list that we were using
 * complexity: O(1)
*/
#define clist_size(list) ((list)->size)

/* clist_head: Return the head of the list
 * list: The list of that we were using
 * complexity: O(1)
*/
#define clist_head(list) ((list)->head)

/* clist_data: Return the data from the element
 * element: The element that we want to catch the data 
 * complexity: O(1)
*/
#define clist_data(element) ((element)->data)

/* clist_next: To return the next element from one node
 * element: The element or node from we want to get the next element
 * complexity: O(1)
*/
#define clist_next(element) ((element)->next)

#endif
