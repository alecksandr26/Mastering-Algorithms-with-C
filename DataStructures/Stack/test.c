#include <stdio.h>

#include "./stack.h"

/* destroy: To delete some element */
void destroy (int *ptr)
{
	free(ptr);
}

void main ()
{
	Stack s;
	int num, num2, *ptr;
	
	stack_init(&s, &destroy); /* Here I initialize my stack */
	num = 5;
	num2 = 10;
	stack_push(&s, &num);
	stack_push(&s, &num2);
	
	printf("Num: %u\n", *((unsigned *) stack_peek(&s)));
	stack_pop(&s, &ptr);
	printf("Num2: %u\n", *((unsigned *) stack_peek(&s)));
}
