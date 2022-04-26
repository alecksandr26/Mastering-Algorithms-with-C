#include <stdio.h>

#include "./traverse.h"

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
    int x5 = 11;
    unsigned num;

    int *x_ptr;

    List list;
    ListElemt *ptr;

    bitree_init(&mytree, &destroy);
    bitree_init(&mytree2, &destroy);
    
    bitree_ins_right(&mytree, NULL, &x);
    bitree_ins_right(&mytree2, NULL, &x3);


    /* Here I put a left node and right node */
    bitree_ins_left(&mytree, bitree_root(&mytree), &x2);

    /* Now lets test the merge */
    bitree_merge(&merge, &mytree2, &mytree, &x4);

    /* THIS IS IN PREORDER */
    puts("[1] preorder");
    puts("[2] inorder");
    puts("[3] postorder");

    scanf("%u", &num);
    switch (num) {
    case 1:
        /* THIS IS IN PREORDER */
        puts("lets do a preorder...");
        list_init(&list, NULL);
        preorder(bitree_root(&merge), &list);

        for (ptr = list_head(&list); ptr != NULL; ptr = list_next(ptr)) {
            x_ptr = (int *) list_data(ptr);
            printf("%i\n", *x_ptr);
        }
        break;
    case 2:
        /* THIS IS IN INORDER */
        puts("lets do a inorder...");
        list_init(&list, &destroy);
        inorder(bitree_root(&merge), &list);

        for (ptr = list_head(&list); ptr != NULL; ptr = list_next(ptr)) {
            x_ptr = (int *) list_data(ptr);
            printf("%i\n", *x_ptr);
        }
        break;
    case 3:
        /* THIS IS IN POSTORDER */
        puts("lets do a postorder...");
        list_init(&list, &destroy);
        postorder(bitree_root(&merge), &list);

        for (ptr = list_head(&list); ptr != NULL; ptr = list_next(ptr)) {
            x_ptr = (int *) list_data(ptr);
            printf("%i\n", *x_ptr);
        }
        break;
    }
    
    return 0;
}

