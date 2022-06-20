#include <stdlib.>

#include "./dfs.h"

#include "../../DataStructures/Graphs/graphs.h"
#include "../../DataStructures/LinkedList/linkedlist.h"


static int dfs_main(Graph *graph, AdjList *adjlist, List *ordered)
{
    AdjList *clr_adjlist;
    DfsVertex *clr_vertex, *adj_vertex;
    ListElemt *member;


    ((DfsVertex *) adjlist->vertex)->color = gray;
    for (member = list_head(&adjlist->adjacent); member != NULL; member = list_next(member)) {
        if (graph_adjlist(graph, adj_vertex, &clr_adjlist) != 0)
            return -1;
        clr_vertex =  clr_adjlist->vertex;

        if (clr_vertex->color == white) {
            if (dfs_main(graph, clr_adjlist, ordered) != 0)
                return -1;
        }
    }

    ((DfsVertex *) adjlist->vertex)->color = black;
    if (list_ins_next(ordered, NULL, (DfsVertex *) adjlist->vertex) != 0)
        return -1;

    return 0;
}


