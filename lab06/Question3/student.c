#include "graph.h"

// Description

// Check whether the graph contains a triangle. A triangle is a set of three nodes that are all connected to each other. 
// The graph is stored as an adjacency matrix. 
// Graph* g is a pointer to a Graph struct, which contains a 2D array adj[MAX_NODES][MAX_NODES]. 
// The value at adj[u][v] is 1 if there is an edge between nodes u and v, and 0 otherwise.

int has_triangle(Graph* g) {
    int tri = 0;
    for(int u=0; u<MAX_NODES; u++) {
        for(int v=u+1; v<MAX_NODES;v++) {
            if(g->adj[u][v] == 1) { // nodeA -> nodeB
                for (int w=v+1; w<MAX_NODES; w++){
                    tri = g->adj[v][w] && g->adj[w][u]; // nodeB -> nodeC && nodeC -> nodeA
                    if (tri) return tri; // triangle has been found, otherwise continue searching
                }
            }
        }
    }

    return tri;
}
