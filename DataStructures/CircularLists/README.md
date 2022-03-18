# Circular Lists
The circular list is another form of linked list that provides additional flexibility in
traversing elements. A circular list may be singly-linked or doubly-linked, but its
distinguishing feature is that it has no tail. In a circular list, the next pointer of the
last element points back to its first element rather than to NULL. In the case of a
doubly-linked circular list, the prev pointer of the first element is set to point to the
last element as well.