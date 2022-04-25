#include <stdio.h>

#include "./binarytree.h"


void destroy (int *data)
{
    free(data);
}


int main ()
{
    BiTree mytree;
    int x = 2;
    int x2 = 3;
    BiTree mytree2;
    BiTree merge;
    int x3 = 5;
    int x4 = 10;

    bitree_init(&mytree, &destroy);
    bitree_init(&mytree2, &destroy);
    
    bitree_ins_right(&mytree, NULL, &x);
    bitree_ins_right(&mytree2, NULL, &x3);

    printf("%p | %p\n", bitree_root(&mytree)->data, &x);
    printf("%i\n", *((int *) bitree_root(&mytree)->data));

    printf("%p | %p\n", bitree_root(&mytree2)->data, &x);
    printf("%i\n", *((int *) bitree_root(&mytree2)->data));


    /* Here I put a left node */
    bitree_ins_left(&mytree, bitree_root(&mytree), &x2);

    printf("%p | %p\n", bitree_data(bitree_root(&mytree)->left), &x);
    printf("%i\n", *((int *) bitree_data(bitree_root(&mytree)->left)));

    /* Now lets test the merge */
    bitree_merge(&merge, &mytree2, &mytree, &x4);

    printf("%p | %p\n", bitree_root(&merge)->data, &x4);
    printf("%i\n", *((int *) bitree_root(&merge)->data));

    /* To print the left thing */
    printf("%p\n", bitree_data(bitree_root(&merge)->left));
    printf("%i\n", *((int *) bitree_data(bitree_root(&merge)->left)));
    
    return 0;
}

