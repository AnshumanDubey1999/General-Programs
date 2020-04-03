#include <stdio.h>
#include <stdlib.h>

#define INFINITY 99999

typedef struct{                              //Declaring a Data Structure QUEUE
    int *a;
    int size;
    int top;
}QUEUE;

void init(QUEUE *q){                            //Initialization
    q->a = (int*)calloc(q->size, sizeof(int));
    q->top = -1;                             //Represents Empty Stack
}

int isFull(QUEUE q){
    return q.top == (q.size-1);
}

int isEmpty(QUEUE q){
    return q.top == -1;
}

void enqueue(QUEUE *q, int n){
	//printf("5\n");
    if(isFull(*q)){
        printf("Queue Overflow!\n");
        return;
    }
    q->a[++(q->top)] = n;                   //add n to top+1 and then increase top by 1
}

int dequeue(QUEUE *q){
    if(isEmpty(*q)){
        printf("Empty Queue!\n");
        return -99999;
    }
    int i, n = q->a[0];
    for(i = 1; i <= q->top; i++)
        q->a[i-1] = q->a[i];     //Shifting everything to the right by 1
    q->top--;
    return n;
}

int BFS(int **graph, int v, char *vertexID){
	//printf("0\n");
	QUEUE q;
	//printf("1\n");
	q.size = v;
	init(&q);
	//printf("2\n");
	int visited[v], i, p;
    for(i=0;i<v;i++)
        visited[i]=0;
    visited[0]=1;
    //printf("3\n");
    enqueue(&q,0);
    printf("Graph Traversal in BFS order: ");
    while(!isEmpty(q)){
        p=dequeue(&q);
        printf("%c, ", vertexID[p]);
        for (i=0;i<v;i++)
	        if(graph[p][i]!=0 && graph[p][i]!=INFINITY && visited[i]==0){
	            enqueue(&q,i);
	            visited[i]=1;
	        }
    }
    printf("\n");
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
	int **graph, i,j,v ,e,s, bi;
	char *vertexID;
	printf("Number of vertices: ");
	scanf("%d%*c",&v);
	vertexID = (char *)malloc(sizeof(char)*v);
	printf("Enter ID for each vertex:\n");
	for (int i = 0; i < v; ++i){
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
	//printSolution(graph, v);
	BFS(graph, v, vertexID); 
	return 0; 
} 