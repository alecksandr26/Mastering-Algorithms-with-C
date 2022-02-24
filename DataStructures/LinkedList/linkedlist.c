#include "./linkedlist.h"


/* list_init: Will initlize the list this must be the first function to execute to be able
 * to execute more functions.
 * list: receive a list object
 * destroy: We need to receive a fucntion that destroy one element inside of the array 
*/
void list_init (List *list, void (*destroy)(void *data))
{
	list->size = 0;
	list->destroy = destroy;
	list->head = NULL;
	list->tail = NULL;
}

/* list_destroy: This function will delete all structure after execute this function 
 * no other operations with the structre is going to be permited the runtime is O(n).
 * list: Its your list object 
*/
void list_destroy (List *list)
{
	void **double_ptr; /* Here we catch the pointer from the data */
	
	/* Here we just remove each element */
	while (list_size(list) > 0) {
		/* Here basically we are destroying the list in pieces */
		if (list_rem_next(list, NULL, double_ptr) == 0 &&
			list->destroy != NULL)
			list->destroy(*double_ptr); /* execute the destroy function received by the user */
	}

	/* After deleting the whole structure we clean the list object */
	memset(list, 0, sizeof(List));
}

/* list_ins_next: This function will insert a new element from another element
 * runtime complexity of this operation is O(1), if it returns "0" is else something comes wrong.
 * list: Is the structure object.
 * elem: This is the element that we want to have previos
 * data: Is the data to we are going to have after the selected element
*/
int list_ins_next (List *list, ListElemt *elem, const void *data)
{
	ListElemt *new_elemnt; /* The pointer of the new element */

	/* Check if nothing wrong happens */
	if ((new_elemnt = (ListElemt *) malloc(sizeof(ListElemt))) == NULL)
		return -1;

	/* Catch the data, remove the const value */
	new_elemnt->data = (void *) data;

	/* This means that the list is empty or that the user wanst to put it in the top */
	if (elem == NULL) {
		if (list_size(list) == 0) /* The list is empty the tail is going to points to the elemnt*/
			list->tail = new_elemnt;
		
		/* First we points to the current top of the element */
		new_elemnt->next = list->head;
		
		/* After we put the head into the top */
		list->head = new_elemnt;
	} else {
		if (elem->next == NULL) /* means that there is just one element in the list */
			list->tail = new_elemnt;

		/* Here points to the next element from the elem */
		new_elemnt->next = elem->next;
		
		/* Now elem points to our current point */
		elem->next = new_elemnt;
	}

	/* Here we increase the size of the list */
	++(list->size);
	
	return 0; /* that everything is fine */
}



/* list_rem_next: It goins to remove the next element from an element from the list
 * the runtime complexity is O(1), also returns "0" if everything done well.
 * list: The list structure
 * elem: Is the element from where we are going to delete the next it
 * data: To catch the pointer from where the data is stored 
*/
int list_rem_next (List *list, ListElemt *elem, void **data_to_catch)
{
	ListElemt *old_element;
	void *data;

	/* Is not allowd to remove elements from a list */
	if (list_size(list) == 0)
		return -1;
	
	/* Here we removes the head elements */
	if (elem == NULL) {
		data = list->head->data; /* Here we catch the pointer of the data */
		/* Update the new head */
		old_element = list->head;
		list->head = old_element->next;
		/* If the list just contain one elment we set the tail as null */
		if (list_size(list) == 1)
			list->tail = NULL;
	} else {
		/* Here we can't remove a null object */
		if (elem->next == NULL)
			return -1;
		
		/* Catch its data */
		data = elem->next->data;
		/* Catch the element to remove */
		old_element = elem->next;
	}
	/* Here we need to know what we want to do with the data */
	if (*data_to_catch == NULL) /* if the user doens't provied a pointer */
		list->destroy(data); /* we destroy the data */
	else
		*data_to_catch = data; /* Here we plot the data in the pointer */
	/* Here we free the memory of that object */
	free(old_element);
	--(list->size); /* the reduce the size of the list */

	return 0;
}
