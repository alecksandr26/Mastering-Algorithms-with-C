#include <stdlib.>

#include "dfs.h"
#include "../../DataStructures/Graphs/graphs.h"
#include "../../DataStructures/LinkedList/linkedlist.h"


/* dfs_main: This is the dfs algorithm  */
static int dfs_main(Graph *graph, AdjList *adjlist, List *ordered)
{
    AdjList *clr_adjlist;
    DfsVertex *clr_vertex, *adj_vertex;
    ListElemt *member;


    /* First Mark the first node as gray */
    ((DfsVertex *) adjlist->vertex)->color = gray;
    for (member = list_head(&adjlist->adjacent); member != NULL; member = list_next(member)) {
        if (graph_adjlist(graph, adj_vertex, &clr_adjlist) != 0)
            return -1;
        clr_vertex =  clr_adjlist->vertex;
        /* Needs to iterate */
        if (clr_vertex->color == white) {
            if (dfs_main(graph, clr_adjlist, ordered) != 0)
                return -1;
        }
    }

    /* Finishing with this node and insert it in the list */
    ((DfsVertex *) adjlist->vertex)->color = black;
    if (list_ins_next(ordered, NULL, (DfsVertex *) adjlist->vertex) != 0)
        return -1;

    return 0;
}


/* dfs: This is the function interface */
int dfs(Graph *graph, List *ordered)
{
    DfsVertex *vertex;
    ListElemt *element;


    /* Fill all the vertex as white */
    for (element = list_head(&graph_adjlists(graph)); element != NULL; element = list_next(element)) {
        vertex = ((AdjList *) list_data(element))->vertex;
        vertex->color = white;
    }

    /* Init the list with the sorted graph */
    list_init(ordered, NULL);

    /* Iterate all the elements and create the list */
    for (element = list_head(&graph_adjlists(graph)); element != NULL; element = list_next(element)) {
        vertex = ((AdjList *) list_data(element))->vertex;
        if (vertex->color == white) {
            if (dfs_main(graph, (AdjList *) list_data(element), ordered) != 0) {
                list_destroy(ordered);
                return -1;
            }
        }
    }

    return 0;
}


