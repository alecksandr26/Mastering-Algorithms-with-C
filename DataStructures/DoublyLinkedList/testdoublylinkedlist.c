#include <stdio.h>
#include <stdlib.h>

#include "./doublylinkedlist.h"

/* destroy: This is my destroy function just free the data */
void destroy (int *data)
{
	free(data);
}

void main ()
{
	DList list;
	int *ele1 = malloc(4);
	DListElmt *ptr;
	
	*ele1 = 10;
	
	/* Here I initialize my list */
	dlist_init(&list, &destroy);
	dlist_ins_next(&list, NULL, ele1);
	ptr = dlist_head(&list);

	/* print the data */
	printf("ele1: %i\n", *((int *) ptr->data));
}
