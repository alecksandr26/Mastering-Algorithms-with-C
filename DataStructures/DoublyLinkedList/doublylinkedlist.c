#include "./doublylinkedlist.h"

/* dlist_init: Here we initialize my list and also I pass the function to destroy my objects 
 * list: Is the struct that deals with the linked nodes of data 
 * destroy: Is the function that is going to free the information that we were saving
 * complexity: Is O(1)
*/
void dlist_init (DList *list, void (*destroy)(void *data))
{
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	list->destroy = destroy;
}

/* dlist_destroy: To basically destroy each element from the list using the destroy function passed
 * list: Is the list that we want to destroy 
 * complexity: Is O(N)
*/
void dlist_destroy (DList *list)
{
	/* Here we catch the data */
	void *data;

	while (dlist_size(list) > 0) {
		if (dlist_remove(list, dlist_tail(list), &data) == 0 && list->destroy != NULL)
			list->destroy(data); /* execute the destroy function */
		else
			free(data); /* otherwise we destroy the data */
	}

	/* Here we set in null all the structure */
	memset(list, 0, sizeof(DList));
}

/* dlist_ins_next: Is a function to insert a node next to another node, it going to return "0" if
 * everything goes well return "-1" if something comes wrong
 * list: Is the list that we were working on it 
 * element: Is the node which we are going to use to be able to insert the next node
 * data: Is the data that we want to plot
 * complexity: Is O(1) 
*/
int dlist_ins_next (DList *list, DListElmt *element, const void *data)
{
	DListElmt *new_element;

	/* We can't insert a null element if the list has one element */
	if (element == NULL && (dlist_size(list) != 0))
		return -1;

	/* If all the memory is filled */
	if ((new_element = (DListElmt *) malloc(sizeof(DListElmt))) == NULL)
		return -1;

	new_element->data = (void *) data;

	if (dlist_size(list) == 0) { /* the list is empty */
		list->head = new_element;
		list->head->prev = NULL;
		list->head->next = NULL;
		list->tail = new_element;
	} else { /* the list is not empty the element exist */
		new_element->next = element->next;
		new_element->prev = element;

		if (element->next == NULL) /* if the element is the tail */
			list->tail = new_element;
		else
			element->next->prev = new_element;
		
		element->next = new_element;
	}

	list->size++;
	return 0;
}


/* dlist_ins_prev: It insert a new node previous one, it returns "0" if everything comes well 
 * otherwise returns "-1" if something comes wrong 
 * list: Is the list that we were working on it
 * element: Is the next node from which we want to plot a new previous one node
 * data: Is the data that we want to plot
 * complexity: Is O(1)
*/
int dlist_ins_prev (DList *list, DListElmt *element, const void *data)
{
	DListElmt *new_element;
	
	/* We can't insert a null element if the list has at least one element */
	if (element == NULL && (dlist_size(list) != 0))
		return -1;
	
	/* If all the memory is filled */
	if ((new_element = (DListElmt *) malloc(sizeof(DListElmt))) == NULL)
		return -1;
	
	new_element->data = (void *) data;

	if (dlist_size(list) == 0) { /* if the list is empty */
		list->head = new_element;
		list->head->next = NULL;
		list->head->prev = NULL;
		list->tail = new_element;
	} else { /* If the list is not empty and also we have an element */
		new_element->next = element;
		new_element->prev = element->prev;
		
		if (element->prev == NULL) /* if it is the top element */
			list->head = new_element;
		else 
			element->prev->next = new_element;
		
		element->prev = new_element;
	}
	
	list->size++;
	return 0;
}

/* dlist_remove: Is going to remove the selected element from the list, the Return Value 
 * will be 0 if removing the element is successful, or –1 otherwise
 * list: Is the list that we were working
 * element: Is the element that we want to delete or remove 
 * data: Is a double pointer that we use to dump the removed data if we pass a null pointer
 * the function will executes the destroy fucntion
 * complexity: Is O(1)
*/
int dlist_remove (DList *list, DListElmt *element, void **data)
{
	/* We can't remove a null element or remove something if the list is empty */
	if (element == NULL || dlist_size(list) == 0)
		return -1;
	
	/* Here we catch the data */
	if (data != NULL) /* if the pointer is not null */
		*data = element->data;
	else
		free(element->data);
	
	if (element == list->head) { /* If the element is the head */
		list->head = element->next; /* we take the next element as the new head */
		
		/* If the head is null means that the is going to be empty */
		if (list->head == NULL) 
			list->tail = NULL;
		else
			element->next->prev = NULL; 
	} else {
		element->prev->next = element->next;

		if (element->next == NULL) /* If we get to the tail */
			list->tail = element->prev;
		else
			element->next->prev = element->prev;
	}
	
	list->size--;
	
	/* Here we delete the node */
	free(element);
	
	return 0;
}
