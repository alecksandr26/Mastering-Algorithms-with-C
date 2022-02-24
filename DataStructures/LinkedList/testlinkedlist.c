#include <stdio.h>
#include <stdlib.h>

#include "./linkedlist.h"

/* Here is my destroy function */
void destroy (int *ptr)
{
	free(ptr);
}

void main ()
{
	List l; /* Here I create the list */
	int *ptr, *ptr2, *ptr3, *ptr4;
	ListElemt *node;
	
	/* Then I add some elements  its recomendable to use pointers */
	ptr = (int *) malloc(sizeof(int));
	*ptr = 10;
	
	ptr2 = (int *) malloc(sizeof(int));
	*ptr2 = 20;
	
	ptr3 = (int *) malloc(sizeof(int));
	*ptr3 = 30;

	/* Now we initlize our list */
	list_init(&l, &destroy);

	/* After that we are enable to insert elements */
	list_ins_next(&l, NULL, ptr); /* we pass null because we don't have more elements */

	list_ins_next(&l, NULL, ptr2);

	list_ins_next(&l, NULL, ptr3);

	printf("size of list: %i\n", list_size(&l));
	/* Here we catch the the tail from the list | tail =  10 */
	node = list_tail(&l);
	printf("node element: %i\n", *((int *) node->data)); /* output = 10 */

	ptr4 = (int *) malloc(sizeof(int));
	*ptr4 = 100;
	
	list_ins_next(&l, node, ptr4);

	/* Now to iterate this we can do */
	node = list_head(&l); /* Here we get the head */
	while (node != NULL) {
		printf("%i ", *((int *) node->data));
		node = list_next(node); /* This is how we are going to get the next elemetn */
	}
	puts("");

	/* Here we destroy our object */
	list_destroy(&l);
}
