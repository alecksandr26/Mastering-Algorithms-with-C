
#ifndef __GRAPHS_H__
#define __GRAPHS_H__

#include <stdlib.h>
#include <string.h>

/* Include the needed libs */
#include "../LinkedList/linkedlist.h"
#include "../Set/set.h"


/* Define the structure of adjacency */
typedef struct AdjList_ {
    void *vertex;
    Set adjacent;
} AdjList;


/* This is the data structure of a graph */
typedef struct Graph_ {
    int vcount;
    int ecount;
    
    int (*match)(const void *key1, const void *key2);
    void (*destroy)(void *data);
    
    List adjlists;
} Graph;

/* graph_init:
   graph: Is the data structure
   match: return 1 if key1 is equal to key2, and 0 otherwise
   destroy: provied a free dynamically allocation of the nodes
   complexity: Is O(1) 
 */
void graph_init(Graph *graph, int (*match)(const void *key1, const void *key2),
                void (*destroy)(void *data));

/* graph_destroy:
   graph: Is the data structure
   complexity: Is O(V + E) where v is the number os vertices and e is the number of edges
 */
void graph_destroy(Graph *graph);



/* graph_ins_vertex: 0 if inserting the vertex is successful, 1 if the vertex already exists, or –1 otherwise
   graph: Is the datastructure
   data: Is the data to insert
   complexity: Is O(V) where v is the number vertices in the graph
 */
int graph_ins_vertex(Graph *graph, const void *data);


/* graphs_ins_edge: 0 if inserting the edge is successful, 1 if the edge already exists, or –1 otherwise
   graph: Is the data structure
   data1 and data2: Are tha pair ordened of data
   complexity: Is O(V) where v is the number of vectires int he graph
 */
int graph_ins_edge(Graph *graph, const void *data1, const void *data2);


/* graph_rem_vertex: 0 if removing the vertex is successful, or –1 otherwise
   graph: Is the data structure
   data: A pointer that points to the removed data
   complexity: O(V + E), where V is the number of vertices in the graph and E is the number of edges
 */
int graph_rem_vertex(Graph *graph, void **data);


/* graph_rem_edge: 0 if removing the edge is successful, or –1 otherwise
   graph: The data structure
   data1 and data2: Are the vertices which you are going to remove its edge
   complexity: Is O(V) where v is the number of vertices in the graph
 */
int graph_rem_edge(Graph *graph, const void *data1, void **data2);


/* graph_adjelist: 0 if retrieving the adjacency list is successful, or –1 otherwise
   graph: The data structure
   complexity: O(V) where v is the number of vertecies into the graph
 */
int graph_adjlist(const Graph *graph, const void *data, AdjList **adjlist);


/* graph_is_adjacent: 1 if the second vertex is adjacent to the first vertex, or 0 other-wise
   complexity: Is O(v) where v is the number of vertices
 */
int graph_is_adjacent(const Graph *graph, const void *data1, const void *data2);


/* graph_adjlist: Number of vertices in the graph.
   complexity: Is O(1)
 */
#define graph_adjlists(graph) ((graph)->adjlists)

/* graph_vcount: Number of vertices in the graph.
   complexity: Is O(1)
 */
#define graph_vcount(graph) ((graph)->vcount)

/* graph_ecount: Number of edges in the graph
   complexity: Is O(1)
 */
#define graph_ecount(graph) ((graph)->ecount)


#endif






