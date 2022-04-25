#include "./binarytree.h"


/* bitree_init: To initializes the binary tress
   tree: The data structure
   destroy: Is going to be the function that we are going to use
   complexity: O(1)
 */
void bitree_init (BiTree *tree, void (*destroy)(void *data))
{
    tree->size = 0;
    tree->destroy = destroy;
    tree->root = NULL;
}



/* bitree_destroy: Destroy the binary tree
   tree: The data structure
   complexity: O(n) where n is the number of nodes
 */
void bitree_destroy (BiTree *tree)
{
    bitree_rem_left(tree, NULL);
    memset(tree, 0, sizeof(BiTree));
}



/* bitree_ins_left: Inserts a node as the left child of another one
   tree: The data structure
   node: The another one node
   data: That data that we want to insert
   complexity: O(1)
 */
int bitree_ins_left (BiTree *tree, BiTreeNode *node, const void *data)
{
    BiTreeNode *new_node, **position;

    /* Determine where to insert the node */
    if (node == NULL) {
        if (bitree_size(tree) > 0)
            return -1;
        position = &tree->root;
    } else {
        if (bitree_left(node) != NULL)
            return -1;
        position = &node->left;
    }

    if ((new_node = (BiTreeNode *) malloc(sizeof(BiTreeNode))) == NULL)
        return -1;

    /* Insert the data to the new node */
    new_node->data = (void *) data;
    new_node->left = NULL;
    new_node->right = NULL;
    *position = new_node;

    tree->size++;

    return 0;
}



/* bitree_ins_right: This operation is similar to bitree_ins_left except that it inserts a node as
   the right child of another one
   tree: The data structure
   node: The another one node
   data: The data that you want to insert
   complexity: O(1)
 */
int bitree_ins_right (BiTree *tree, BiTreeNode *node, const void *data)
{
    BiTreeNode *new_node, **position;

    /* Calculate its position */
    if (node == NULL) {
        if (bitree_size(tree) > 0)
            return -1;
        position = &tree->root;
    } else {
        if (bitree_right(node) != NULL)
            return -1;
        position = &node->right;
    }

    if ((new_node = (BiTreeNode *) malloc(sizeof(BiTreeNode))) == NULL)
        return -1;

    /* Insert the data to the new node */
    new_node->data = (void *) data;
    new_node->left = NULL;
    new_node->right = NULL;
    *position = new_node;

    tree->size++;

    return 0;
}


/* bitree_rem_left: To remove the subtree at the left child of the node
   tree: The data structure
   node: The specified node if this node is NULL all the nodes in the tree are removed
   complexity: O(n) where n is the number of nodes
 */
void bitree_rem_left (BiTree *tree, BiTreeNode *node)
{
    BiTreeNode **position;

    if (bitree_size(tree) == 0)
        return;

    /* Determine where to remove nodes */

    if (node == NULL)
        position = &tree->root;
    else
        position = &node->left;

    /* Remove the nodes  it is a recursive function */
    if (*position != NULL) {
        bitree_rem_left(tree, *position);
        bitree_rem_right(tree, *position);

        /* To destroy the data contained into the node */
        if (tree->destroy != NULL)
            tree->destroy((*position)->data);
        /* Free the node */
        free(*position);
        *position = NULL;
        
        tree->size--;
    }
}

/* bitree_rem_right: To remove the subtree at right child of the node
   tree: The data structure
   node: The specified node if this node is NULL all the nodes in the tree are removed
   complexity: O(n) where n is the number of nodes
 */
void bitree_rem_right (BiTree *tree, BiTreeNode *node)
{
    BiTreeNode **position;

    if (bitree_size(tree) == 0)
        return;

    /* Determine where to remove nodes */

    if (node == NULL)
        position = &tree->root;
    else
        position = &node->right;

    /* Remove the nodes  it is a recursive function */
    if (*position != NULL) {
        bitree_rem_left(tree, *position);
        bitree_rem_right(tree, *position);

        /* To destroy the data contained into the node */
        if (tree->destroy != NULL)
            tree->destroy((*position)->data);
        /* Free the node */
        free(*position);
        *position = NULL;
        
        tree->size--;
    }
}



/* bitree_merge: To merge two binary trees specified by left and right into the single binary
   tree merge
   merge: The combination of the binary tree left and right
   left: A binary tree
   right: A binary tree
   data: The data contained by the root
   complexity: O(1)
*/
int bitree_merge (BiTree *merge, BiTree *left, BiTree *right, const void *data)
{
    /* Here I initializes the merge tree */
    bitree_init(merge, left->destroy);

    /* If something comes wrong with the insertion return -1 */
    if (bitree_ins_left(merge, NULL, data) != 0) {
        bitree_destroy(merge);
        return -1;
    }

    /* Here is where we insert the data */
    bitree_root(merge)->left = bitree_root(left);
    bitree_root(merge)->right = bitree_root(right);

    /* And now we combine the sizes */
    merge->size = merge->size + bitree_size(left) + bitree_size(right);

    /* Do not let the originals trees access the merged nodes */
    left->root = NULL;
    left->size = 0;
    right->root = NULL;
    right->size = 0;

    return 0;
}

