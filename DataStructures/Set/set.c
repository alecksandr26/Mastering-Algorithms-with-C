#include "./set.h"

/* set_init: Here we set the set structur
   set: Is the data structure 
   match: Is a boolean function that returns true if two pieces of data are equal
   destroy: Is a function that destroy our data
   complexity: Is O(1)
 */
void set_init (Set *set, int (*match)(const void *key1, const void *key2),
			  void (*destroy)(void *data))
{
	list_init(set, destroy);
	set->match = match;
}

/* set_insert: To insert new data to the data structure here we return 0 if
   the instertion goes well, 1 is the data was already added and -1 if something comes wrong
   set: is the data structure
   data: Is the data that we want to insert
   complexity: Is O(n) where n is the amount data
 */
int set_insert (Set *set, const void *data)
{
	if (set_is_member(set, data))
		return 1;
	return list_ins_next(set, list_tail(set), data);
}

/* set_remove: To remove an element from the set reutrns 0 if okay -1 if something comes wrong
   set: is the data structure
   data: a pointer which is going to point to the data if it is null
   is going to try to free the memory
   complexity: Is O(n) because we need to check what is the position of the element
 */
int set_remove (Set *set, void **data)
{
	ListElemt *member, *prev;
	prev = NULL;

	for (member = list_head(set); member != NULL; member = list_next(member)) {
		if (set->match(*data, list_data(member)))
			break;
		prev = member;
	}
	if (member != NULL)
		return -1;
	
	return list_rem_next(set, prev, data);
}

/* set_union: To make an union operation returns -1 if something comes wrong 0 if it goes well
   setu: Is a pointer that we pass to point to the new structure of set 
   set1: The data structure
   complexity: Is O(nm) where "n" is the amount of set1 and "m" is the amount of set2
 */
int set_union (Set *setu, const Set *set1, const Set *set2)
{
	ListElemt *member;
	void *data;

	set_init(setu, set1->match, NULL);

	/* Insert the elements of the first set */
	for (member = list_head(set1); member != NULL; member = list_next(member)) {
		data = list_data(member);
		if (list_ins_next(setu, list_tail(setu), data) != 0) {
			set_destroy(setu);
			return -1;
		}
	}

	/* Inser the elements of the second set */
	for (member = list_head(set2); member != NULL; member = list_next(member)) {
		/* Continue if already exist */
		if (set_is_member(set1, list_data(member)))
			continue;

		/* Otherwise we add the element */
		data = list_data(member);
		if (list_ins_next(setu, list_tail(setu), data) != 0) {
			set_destroy(setu);
			return -1;
		}
	}

	return 0;
}

/* set_intersection: To make an intersection with two sets return 0 if goes well otherwise -1
   seti: Is the result set of the intersection operation
   set1: Is an set structure
   set2: Is another set structure
   complexity: Is O(nm) where "n" is the amount of data of set1 and "m" is the amount of data of
   set2
 */
int set_intersection (Set *seti, const Set *set1, const Set *set2)
{
	ListElemt *member;
	void *data;

	set_init(seti, set1->match, NULL);

	for (member = list_head(set1); member != NULL; member = list_next(member)) {
		data = list_data(member);
		/* Here we just add the data that set2 has */
		if (set_is_member(set2, data)) {
			if (list_ins_next(seti, list_tail(seti), data) != 0) {
				set_destroy(seti);
				return -1;
			}
		}
	}

	return 0;
}


/* set_difference: To get into a set the operation difference
   setd: Is where we are going to store the result
   set1: Is a set structure
   set2: Is a set structure
   complexity: O(nm) n is the amount of set1 and m is the amount of set2
 */
int set_difference (Set *setd, const Set *set1, const Set *set2)
{
	ListElemt *member;
	void *data;

	set_init(setd, set1->match, NULL);

	/* First we do the operations of the set */
	for (member = list_tail(set1); member != NULL; member = list_next(member)) {
		data = list_data(member);
		if (!set_is_member(set2, data)) {
			if (list_ins_next(setd, list_tail(setd), data)) {
				set_destroy(setd);
				return -1;
			}
		}
	}
	
	return 0;
}


/* set_is_member: To now if some piece of data belongs to the set
   set: Is the data structure
   data: is the data that we are searching
   complexity: Is O(n) we need to check all the elements
 */
int set_is_member (const Set *set, const void *data)
{
	ListElemt *member;

	for (member = list_head(set); member != NULL; member = list_next(member)) {
		if (set->match(data, list_data(member)))
			return 1;
	}
	return 0;
}


/* set_is_subset: To check if set2 is a subset of set1
   set1: Is a set structure
   set2: Is a set structure
   complexity: Is O(nm)  where n is the amount of set1 and m is the amount of set2
 */
int set_is_subset (const Set *set1, const Set *set2)
{
	ListElemt *member;

	if (set_size(set1) > set_size(set2))
		return 0;

	for (member = list_head(set1); member != NULL; member = list_next(member)) {
		if (!set_is_member(set2, list_data(member)))
			return 0;
	}

	return 1;
}


/* set_is_equal: To know if these sets are equal
   set1: Is a set structure 
   set2: Is a set structure
   complexity: Is O(nm) is the amount of set1 and m is the amount of set2
 */
int set_is_equal (const Set *set1, const Set *set2)
{
	ListElemt *member;

	if (set_size(set1) != set_size(set2))
		return 0;

	for (member = list_head(set1); member != NULL; member = list_next(member)) {
		if (!set_is_member(set2, list_data(member)))
			return 0;
	}
	return 1;
}

