/* This is implementation of insertion sort algorithm */

#include "./insertionsort.h"

/* insertionSort: The insertion sort algorithm example runtime is n² 
 *
 * As I mention before you can use this code for another data types
 * data: can be an array of any data type object
 * size: The amount of objects 
 * osize: The size of each object 
 * compare: Is a function which is going to return boolean value
*/
void inssort (void *data, size_t size, size_t osize,
			  int (*compare)(const void *obj1, const void *obj2))
{
	unsigned char *arr = data; /* here we get the void pointer */
	void *temp; /* Here we are going to pass the memory to the object */
	int i, j; /* The indexers */

	/* Here we preare our temp object */
	if ((temp = (void *) malloc(osize)) == NULL) {
		fprintf(stderr, "Error: Not enough memory to run\n");
		exit(EXIT_FAILURE);
	}

	/* Here we start iterating the object */
	for (j = 1; j < size; ++j) {
		i = j - 1;
		/* Here we are able to copy the iterate object */
		memcpy(temp, &arr[j * osize], osize);

		/* Compare will return true or false if needs to change the position */
		while (i >= 0 && compare(&arr[i * osize], temp) > 0) {
			memcpy(&arr[(i + 1) * osize], &arr[i * osize], osize);
			--i;
		}
		memcpy(&arr[(i + 1) * osize], temp, osize);
	}
	
	/* Here we free the memory */
	free(temp);	
}
