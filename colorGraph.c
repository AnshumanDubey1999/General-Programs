#include<stdio.h>
#include<stdlib.h>


int canColor(int **adj ,int *colors,int color,int start){
	int i;
    for(i = 0; i < start; i++){
        if(adj[start][i]==1 && color==colors[i])
            return 0;
    }
    return 1;
}

int startColoring(int **adj,int V,int start,int *colors){
	int i;
    if(start==V)
    	return 1;
    for(i = 0; i < V; i++){
        if(canColor(adj,colors,i,start)){
            colors[start]=i;
	        if(startColoring(adj,V,start+1,colors))
	        	return 1;
        }
    }
    return 0;
}

int setAdgecencyMatrix(int** adj, int edges, int vertices, int isBiDirectional){
    int i, x , y;
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &x, &y);
        adj[x-1][y-1] = 1;
        if(isBiDirectional)
            adj[y-1][x-1] = 1;
    }
    return 0;
}

int main()
{
	int **adj,i,j,v,e, *colors, max=0;
	printf("Number of vertices: ");
	scanf("%d",&v);
	colors = (int *)malloc(sizeof(int)*v);
	adj = (int **)malloc(sizeof(int*)*v);
    for(i = 0; i < v; i++){
        adj[i] = (int *)malloc(sizeof(int)*v);
        for(j = 0; j < v; j++)
            adj[i][j] = 0;
    }
	printf("Number of edges: ");
	scanf("%d",&e);
	printf("Enter 2 vertices that form an edge:\n");
	setAdgecencyMatrix(adj, e ,v, 1);
	startColoring(adj, v, 0, colors);
	printf("Order of painting: ");
    for(i = 0; i < v; i++){
    	if(colors[i]>max)
    		max = colors[i];
        printf("%d, ",colors[i]);
    }
    printf("\nNumber of differevt colors required: %d.\n", (max+1));
	return 0;
}
