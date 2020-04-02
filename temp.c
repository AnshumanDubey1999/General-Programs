#include<stdio.h>


#define INFINITY 99999

#define MAX 10


void dijkstra(int Graph[MAX][MAX],int n,int start)
{

int cost[MAX][MAX],dist[MAX],pred[MAX];
int visited[MAX],count,mindistance,next,i,j;

for(i=0;i<n;i++)

		for(j=0;j<n;j++)

			if(Graph[i][j]==0)

				cost[i][j]=INFINITY;

			else

				cost[i][j]=Graph[i][j];

	for(i=0;i<n;i++)

	{

		dist[i]=cost[start][i];

		pred[i]=start;

		visited[i]=0;

	}


	dist[start]=0;

	visited[start]=1;

	count=1;


	while(count<n-1)

	{

		mindistance=INFINITY;

		for(i=0;i<n;i++)

			if(dist[i]<mindistance&&!visited[i])

			{

				mindistance=dist[i];

				next=i;

			}


			visited[next]=1;

			for(i=0;i<n;i++)

				if(!visited[i])

					if(mindistance+cost[next][i]<dist[i])

					{

						dist[i]=mindistance+cost[next][i];

						pred[i]=next;

					}

		count++;

	}


	for(i=0;i<n;i++)

		if(i!=start)

		{

			printf("\nDistance of node%d=%d",i,dist[i]);

			printf("\nPath=%d",i);


			j=i;

			do

			{

				j=pred[j];

				printf("<-%d",j);

			}while(j!=start);

	}

}


int main()

{

	int Graph[MAX][MAX],i,j,Ver,s;

	printf("no. of vertices:");

	scanf("%d",&Ver);

	printf("\nadjacency matrix:\n");


	for(i=0;i<Ver;i++)

		for(j=0;j<Ver;j++)

			scanf("%d",&Graph[i][j]);


	printf("\nstarting node:");

	scanf("%d",&s);

	dijkstra(Graph,Ver,s - 1);


	return 0;

}