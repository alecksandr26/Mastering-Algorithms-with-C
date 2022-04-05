# Circular Lists
The circular list is another form of linked list that provides additional flexibility in
traversing elements. A circular list may be singly-linked or doubly-linked, but its
distinguishing feature is that it has no tail. In a circular list, the next pointer of the
last element points back to its first element rather than to NULL. In the case of a
doubly-linked circular list, the prev pointer of the first element is set to point to the
last element as well.
# Circular List Example: Second-Chance Page Replacement
Earlier we saw how a singly-linked list might be used to manage frame allocation
in a virtual memory system. One issue not addressed, however, was how a system
allocates new frames when the list of available frames is empty. To deal with this,
a system frees a frame by moving a page from physical memory to a disk called a
swap disk. The system uses a page-replacement algorithm to determine which
frame is best to free at a given moment. One example of a page-replacement algorithm is the second-chance algorithm, sometimes called the clock algorithm.