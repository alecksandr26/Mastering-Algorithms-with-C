#include "traverse.h"


/* preorder: Iterates the whole tree in preorder and dump the result into a list
   node: Is the root of the tree
   list: Is the datastructure list
   complexity: Is O(n) where n is the number of nodes that the tree has
 */
int preorder (const BiTreeNode *node, List *list)
{
    /* To know when we get into the end of the tree */
    if (!bitree_is_eob(node)) {
        /* Inser the node */
        if (list_ins_next(list, list_tail(list), bitree_data(node)) != 0)
            return -1;

        /* Recursive case until get to one leaf */
        if (!bitree_is_eob(bitree_left(node)))
            if (preorder(bitree_left(node), list) != 0)
                return -1;
        
        /* Recursive case until get to one leaf */
        if (!bitree_is_eob(bitree_right(node)))
            if (preorder(bitree_right(node), list) != 0)
                return -1;
    }

    return 0;
}


/* inorder: Iterates the whole tree in inorder and dump the result into a list
   node: Is the root of the tree
   list: Is the datastructure list
   complexity: Is O(n) where n is the number of nodes that the tree has
 */
int inorder (const BiTreeNode *node, List *list)
{
    /* To make sure when we get a null node */
    if (!bitree_is_eob(node)) {
        
        /* In this case Iterates into the left path of the tree doing our recursive case */
        if (!bitree_is_eob(bitree_left(node)))
            if (inorder(bitree_left(node), list) != 0)
                return -1;
        
        /* Inserts the nodes */
        if (list_ins_next(list, list_tail(list), bitree_data(node)) != 0)
            return -1;

        /* After Iterates to the right path */
        if (!bitree_is_eob(bitree_right(node)))
            if (inorder(bitree_right(node), list) != 0)
                return -1;
    }
    return 0;
}


/* postorder: Iterates the whole tree in postorder and dump the result into a list
   node: Is the root of the tree
   list: Is the datastructure list
   complexity: Is O(n) where n is the number of nodes that the tree has
 */
int postorder (const BiTreeNode *node, List *list)
{
    /* Is not null */
    if (!bitree_is_eob(node)) {
        /* Iterate the whole list in both sides left and right */
        if (!bitree_is_eob(bitree_left(node)))
            if (postorder(bitree_left(node), list) != 0)
                return -1;
        if (!bitree_is_eob(bitree_right(node)))
            if (postorder(bitree_right(node), list) != 0)
                return -1;
        
        /* Insert insert the nodes */
        if (list_ins_next(list, list_tail(list), bitree_data(node)) != 0)
            return -1;
    }
    return 0;
}
