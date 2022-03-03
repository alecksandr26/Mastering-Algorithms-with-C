# Doubly Linked List
Doubly-linked lists, as their name implies, are composed of elements linked by
two pointers. Each element of a doubly-linked list consists of three parts: in addi-
tion to the data and the next pointer, each element includes a pointer to the previ-
ous element, called the prev pointer. A doubly-linked list is formed by composing
a number of elements so that the next pointer of each element points to the ele-
ment that follows it, and the prev pointer points to the element preceding it. To
mark the head and tail of the list, we set the prev pointer of the first element and
the next pointer of the last element to NULL.