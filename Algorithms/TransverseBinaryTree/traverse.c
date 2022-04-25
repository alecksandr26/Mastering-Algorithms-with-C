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

