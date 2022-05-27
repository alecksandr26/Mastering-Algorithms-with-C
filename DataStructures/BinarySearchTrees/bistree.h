#ifndef __BISTREE_H__
#define __BISTREE_H__

#include <stdlib.h>
#include <string.h>

/* Here we need to the binary tree dependency */
#include "../../DataStructures/BinaryTree/binarytree.h"


/* Define balance factorss for avl trees */
#define AVL_LFT_HEAVY 1
#define AVL_BALANCED 0
#define AVL_RGT_HEAVY -1


/* the avlnode */
typedef struct AvlNode_ {
    void *data;
    int hidden;
    int factor;
} AvlNode;


typedef BiTree BisTree;

/* bistree_init: Initializes the binary search tree specified by tree
   tree: is the data structure
   compare: specifies a user-defined function to compare elements
   destroy: The destroy argument provides a way to free dynamically 
   allocated data when bistree_destroy is called.
   complexity: Is the O(1)
*/
void bistree_init (BisTree *tree, void (*compare)(const void *key1, const void *key2), void (*destroy)(void *data));

/* bistree_destroy: To destroy the structure easy 
   tree: the data structure 
   complexity: Is O(n) where n is the number of nodes that the tree has 
 */
void bistree_destroy (BisTree *tree);

/* bistree_insert: To insert data insde of the tree 
   tree: is the data structure
   data: The data stored in the binary tree
   complexity: Is O(lg n) wheren is the nombre of nodes in the bianry search 
*/
int bistree_insert (BisTree *tree, const void *data);

/* bistree_remove: To remove one element 
   tree: Is the data structure
   data: The data to stored 
   complexity: Is O(lg n) where is the number of node in the binary search
*/
int bistree_remove (BisTree *tree, const void *data);

/* bistree_lookup: Determines whether a node matches data in the binary search
   tree specified as tree. If a match is found, data points to the matching data in the
   binary search tree upon return.
   tree: Is the data structure 
   data: Is the data found it 
   complexity: Is O(lg n) where n is the number of nodes 
 */
int bistree_lookup (const BisTree *tree, void **data);


/* bistree_size: returns the size of the tree
   tree: the data structure
   complexity: Is O(1)
 */
#define bistree_size(tree) ((tree)->size)


#endif
