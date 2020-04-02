#include<stdio.h> 
#include<stdlib.h>
#define INFINITY 99999 


void printSolution(int **dist, int V) 
{ 
	printf ("The all-pair-shortest-path is represented by the matrix: \n"); 
	for (int i = 0; i < V; i++) 
	{ 
		for (int j = 0; j < V; j++) 
		{ 
			if (dist[i][j] == INFINITY) 
				printf("%7s", "INF"); 
			else
				printf ("%7d", dist[i][j]); 
		} 
		printf("\n"); 
	} 
}

void floydWarshall (int **graph, int V) 
{ 
	int **dist, i, j, k;
	dist = (int **)malloc(sizeof(int*)*V);
    for(i = 0; i < V; i++){
        dist[i] = (int *)malloc(sizeof(int)*V);
        for(j = 0; j < V; j++){
            if(i==j)
                dist[i][j] = 0;
            else
                dist[i][j] = INFINITY;
        }
    }
	for (i = 0; i < V; i++) 
		for (j = 0; j < V; j++) 
			dist[i][j] = graph[i][j]; 
	for (k = 0; k < V; k++) {
		for (i = 0; i < V; i++) { 
			for (j = 0; j < V; j++) { 
				if (dist[i][k] + dist[k][j] < dist[i][j]) 
					dist[i][j] = dist[i][k] + dist[k][j]; 
			} 
		} 
	} 
	printSolution(dist, V); 
} 

int setAdgecencyMatrix(int **adj, int edges, int vertices, int isBiDirectional){
	//printSolution(adj, vertices);
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
	int **graph, i,j,v ,e,s, bi;
	printf("Number of vertices: ");
	scanf("%d",&v);
	graph = (int **)malloc(sizeof(int*)*v);
    for(i = 0; i < v; i++){
        graph[i] = (int *)malloc(sizeof(int)*v);
        for(j = 0; j < v; j++){
            if(i==j)
                graph[i][j] = 0;
            else
                graph[i][j] = INFINITY;
        }
    }
	//printSolution(graph, v);
	printf("Number of edges: ");
	scanf("%d",&e);
	printf("Enter 0 if graph is Directed, else enter 1: ");
	scanf("%d", &bi);
	printf("Enter 2 vertices and correspoding weight for each edge:\n");
	setAdgecencyMatrix(graph, e ,v, bi);
	//printSolution(graph, v);

	floydWarshall(graph, v); 
	return 0; 
} 
