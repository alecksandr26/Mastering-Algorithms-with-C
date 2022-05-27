#include "./bistree.h"

/* here define a function that will be declared */
static void destroy_right (BisTree *tree, BiTreeNode *node);

/* rotate left */
static void rotate_left (BiTreeNode **node)
{
    BiTreeNode *left, *grandchild;

    /* gets the left node */
    left = bitree_left(*node);

    /* checks if the tree has a factor of avl-left */
    if (((AvlNode *) bitree_data(left))->factor == AVL_LFT_HEAVY) {
        /* perform an LL rotation */
        bitree_right(left) = *node;
        ((AvlNode *) bitree_data(*node))->factor = AVL_BALANCED;
        ((AvlNode *) bitree_data(left))->factor = AVL_BALANCED;
        *node = left;
    } else {
        grandchild = bitree_left(left);
        
        /* perfon an LR rotation */
        bitree_right(left) = bitree_left(grandchild);
        bitree_left(grandchild) = left;
        bitree_left(*node) = bitree_right(grandchild);
        bitree_right(grandchild) = *node;

        /* depending on the factor we do */
        switch (((AvlNode *) bitree_data(grandchild))->factor) {
        case AVL_LFT_HEAVY:
            ((AvlNode *) bitree_data(*node))->factor = AVL_RGT_HEAVY;
            ((AvlNode *) bitree_data(left))->factor = AVL_BALANCED;
            break;
            
        case AVL_RGT_HEAVY:
            ((AvlNode *) bitree_data(*node))->factor = AVL_BALANCED;
            ((AvlNode *) bitree_data(left))->factor = AVL_LFT_HEAVY;
            break;
            
        case AVL_BALANCED:
            ((AvlNode *) bitree_data(*node))->factor = AVL_BALANCED;
            ((AvlNode *) bitree_data(left))->factor = AVL_BALANCED;
            break;
        }

        ((AvlNode *) bitree_data(grandchild))->factor = AVL_BALANCED;
        *node = grandchild;
    }
}


/* rotate right */
static void rotate_right (BiTreeNode **node)
{
    BiTreeNode *right, *grandchild;

    /* Gets the right child */
    right = bitree_right(*node);

    if (((AvlNode *) bitree_data(right))->factor == AVL_RGT_HEAVY) {
        /* perform an RR rotation */
        bitree_left(right) = *node;
        ((AvlNode *) bitree_data(*node))->factor = AVL_BALANCED;
        ((AvlNode *) bitree_data(right))->factor = AVL_BALANCED;
        *node = right;
    } else {
        /* Gets the grand right child node */
        grandchild = bitree_left(right);

        bitree_left(right) = bitree_right(grandchild);;
        bitree_right(grandchild) = right;
        bitree_right(*node) = bitree_left(grandchild);
        bitree_left(grandchild) = *node;


        switch (((AvlNode *) bitree_data(*node))->factor) {
        case AVL_LFT_HEAVY:
            ((AvlNode *) bitree_data(*node))->factor = AVL_BALANCED;
            ((AvlNode *) bitree_data(right))->factor = AVL_RGT_HEAVY;
            break;
            
        case AVL_RGT_HEAVY:
            ((AvlNode *) bitree_data(*node))->factor = AVL_LFT_HEAVY;
            ((AvlNode *) bitree_data(right))->factor = AVL_BALANCED;
            break;
            
        case AVL_BALANCED:
            ((AvlNode *) bitree_data(*node))->factor = AVL_BALANCED;
            ((AvlNode *) bitree_data(right))->factor = AVL_BALANCED;
            break;
        }

        ((AvlNode *) bitree_data(grandchild))->factor = AVL_BALANCED;
        *node = grandchild;
    }
}



