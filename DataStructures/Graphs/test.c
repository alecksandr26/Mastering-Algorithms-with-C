#include <stdio.h>

#include "graphs.h"


int match(const int *key1, const int *key2)
{
    if (*key1 == *key2)
        return 1;
    return 0;
}


void destroy(int *data)
{

}


int main()
{
    Graph graph;
    int num = 5, num2 = 4;

    
    graph_init(&graph, &match, &destroy);

    graph_ins_vertex(&graph, &num);
    graph_ins_vertex(&graph, &num2);

    graph_ins_edge(&graph, &num, &num2);
    
    return 0;
}
