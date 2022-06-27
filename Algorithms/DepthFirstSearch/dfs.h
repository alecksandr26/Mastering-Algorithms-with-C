#ifndef __DFS_H__
#define __DFS_H__

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
} DfsVertex;

int dfs(Graph *graph, List *ordered);

#endif


