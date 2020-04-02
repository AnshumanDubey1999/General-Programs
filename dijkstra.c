#include<stdio.h>
#include<stdlib.h>
#define INFINITY 99999
#define MAX 10

int minDistance(int distance[], int isVisited[],int V) { 
	int min = INFINITY, min_index; 

	for (int v = 0; v < V; v++) 
		if (isVisited[v] == 0 && distance[v] <= min) {
			min = distance[v];
			min_index = v; 
		}

	return min_index; 
} 

int displaySolution(int distance[],int V, int source) 
{
	int i;
	printf("Distances from %d:\n", (source+1));
	for (i = 0; i < V; i++) 
		printf("%d -> %d : %d\n", (source+1), (i+1), distance[i]); 
} 
void dijkstra(int V,int **graph, int src) 
{
	int i, count, u, v;
	int distance[V];

	int isVisited[V]; 
	
	for (i = 0; i < V; i++){
		distance[i] = INFINITY;
		isVisited[i] = 0; 
	}

	
	distance[src] = 0; 

	
	for (count = 0; count < V - 1; count++) { 
		u = minDistance(distance, isVisited,V); 
		isVisited[u] = 1; 
		for (v = 0; v < V; v++) 
			if (!isVisited[v] && graph[u][v] && (distance[u] != INFINITY) && (distance[u] + graph[u][v] < distance[v])) 
				distance[v] = distance[u] + graph[u][v]; 
	} 

	
	displaySolution(distance,V, src); 
} 

int setAdgecencyMatrix(int** adj, int edges, int vertices, int isBiDirectional){
    int i, j, x , y, w;
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &x, &y, &w);
        adj[x-1][y-1] = w;
        if(isBiDirectional)
            adj[y-1][x-1] = w;
    }
    return 0;
}

int main()
{
	int **adj,i,j,v ,e,s, bi;
	printf("Number of vertices: ");
	scanf("%d",&v);
	adj = (int **)malloc(sizeof(int*)*v);
    for(i = 0; i < v; i++){
        adj[i] = (int *)malloc(sizeof(int)*v);
        for(j = 0; j < v; j++){
            if(i==j)
                adj[i][j] = 0;
            else
                adj[i][j] = INFINITY;
        }
    }
	printf("Number of edges: ");
	scanf("%d",&e);
	printf("Enter 0 if graph is Directed, else enter 1: ");
	scanf("%d", &bi);
	printf("Enter 2 vertices and correspoding weight for each edge:\n");
	setAdgecencyMatrix(adj, e ,v, bi);
	printf("\nEnter starting vertex: ");
	scanf("%d",&s);
	dijkstra(v, adj,s - 1);

	return 0;
}