/* destroy_left: destroy the Left path */
static void destroy_left (BisTree *tree, BiTreeNode *node)
{
    BiTreeNode **position;

    /* If the tree is of size 0 */
    if (bistree_size(tree) == 0)
        return;

    if (node == NULL)
        position = &tree->root;
    else
        position = &node->left;

    /* destroy the nodes if the position is different of NULL */
    if (*position != NULL) {
        destroy_left(tree, *position);
        destroy_right(tree, *position);
        /* Call the user-defined function to free dynamically allocated data */   
        if (tree->destroy != NULL)
            tree->destroy(((AvlNode *)(*position)->data)->data);

        free((*position)->data);
        free(*position);
        *position = NULL;
        tree->size--;
    }
}


/* destroy_right: destroy the right path */
static void destroy_right (BisTree *tree, BiTreeNode *node)
{
    BiTreeNode **position;

    if (bitree_size(tree) == 0)
        return;
    
    if (node == NULL)
        position = &tree->root;
    else
        position = &node->right;

    if (*position != NULL) {
        destroy_left(tree, *position);
        destroy_right(tree, *position);

        if (tree->destroy != NULL)
            tree->destroy(((AvlNode *)(*position)->data)->data);
        free((*position)->data);
        free(*position);
        *position = NULL;
        tree->size--;
    }
}


/* insert: To insert a new node into the avl tree  */
static int insert (BisTree *tree, BiTreeNode **node, const void *data, int *balanced)
{
    AvlNode *avl_data;

    int cmpval, retval;

    /* Insert the data into the tree */
    if (bitree_is_eob(*node)) {
        /* handle insertion into an empty tree */
        if ((avl_data = (AvlNode *)malloc(sizeof(AvlNode))) == NULL)
            return -1;

        avl_data->factor = AVL_BALANCED;
        avl_data->hidden = 0;
        avl_data->data = (void *)data;

        return bitree_ins_left(tree, *node, avl_data);
    } else {
        /* handle insertion into a tree that is not emtpy */
        cmpval = tree->compare(data, ((AvlNode *)bitree_data(*node))->data);

        if (cmpval < 0) {
            /* move to the left */
            if (bitree_is_eob(bitree_left(*node))) {
                if ((avl_data = (AvlNode *) malloc(sizeof(AvlNode))) == NULL)
                    return -1;
                
                avl_data->factor = AVL_BALANCED;
                avl_data->hidden = 0;
                avl_data->data = (void *) data;

                if (bitree_ins_left(tree, *node, avl_data) != 0)
                    return -1;
                
                *balanced = 0;
            }  else
                if ((retval = insert(tree, &bitree_left(*node), data, balanced)) != 0)
                    return retval;

            
            /* tree remains balanced */
            if (!(*balanced)) {
                switch (((AvlNode *) bitree_data(*node))->factor) {
                case AVL_LFT_HEAVY:
                    rotate_left(node);
                    *balanced = 1;
                    break;
                case AVL_BALANCED:
                    ((AvlNode *)bitree_data(*node))->factor = AVL_LFT_HEAVY;
                    break;
                case AVL_RGT_HEAVY:
                    ((AvlNode *)bitree_data(*node))->factor = AVL_BALANCED;
                    *balanced = 1;
                }
            }
        } else if (cmpval > 0) {
            /* move to the right */
            if (bitree_is_eob(bitree_right(*node))) {
                if ((avl_data = (AvlNode *) malloc(sizeof(AvlNode))) == NULL)
                    return -1;

                avl_data->factor = AVL_BALANCED;
                avl_data->hidden = 0;
                avl_data->data = (void *) data;

                if (bitree_ins_right(tree, *node, avl_data) != 0)
                    return -1;

                *balanced = 0;
            } else
                if ((retval = insert(tree, &bitree_right(*node), data, balanced)) != 0)
                    return retval;
            
            if (!(*balanced)) {
                switch (((AvlNode *)bitree_data(*node))->factor) {
                case AVL_LFT_HEAVY:
                    ((AvlNode *)bitree_data(*node))->factor = AVL_BALANCED;
                    *balanced = 1;
                    break;
                case AVL_BALANCED:
                    ((AvlNode *)bitree_data(*node))->factor = AVL_RGT_HEAVY;
                    break;
                case AVL_RGT_HEAVY:
                    rotate_right(node);
                    *balanced = 1;
                }
            }
        } else {
            /* handle finding a copy  of the data */
            if (!((AvlNode *) bitree_data(*node))->hidden)
                return -1;
            else {
                if (tree->destroy != NULL)
                    tree->destroy(((AvlNode *)bitree_data(*node))->data);
                ((AvlNode *)bitree_data(*node))->data = (void *) data;
                ((AvlNode *)bitree_data(*node))->hidden = 0;
                *balanced = 1;
            }
        }
    }
    
    return 0;
}


