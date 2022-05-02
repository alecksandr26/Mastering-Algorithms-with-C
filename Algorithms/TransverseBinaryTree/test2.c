#include "./traverse.h"



int main ()
{
    BiTree mytree;
    List mylist;
    ListElemt *el;
    int x = 1;
    int x2 = 2;
    int x3 = 3;

    /* Init the lists and the tree */
    bitree_init(&mytree, NULL);
    list_init(&mylist, NULL);

    bitree_ins_right(&mytree, NULL, &x);
    bitree_ins_right(&mytree, bitree_root(&mytree), &x2);
    bitree_ins_left(&mytree, bitree_root(&mytree)->right, &x3);

    preorder(bitree_root(&mytree), &mylist);

    puts("hello");
    for (el = list_head(&mylist); el != NULL; el = list_next(el)) {
        printf("%i\n", *((int *) list_data(el)));
    }


        
    return 0;
}
