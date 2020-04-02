#include <stdio.h>
#include <stdlib.h>

#define INFINITY 99999

struct Edge {
	int u;	
	int v;	
	int w;	
};

struct Graph {
	int V;	
	int E;	
	struct Edge *edge;	
};

int displaySolution(int *distance,int V, int source) {
	int i;
	printf("Distances from %d:\n", (source+1));
	for (i = 0; i < V; i++) 
		printf("%d -> %d : %d\n", (source+1), (i+1), distance[i]); 
} 

int bellmanFord(struct Graph* graph, int source){
	int V,E,i,j,u,v,w;
    V = graph->V;
	E = graph->E;
    int distance[V];

    for (i = 0; i < V; i++)
        distance[i] = INFINITY;

    distance[source] = 0;

    for (i = 1; i <= V-1; i++){
        for (j = 0; j < E; j++){
            u = graph->edge[j].u;
            v = graph->edge[j].v;
            w = graph->edge[j].w;
            if (distance[u] + w < distance[v])
                distance[v] = distance[u] + w;
        }
    }

    for (i = 0; i < E; i++){
        u = graph->edge[i].u;
        v = graph->edge[i].v;
        w = graph->edge[i].w;
        if (distance[u] + w < distance[v]){
            printf("This graph contains negative edge cycle\n");
            return 0;
        }
    }

    displaySolution(distance, V, source);

    return 0;
}

int main() {
	struct Graph *g = (struct Graph*)malloc(sizeof(struct Graph));
	printf("Number of vertices: ");
	scanf("%d",&g->V);
	printf("Number of edges: ");
	scanf("%d",&g->E);
	
	g->edge = (struct Edge*)malloc(g->E * sizeof(struct Edge));

	int i, src;
	printf("Enter 2 vertices and correspoding weight for each edge:\n");
    for(i = 0; i<(g->E); i++)
       scanf("%d %d %d", &g->edge[i].u, &g->edge[i].v, &g->edge[i].w);
	
	printf("\nEnter starting vertex: ");
	scanf("%d",&src);
	
	bellmanFord(g, src);
	
	return 0;
}