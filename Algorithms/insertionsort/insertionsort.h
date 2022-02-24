
/* This is the dependency of insertion sort algorithm in c */
#ifndef __INSERTION_SORT_H_
#define __INSERTION_SORT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


/* insertionSort: The insertion sort algorithm example runtime is n² 
 *
 * As I mention before you can use this code for another data types
 * data: can be an array of any data type object
 * size: The amount of objects 
 * osize: The size of each object 
 * compare: Is a function that you should provied to know how we are going to 
 * sort the list
*/
void inssort (void *data, size_t size, size_t osize,
			  bool (*compare)(const void *obj1, const void *obj2));


/* For example if you want to sort an array of numbers you should provied 
 * a function like this.
 * 
 * int gtr (const int *a, const int *b)
 * {
 *     return *a > *b; 
 * }
*/


#endif
