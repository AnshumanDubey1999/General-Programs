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


/*
                            ALGORITHM
Step 1: Start
Step 2: V is the number of vertices, visited[V] is array containing all 0's, graph[V][V] is the adjacency matrix of the graph and s is an Empty Stack Data Structure.
Step 3: Push 0 in s
Step 4: Set visited[0]=1
Step 5: If s is not empty go to next step, else go to step 6.
        Step 5.1:   Set Integer p = pop(s) and i = 0
        Step 5.2:   Print p
        Step 5.3:   If i<V, go to next step, else go to step 5
                Step 5.31:  If graph[p][i]!=0 and graph[p][i]!=INFINITY and visited[i]==0, Push i in s and set visited[i]=1
                Step 5.32:  Increase i by 1 and go to step 5.3
Step 6: Stop
*/