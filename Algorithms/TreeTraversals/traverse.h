#ifndef __TRAVERSE_H_
#define __TRAVERSE_H_

#include "../../DataStructures/BinaryTree/binarytree.h"
#include "../../DataStructures/LinkedList/linkedlist.h"


/* preorder: Iterates the whole tree in preorder and dump the result into a list
   node: Is the root of the tree
   list: Is the datastructure list
   complexity: Is O(n) where n is the number of nodes that the tree has
 */
int preorder (const BiTreeNode *node, List *list);


/* inorder: Iterates the whole tree in inorder and dump the result into a list
   node: Is the root of the tree
   list: Is the datastructure list
   complexity: Is O(n) where n is the number of nodes that the tree has
 */
int inorder (const BiTreeNode *node, List *list);


/* postorder: Iterates the whole tree in postorder and dump the result into a list
   node: Is the root of the tree
   list: Is the datastructure list
   complexity: Is O(n) where n is the number of nodes that the tree has
 */
int postorder (const BiTreeNode *node, List *list);


#endif