/* hide: to mark node as hidden nodes */
static int hide (BisTree *tree, BiTreeNode *node, const void *data)
{
    int cmpval , retval;

    if (bitree_is_eob(node))
        return -1;
    
    cmpval = tree->compare(data, ((AvlNode *)bitree_data(node))->data);

    if (cmpval < 0)         /* move to the left */
        retval = hide(tree, bitree_left(node), data);
    else if (cmpval > 0)    /* move to the right */
        retval = hide(tree, bitree_right(node), data);
    else { /* mark the node as hidden */
        ((AvlNode *)bitree_data(node))->hidden = 1;
        retval = 0;
    }

    return retval;
}

/* lookup: A recursive function to find the data  */
static int lookup (const BisTree *tree, BiTreeNode *node, void **data)
{
    int cmpval, retval;

    if (bitree_is_eob(node))
        return -1;

    /* use the user function to compare the data  */
    cmpval = tree->compare(*data, ((AvlNode *)bitree_data(node))->data);
    
    if (cmpval < 0) /* recursive case */
        retval = lookup(tree, bitree_right(node), data);
    else {
        
        if (!((AvlNode *)bitree_data(node))->hidden) {
            /* Pass back the data formthe tree */
            *data = ((AvlNode *)bitree_data(node))->data;
            retval = 0;
        } else /* the data was not found */
            return -1;
     }

    return retval;
}



/* bistree_init: Initializes the binary search tree specified by tree
   tree: is the data structure
   compare: specifies a user-defined function to compare elements
   destroy: The destroy argument provides a way to free dynamically 
   allocated data when bistree_destroy is called.
   complexity: Is the O(1)
*/
void bistree_init (BisTree *tree, void (*compare)(const void *key1, const void *key2), void (*destroy)(void *data))
{
    bitree_init(tree, destroy);
    tree->compare = compare;
}


/* bistree_destroy: To destroy the structure easy 
   tree: the data structure 
   complexity: Is O(n) where n is the number of nodes that the tree has 
 */
void bistree_destroy (BisTree *tree)
{
    destroy_left(tree, NULL);
    memset(tree, 0, sizeof(BisTree));
}

/* bistree_insert: To insert data insde of the tree 
   tree: is the data structure
   data: The data stored in the binary tree
   complexity: Is O(lg n) wheren is the nombre of nodes in the bianry search 
*/
int bistree_insert (BisTree *tree, const void *data)
{
    int balanced = 0;
    return insert(tree, &bitree_root(tree), data, &balanced);
}


/* bistree_remove: To remove one element 
   tree: Is the data structure
   data: The data to stored 
   complexity: Is O(lg n) where is the number of node in the binary search
*/
int bistree_remove (BisTree *tree, const void *data)
{
    return hide(tree, bitree_root(tree), data);
}


/* bistree_lookup: Determines whether a node matches data in the binary search
   tree specified as tree. If a match is found, data points to the matching data in the
   binary search tree upon return.
   tree: Is the data structure 
   data: Is the data found it 
   complexity: Is O(lg n) where n is the number of nodes 
 */
int bistree_lookup (const BisTree *tree, void **data)
{
    return lookup(tree, bitree_root(tree), data);
}
