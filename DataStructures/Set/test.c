#include <stdlib.h>
#include "./set.h"
#include "../LinkedList/linkedlist.h"

/* Our data will be integers */


int match (const int *a, const int *b)
{
	return *a == *b;
}

void destroy (int *a)
{
	free(a);
}


void main ()
{
	Set set, set2, setr;
	ListElemt *member;
	int b = 0;
	int a = 1;
	int c = 2;
	int d = 3;
	int i = 2;

	set_init(&set, &match, &destroy);
	set_init(&set2, &match, &destroy);
	
	set_insert(&set, &b);
	set_insert(&set, &d);
	set_insert(&set, &i);

	set_insert(&set2, &a);
	set_insert(&set2, &b);

	puts("Set:");
	for (member = list_head(&set); member != NULL; member = list_next(member))
		printf("%i\n", *((int *) list_data(member)));

	puts("Set2:");
	for (member = list_head(&set2); member != NULL; member = list_next(member))
		printf("%i\n", *((int *) list_data(member)));

	puts("Set u Set2:");
	set_union(&setr, &set, &set2);
	for (member = list_head(&setr); member != NULL; member = list_next(member))
		printf("%i\n", *((int *) list_data(member)));
	
	puts("Set ^ Set2:");
	set_intersection(&setr, &set, &set2);
	for (member = list_head(&setr); member != NULL; member = list_next(member))
		printf("%i\n", *((int *) list_data(member)));
}
