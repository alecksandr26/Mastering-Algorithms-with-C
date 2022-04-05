#include "./circularlists.h"

/* clist_init: To initlize a new list
 * list: Is the list that we want to use 
 * destroy: The function that is going to destroy our element that we want to save
 * Complexity: O(1)
 */
void clist_init (CList *list, void (*destroy)(void *data))
{
	list->size = 0;
	list->destroy = destroy;
	list->head = NULL;
}

/* clist_destroy: To delete the list 
 * list: The list that you want
 * complexity: O(1)
*/
void clist_destroy (CList *list)
{
	void *data;

	while (clist_size(list) > 0)
		if (clist_rem_next(list, list->head, (void **)&data) == 0
			&& list->destroy != NULL)
			list->destroy(data);
	
	memset(list, 0, sizeof(CList));
}

/* clist_ins_next: To insert a node from another node 
 * list: The list that you want
 * element: element or node from where we want to insert a new node
 * data: The data that we want to save 
 * complexity: O(1)
*/
int clist_ins_next (CList *list, CListElmt *element, const void *data)
{
	CListElmt *new_element;

	if ((new_element = (CListElmt *)malloc(sizeof(CListElmt))) == NULL)
		return -1;

	new_element->data = (void *)data;
	
	if (clist_size(list) == 0) {
		new_element->next = new_element;
		list->head = new_element;
	} else {
		new_element->next = element->next;
		element->next = new_element;
	}
	
	list->size++;
	return 0;
}

/* clist_rem_next: To remove one node from another node
 * list: the list that we are using
 * element: The node where we want to remove another node
 * data: The pointer to catch the data that we want to delete
 * complexity: O(1)
*/
int clist_rem_next (CList *list, CListElmt *element, void **data)
{
	CListElmt *old_element;

	if (clist_size(list) == 0)
		return -1;

	*data = element->next->data;
	if (element->next == element) {
		old_element = element->next;
		list->head = NULL;
	} else {
		old_element = element->next;
		element->next = element->next->next;
		if (old_element == clist_head(list))
			list->head = old_element->next;
	}
	
	free(old_element);
	list->size--;
	
	return 0;
}

