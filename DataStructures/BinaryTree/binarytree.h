#ifndef __BINARY_TREE_H_
#define __BINARY_TREE_H_

#include <stdlib.h>
#include <string.h>

/* The node structure */
typedef struct BiTreeNode_ {
    void *data;
    struct BiTreeNode_ *left;
    struct BiTreeNode_ *right;
} BiTreeNode;


/* the binary tree structure */
typedef struct BiTree_ {
    int size;
    int (*compare) (const void *key1, const void *key2);
    void (*destroy) (void *data);
    BiTreeNode *root;
} BiTree;


/* bitree_init: To initializes the binary tress
   tree: The data structure
   destroy: Is going to be the function that we are going to use
   complexity: O(1)
 */
void bitree_init (BiTree *tree, void (*destroy)(void *data));


/* bitree_destroy: Destroy the binary tree
   tree: The data structure
   complexity: O(n) where n is the number of nodes
 */
void bitree_destroy (BiTree *tree);


/* bitree_ins_left: Inserts a node as the left child of another one
   tree: The data structure
   node: The another one node
   data: That data that we want to insert
   complexity: O(1)
 */
int bitree_ins_left (BiTree *tree, BiTreeNode *node, const void *data);

/* bitree_ins_right: This operation is similar to bitree_ins_left except that it inserts a node as
   the right child of another one
   tree: The data structure
   node: The another one node
   data: The data that you want to insert
   complexity: O(1)
 */
int bitree_ins_right (BiTree *tree, BiTreeNode *node, const void *data);


/* bitree_rem_left: To remove the subtree at the left child of the node
   tree: The data structure
   node: The specified node if this node is NULL all the nodes in the tree are removed
   complexity: O(n) where n is the number of nodes
 */
void bitree_rem_left (BiTree *tree, BiTreeNode *node);


/* bitree_rem_right: To remove the subtree at right child of the node
   tree: The data structure
   node: The specified node if this node is NULL all the nodes in the tree are removed
   complexity: O(n) where n is the number of nodes
 */
void bitree_rem_right (BiTree *tree, BiTreeNode *node);


/* bitree_merge: To merge two binary trees specified by left and right into the single binary
   tree merge
   merge: The combination of the binary tree left and right
   left: A binary tree
   right: A binary tree
   data: The data contained by the root
   complexity: O(1)
*/
int bitree_merge (BiTree *merge, BiTree *left, BiTree *right, const void *data);


/* bitree_size: Evaluates the number of nodes
   tree: The data structure
   complexity: O(1)
 */
#define bitree_size(tree) ((tree)->size)

/* bitree_root: Node at the root of the tree
   tree: The data structure
   complexity: O(1)
 */
#define bitree_root(tree) ((tree)->root)

/* bitree_is_eob: Determines wheter the node specified as node marks the end of a branch
   node: The specified node
   complexity: O(1)
 */
#define bitree_is_eob(node) ((node) == NULL)

/* bitree_isleaf: Determines wheter the node specified as node is a leaf node
   node: The specified node
   complexity: O(1)
 */
#define bitree_is_leaf(node) ((node)->left == NULL && (node)->right == NULL)


/* bitree_data: evaluates to the the data stored inthe node of a binary tree specified by node
   node: The specified node
   complexity: O(1)
 */
#define bitree_data(node) ((node)->data)

/* bitree_left: Evaluates to the node of binary tree that is the left child of the node
   specified by node
   node: The specified node
   complexity: O(1)
 */
#define bitree_left(node) ((node)->left)


/* bitree_right: Evaluates to the node of a binary tree that is the right child of the node
   specified by node
   node: The specified node
   complexity: O(1)
 */
#define bitree_right(node) ((node)->right)

#endif
