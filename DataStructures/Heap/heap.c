#include "./heap.h"


/* Some private macro methods */
#define heap_parent(npos) ((int)(((npos) - 1) / 2))

#define heap_left(npos) (((npos) * 2) + 1)

#define heap_right(npos) (((npos) * 2) + 2)
   

/* heap_init: Initializes the heap specified by heap. 
   head: The data structure
   compare: To compare the function
   destroy: To destroy the data structure
   complexity: Is O(1)
 */
void heap_init (Heap *heap, int (*compare)(const void *key1, const void *key2),
               void (*destroy)(void *data))
{
    heap->size = 0;
    heap->destroy = destroy;
    heap->compare = compare;
    heap->tree = NULL;
}


/* heap_destroy: destroy everything
   heap: The data structure
   complexity: Is O(n) where n is the number of nodes
 */
void heap_destroy (Heap *heap)
{
    int i;

    if (heap->destroy != NULL)
        for (i = 0; i < heap_size(heap); ++i)
            heap->destroy(heap->tree[i]);

    free(heap->tree);

    memset(heap, 0, sizeof(Heap));
}


/* heap_insert: To insert a new node to the heap
   heap: Is the data structure
   data: The data to insert
   complexity: Is O(logN) where N is the number o nodes 
 */
int heap_insert (Heap *heap, const void *data)
{
    void *temp;
    int ipos, ppos;

    /* reallocate all the memory */
    if ((temp = (void  **) realloc(heap->tree, (heap_size(heap) + 1) * sizeof(void *))) == NULL)
        return -1;
    else
        heap->tree = temp;

    /* Insert a new node */
    heap->tree[heap_size(heap)] = (void *) data;

    /* calculate the sizes */
    ipos = heap_size(heap);
    ppos = heap_parent(ipos);

    /* Reordenate every node */
    while (ipos > 0 && heap->compare(heap->tree[ppos], heap->tree[ipos]) < 0) {
        temp = heap->tree[ppos];
        heap->tree[ppos] = heap->tree[ipos];
        heap->tree[ipos] = temp;

        /* move to the another level */
        ipos = ppos;
        ppos = heap_parent(ipos);
    }

    heap->size++;

    return 0;
}



/* heap_extract: To dump the root value
   heap: Is the data structure
   data: The pointer to allocate the result
   complexity: Is O(logN) where N is the number of nodes
 */
int heap_extract (Heap *heap, void **data)
{
    void *save, *temp;
    int ipos, lpos, rpos, mpos;

     if (heap_size(heap) == 0)
        return -1;

    /* Get the root */
    *data = heap->tree[0];

    /* Save the last node */
    save = heap->tree[heap_size(heap) - 1];

    if (heap_size(heap) - 1 > 0) {
        /* reallocate the memory making shorter */
        if ((temp = (void **) realloc(heap->tree, (heap_size(heap) - 1) * sizeof(void *))) == NULL)
            return - 1;

        else
            heap->tree = temp;

        heap->size--;
    } else { /* when its the last node */
        free(heap->tree);
        heap->tree = NULL;
        heap->size = 0;
        
        return 0;
    }


    /* Copy the last node to the root */
    heap->tree[0] = save;

    
    ipos = 0;
    
    /* And now reorder the list */
    while (1) {
        /* calculate the indexes */
        lpos = heap_left(ipos);
        rpos = heap_right(ipos);
    
        if ((lpos < heap_size(heap)) && (heap->compare(heap->tree[lpos], heap->tree[ipos]) > 0))
            mpos = lpos;
        else
            mpos = ipos;
        
        if ((rpos < heap_size(heap)) && (heap->compare(heap->tree[rpos], heap->tree[mpos]) > 0))
            mpos = rpos;
        
        if (mpos == ipos) /* This ends the loop */
            break;
        
        else { /* Swap the values */
            temp = heap->tree[mpos];
            heap->tree[mpos] = heap->tree[ipos];
            heap->tree[ipos] = temp;

            /* Make it equals */
            ipos = mpos;
        }
    }

    return 0;
}

