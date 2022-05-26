#include "./bistree.h"

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
        bitree_left(*node) = bitree_right(gra ndchild);
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
    BiTreeNode = *right, *grandchild;

    /* Gets the right child */
    right = bitree_right(*node);

    if (((AlvNode *) bitree_data(right))->factor == AVL_RGT_HEAVY) {
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



/* destroy_right: destroy the right path */
static void destroy_right (BisTree *tree, BiTreeNode *node)
{
    BiTreeNode **position;

    if (bitree_size(tree) == 0)
        return;

    if (node == NULL)
        position = &tree->right;
    else
        position = &node->right;

    if (*position != NULL) {
        
    }
}






