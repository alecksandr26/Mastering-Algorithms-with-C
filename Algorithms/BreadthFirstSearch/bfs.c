#include <stdlib.h>

#include "bfs.h"
#include "../../DataStructures/Graphs/graphs.h"
#include "../../DataStructures/LinkedList/linkedlist.h"
#include "../../DataStructures/Queue/queue.h"


/* bfs: To do a bfs
   Graph: Is the data structure to iterate
   start: Is the vertex where we want to start
   hops: Where the algorithm stored the nodes to jump
   comlexity: Is O(N) where n is all the vertex 
 */
int bfs(Graph *graph, BfsVertex *start, List *hops)
{
    Queue queue;
    AdjList *adjlist, *clr_adjlist;
    BfsVertex *clr_vertex, *adj_vertex;
    ListElemt *element, *member;

    /* Find the started node */
    for (element = list_head(&graph_adjlists(graph)); element != NULL; element =
             list_next(element)) {
        clr_vertex = ((AdjList *) list_data(element))->vertex;
        
        if (graph->match(clr_vertex, start)) {
            clr_vertex->color = gray;
            clr_vertex->hops = 0;
        } else {
            clr_vertex->color = white;
            clr_vertex->hops = -1;
        }
    }

    queue_init(&queue, NULL);

    /* If the started node doesn't exist finish else get the adjlist of the started vertex */
    if (graph_adjlist(graph, start, &clr_adjlist) != 0) {
        queue_destroy(&queue);
        return -1;
    }

    if (queue_enqueue(&queue, clr_adjlist) != 0) {
        queue_destroy(&queue);
        return -1;
    }

    /* Perfome the breadth first search */
    while (queue_size(&queue) > 0) {
        adjlist = queue_peek(&queue);
        for (member = list_head(&adjlist->adjacent); member != NULL; member = list_next(member)) {
            adj_vertex = list_data(member);
            if (graph_adjlist(graph, adj_vertex, &clr_adjlist) != 0) {
                queue_destroy(&queue);
                return -1;
            }
            clr_vertex = clr_adjlist->vertex;

            if (clr_vertex->color == white) {
                clr_vertex->color = gray;
                clr_vertex->hops = ((BfsVertex *) adjlist->vertex)->hops + 1;
                if (queue_enqueue(&queue, clr_adjlist) != 0) {
                    queue_destroy(&queue);
                    return -1;
                }
            }
        }
        
        /* Dequeue the current adjacency list and color its vertex black */
        if (queue_dequeue(&queue, (void **) &adjlist) == 0)
            ((BfsVertex *) adjlist->vertex)->color = black;
        else {
            queue_destroy(&queue);
            return -1;
        }
    }
    
    queue_destroy(&queue);

    /* Initialize the list */
    list_init(hops, NULL);

    /* Insert all the nodes */
    for (element = list_head(&graph_adjlists(graph)); element != NULL; element = list_next(element)) {
        clr_vertex = ((AdjList *) list_data(element))->vertex;
        if (clr_vertex->hops != -1) {
            if (list_ins_next(hops, list_tail(hops), clr_vertex) != 0) {
                list_destroy(hops);
                return -1;
            }
        }
    }

    return 0;
}

