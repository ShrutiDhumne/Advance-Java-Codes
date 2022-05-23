// Name: Abhijeet Ashok Gandhi           Batch: E2
// Roll: 244        PRN: 0220200160     Assignment_4 (Krushkal Algorithm)

#include <bits/stdc++.h>
using namespace std;

                                                    // a structure to represent a
                                                    // weighted edge in graph
class Edge{
    public:
        int src, dest, weight;
};
                                                    // a structure to represent a connected,
                                                    // undirected and weighted graph
class Graph{
    public:

     int V, E;
     Edge* edge;
};
                                                    // Creates a graph with V vertices and E edges
Graph* createGraph(int V, int E){
    Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}
                                                    // A structure to represent a subset for union-find
class subset {
public:
    int parent;
    int rank;
};
                                                    // A utility function to find set of an element i
                                                    // (uses path compression technique)
int find(subset subsets[], int i){
                                                    // find root and make root as parent of i
                                                    // (path compression)
    if (subsets[i].parent != i)
        subsets[i].parent
            = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}
                                                    // A function that does union of two sets of x and y
                                                    // (uses union by rank)
void Union(subset subsets[], int x, int y){
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
                                                    // Attach smaller rank tree under root of high
                                                    // rank tree (Union by Rank)
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
                                                    // If ranks are same, then make one as root and
                                                    // increment its rank by one
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
                                                    // Compare two edges according to their weights.
int myComp(const void* a, const void* b){
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1->weight > b1->weight;
}
                                                    // The main function to construct MST using Kruskal's
                                                    // algorithm
void KruskalMST(Graph* graph)
{
    int V = graph->V;
    Edge result[V];                                 // output array of Algorithm
    int e = 0;                                      // Final selected edges in algo
    int i = 0;

                                                    // sorting of edges
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]),myComp);
                                                    // Allocate memory for creating V ssubsets
    subset* subsets = new subset[(V * sizeof(subset))];
                                                    // Create V subsets with single elements
    for (int v = 0; v < V; ++v){
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
                                                    // Number of edges to be taken is equal to V-1
    while (e < V - 1 && i < graph->E){
                                                    // pick smallest edge
        Edge next_edge = graph->edge[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
                                                    // In no cycle case add edge to output
        if (x != y){
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
                                                    // Else discard the edge
    }
    cout << "\nKruskal Algorithm --> \n";
    int minimumCost = 0;
    for (i = 0; i < e; ++i){
        cout << result[i].src << " -- " << result[i].dest<< " = " << result[i].weight << endl;
        minimumCost = minimumCost + result[i].weight;
    }
    cout << "\nMinimum Cost Spanning Tree --> " << minimumCost<< endl;
}
                                                    // Driver code
int main()
{
    int V;                                          // Number of vertices in graph
    int E;                                          // Number of edges in graph
    cout<<"Enter vertex and Edge of graph : ";
    cin>>V>>E;
    Graph* graph = createGraph(V, E);
    int i;
    for(i=0;i<E;i++){
        cout<<"\nEnter Source Vertex --> Destination Vertex --> Weight of edge : ";
        cin>>graph->edge[i].src>>graph->edge[i].dest>>graph->edge[i].weight;
    }
                                                    // Function call
    KruskalMST(graph);

    return 0;
}

/*
***********************************************OUTPUT************************************

Enter vertex and Edge of graph : 4 5

Enter Source Vertex --> Destination Vertex --> Weight of edge : 2 3 1

Enter Source Vertex --> Destination Vertex --> Weight of edge : 2 4 3

Enter Source Vertex --> Destination Vertex --> Weight of edge : 1 4 5

Enter Source Vertex --> Destination Vertex --> Weight of edge : 3 4 2

Enter Source Vertex --> Destination Vertex --> Weight of edge : 2 1 4

Kruskal Algorithm -->
2 -- 3 = 1
3 -- 4 = 2
2 -- 1 = 4

Minimum Cost Spanning Tree --> 7

*/
