#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
  
struct Edge { 
    int u, v, weight; 
}; 
struct Graph { 
    int V, E; 
    struct Edge* edge; 
}; 

struct Graph* createGraph(int V, int E) { 
    struct Graph* graph;
    graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V; 
    graph->E = E;
    graph->edge = (struct Edge*)malloc(sizeof(struct Edge)*E);
    return graph; 
} 
  
struct subset { 
    int parent; 
    int rank; 
}; 

int find(struct subset subsets[], int i) { 
    if (subsets[i].parent != i) 
        subsets[i].parent = find(subsets, subsets[i].parent); 
    return subsets[i].parent; 
} 

void Union(struct subset subsets[], int x, int y) { 
    int xroot = find(subsets, x); 
    int yroot = find(subsets, y); 
  
    if (subsets[xroot].rank < subsets[yroot].rank) 
        subsets[xroot].parent = yroot; 
    else if (subsets[xroot].rank > subsets[yroot].rank) 
        subsets[yroot].parent = xroot; 
    else{ 
        subsets[yroot].parent = xroot; 
        subsets[xroot].rank++; 
    } 
} 
  
int myComp(const void* a, const void* b) {  //For Sorting
    struct Edge* a1 = (struct Edge*)a; 
    struct Edge* b1 = (struct Edge*)b; 
    return a1->weight > b1->weight; 
} 

int printMST(struct Edge result[], int e) {
    int cost = 0, i;
    printf("Edge \tWeight\n"); 
    for (i = 0; i < e; ++i) {
        printf("%d--%d \t%d\n", result[i].u, result[i].v, result[i].weight); 
        cost += result[i].weight;
    }
    printf("Cost: %d.\n", cost);
} 

void KruskalMST(struct Graph* graph) { 
    int V = graph->V; 
    struct Edge result[V];
    int e = 0; 
    int i = 0; 
    int v, x, y;
  
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp); 
    struct subset *subsets = (struct subset*) malloc( V * sizeof(struct subset) ); 
  
    for (v = 0; v < V; ++v) { 
        subsets[v].parent = v; 
        subsets[v].rank = 0; 
    } 
  
    while (e < V - 1 && i < graph->E) { 
        struct Edge next_edge = graph->edge[i++]; 
  
        x = find(subsets, next_edge.u); 
        y = find(subsets, next_edge.v); 
        if (x != y) { 
            result[e++] = next_edge; 
            Union(subsets, x, y); 
        } 
    } 
  
    printMST(result,e);
    return; 
} 

int main() 
{ 
    int V, E;
    printf("Number of vertices: ");
    scanf("%d",&V);
    printf("Number of edges: ");
    scanf("%d",&E);
    struct Graph* graph = createGraph(V, E); 
    int i;
    printf("Enter 2 vertices and correspoding weight for each edge:\n");
    for(i = 0; i<E; i++)
       scanf("%d %d %d", &graph->edge[i].u, &graph->edge[i].v, &graph->edge[i].weight);
    
    KruskalMST(graph); 
  
    return 0; 
} 