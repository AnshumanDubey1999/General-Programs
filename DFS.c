#include <stdio.h>
#include <stdlib.h>

#define INFINITY 99999

int **graph, *visited, v;
char *vertexID;

int DFS(int current){
    printf("%c, ", vertexID[current]);
	int i;
    visited[current]=1;
    for (i=0;i<v;i++)
        if(graph[current][i]!=0 && graph[current][i]!=INFINITY && visited[i]==0)
            DFS(i);
}


int setAdgecencyMatrix(int **adj, int edges, int vertices, int isBiDirectional){
	//printSolution(adj, vertices);
    int i, j, x , y;
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &x, &y);
        adj[x][y] = 1;
        if(isBiDirectional)
            adj[y][x] = 1;
    }
    return 0;
}

int main() {
	int  i,j ,e,s, bi;
	printf("Number of vertices: ");
	scanf("%d%*c",&v);
	vertexID = (char *)malloc(sizeof(char)*v);
    visited = (int *)malloc(sizeof(int)*v);
	printf("Enter ID for each vertex:\n");
	for (int i = 0; i < v; ++i){
        visited[i] = 0;
		printf("Vertex %d --> ", i);
		scanf("%c%*c", &vertexID[i]);
	}
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
	printf("Enter 2 vertices each edge:\n");
	setAdgecencyMatrix(graph, e ,v, bi);
    printf("Graph Traversal in DFS order: ");
	DFS(0); 
    printf("\n");
	return 0; 
} 