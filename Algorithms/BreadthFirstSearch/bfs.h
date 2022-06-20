
#ifndef __BFS_H__
#define __BFS_H__

#include "../../DataStructures/Graphs/graphs.h"
#include "../../DataStructures/LinkedList/linkedlist.h"

typedef enum {
    gray,
    black,
    white
} VertexColor;



typedef struct {
    void *data;
    VertexColor color;
    int hops;
} BfsVertex;




int bfs(Graph *graph, BfsVertex *start, List *hops);

#endif
