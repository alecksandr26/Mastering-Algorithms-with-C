/* A simple test of the module */
#include <stdio.h>
#include <stdbool.h>

#include "./insertionsort.h"


/* And also here is my function compare */
bool compare (const int *a, const int *b)
{
	return *a > *b;
}


void main ()
{
	/* First we need to delcare our array */
	int arr[] = { 5, 4, 3, 2, 1 };
	int i;
	
	inssort(arr, 5, sizeof(int), &compare);

	for (i = 0; i < 5; ++i)
		printf("%i ", arr[i]);
	
	puts("");
	
}




