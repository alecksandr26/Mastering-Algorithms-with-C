#ifndef __SET_H_
#define __SET_H_

#include <stdlib.h>
#include <string.h>

/* Again we are going to need to use */
#include "../LinkedList/linkedlist.h"

/* To compile the code you will need the linkedlist.o or linkedlist.c */

/* Here we define again the set as a list */
typedef List Set;

/* set_init: Here we set the set structur
   set: Is the data structure 
   match: Is a boolean function that returns true if two pieces of data are equal
   destroy: Is a function that destroy our data
   complexity: Is O(1)
 */
void set_init (Set *set, int (*match)(const void *key1, const void *key2),
			  void (*destroy)(void *data));

/* set_destroy: To destroy our set
   set: is the data structure
   complexity: Is O(n) where n is the amount of data
 */
#define set_destroy list_destroy

/* set_insert: To insert new data to the data structure here we return 0 if
   the instertion goes well, 1 is the data was already added and -1 if something comes wrong
   set: is the data structure
   data: Is the data that we want to insert
   complexity: Is O(n) where n is the amount data
 */
int set_insert (Set *set, const void *data);

/* set_remove: To remove an element from the set reutrns 0 if okay -1 if something comes wrong
   set: is the data structure
   data: a pointer which is going to point to the data if it is null
   is going to try to free the memory
   complexity: Is O(n) because we need to check what is the position of the element
 */
int set_remove (Set *set, void **data);

/* set_union: To make an union operation returns -1 if something comes wrong 0 if it goes well
   setu: Is a pointer that we pass to point to the new structure of set 
   set1: The data structure
   complexity: Is O(nm) where "n" is the amount of set1 and "m" is the amount of set2
 */
int set_union (Set *setu, const Set *set1, const Set *set2);

/* set_intersection: To make an intersection with two sets return 0 if goes well otherwise -1
   seti: Is the result set of the intersection operation
   set1: Is an set structure
   set2: Is another set structure
   complexity: Is O(nm) where "n" is the amount of data of set1 and "m" is the amount of data of
   set2
 */
int set_intersection (Set *seti, const Set *set1, const Set *set2);

/* set_difference: To get into a set the operation difference
   setd: Is where we are going to store the result
   set1: Is a set structure
   set2: Is a set structure
   complexity: O(nm) n is the amount of set1 and m is the amount of set2
 */
int set_difference (Set *setd, const Set *set1, const Set *set2);

/* set_is_member: To now if some piece of data belongs to the set
   set: Is the data structure
   data: is the data that we are searching
   complexity: Is O(n) we need to check all the elements
 */
int set_is_member (const Set *set, const void *data);


/* set_is_subset: To check if set2 is a subset of set1
   set1: Is a set structure
   set2: Is a set structure
   complexity: Is O(nm)  where n is the amount of set1 and m is the amount of set2
 */
int set_is_subset (const Set *set1, const Set *set2);


/* set_is_equal: To know if these sets are equal
   set1: Is a set structure 
   set2: Is a set structure
   complexity: Is O(nm) is the amount of set1 and m is the amount of set2
 */
int set_is_equal (const Set *set1, const Set *set2);

/* set_size: Returns the size of the set
   set: Is a set structure
   complexity: Is O(1)
 */
#define set_size list_size

#endif
