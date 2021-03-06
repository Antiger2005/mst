/* graph initialization methods */
#ifndef INITIALIZE_GRAPH_H
#define INITIALIZE_GRAPH_H

#include <input/adj_list.h> /* edge_list */
#include <mst.h> /* edge, foi */

/** Initializes G to an unitialized list of edges */
void initialize_edge_list(edge **G, int num_edges);

/** Initializes G to an empty adjacency list with the specified number of vertices */
void initialize_adjacency_list(edge_list **el, int num_verts, int num_edges);

/** Initializes G to an empty adjacency matrix with weights initialized to -1.0f */
void initialize_adjacency_matrix(foi **G, int num_verts);

#endif /* INITIALIZE_GRAPH_H */

