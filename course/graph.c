#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ---------------- graph -------------------
// represents node in a graph
struct edge_node {
    int v; // node value
    int weight; // edge weight e.g. distance, etc.
    struct edge_node * next; // next node
};
typedef struct edge_node edge_node;

// represents graph
struct graph {
    // same as edge_node * edges[100], but declare dynamic size of array
    edge_node * * edges; // array of edge nodes in the graph
    int nb_nodes; // number of nodes in the graph
    int ng_edges; // number of edges in the graph
    bool is_directed; // whether graph is directed or not
};
typedef struct graph graph;

graph * create_graph(int nb_nodes, bool is_directed)
{
    graph * g = (graph *) malloc(sizeof(graph));
    g->nb_nodes = nb_nodes;
    g->ng_edges = 0;
    g->is_directed = is_directed;
    g->edges = (edge_node * *) malloc(sizeof(edge_node *) * nb_nodes);

    int u;
    for(u = 0; u < g->nb_nodes; u++) {
        g->edges[u] = NULL;
    }

    return g;
}

void print_graph(graph * g)
{
    int u;
    // for every list
    for(u = 0; u < g->nb_nodes; u++) {
        printf("%d --> ", u);

        // print all the nodes connected to u
        edge_node * e = g->edges[u];
        while(e != NULL) {
            printf("%d ", e->v);
            e = e->next;
        }
        printf("\n");
    }

}

// connect  u to v and the weight
void graph_add_edge(graph * g, int u, int v, int weight)
{
    edge_node * e = (edge_node *) malloc(sizeof(edge_node));
    e->v = v;
    e->weight = weight;
    e->next = g->edges[u];
    g->edges[u] = e;

    if(!g->is_directed) {
        e = (edge_node *) malloc(sizeof(edge_node));
        e->v = u;
        e->weight = weight;
        e->next = g->edges[v];
        g->edges[v] = e;
    }

    g->ng_edges++;
}

int main(int argc, char* argv[])
{
    graph * g = create_graph(6, false);
    graph_add_edge(g, 2, 4, 1);
    graph_add_edge(g, 2, 5, 1);

    print_graph(g);

    return 0;
}
