#include <stdio.h>
#include <stdlib.h>

#include "./queue.h"

void destroy (int *a)
{
	free(a);
}

/* It works as you can see we create queue */
void main ()
{
	Queue queue;
	int *num, *num2, *num3;
	
	queue_init(&queue, &destroy);
	num = (int *) malloc(sizeof(int));
	*num = 10;
	queue_enqueue(&queue, num);
	num2 = (int *) malloc(sizeof(int));
	*num2 = 20;
	queue_enqueue(&queue, num2);
	num3 = (int *) malloc(sizeof(int));
	*num3 = 30;
	queue_enqueue(&queue, num3);

	printf("%i\n", *((int *) queue_peek(&queue)));
}

