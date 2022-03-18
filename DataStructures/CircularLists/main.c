#include <stdio.h>
#include <stdlib.h>

#include "./circularlists.h"

void destroy (int *num)
{
	free(num);
}


int main ()
{
	CList list;
	int num;

	clist_init(&list, &destroy);

	num = 1;
	clist_ins_next(&list, NULL, &num);

	/* Here I print the number */
	printf("%i\n", *((int *) clist_head(&list)->data));
	
	return 0;
}
