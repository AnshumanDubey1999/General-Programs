#include<stdio.h>
#include<stdlib.h>
#define INFINITE 10000
#define EMPTY_ERROR -9999

typedef struct {
    int n;
    char *V;
    int **wt; 
}GRAPH;

typedef struct{
    int top;
    int *vertex;
}STACK;

typedef struct{
    int front, rear;
    int *vertex;
}QUEUE;

void input_graph(GRAPH *aG){
    int i,j;
    char ans;
    printf("\n Enter the no. of vertices :");
    scanf("%d",&aG->n);
    getchar();
    aG->V=(char *)malloc(sizeof(char)*aG->n);
    for(i=0;i<aG->n;i++)
        aG->V[i]='A'+i;
    aG->wt=(int **)malloc(sizeof(int *)*aG->n);
    for(i=0; i<aG->n; i++)
        aG->wt[i]=(int *)malloc(sizeof(int)*aG->n);
    for(i=0; i<aG->n; i++)
    for(j=0; j<aG->n; j++){
        printf("\n Is any edge between %d and %d? Answer (Y/N):",i+1,j+1);
        scanf("%c",ans);
        if(ans=='y'||ans=='Y'){
            printf("\n Enter edge cost between %d and %d :",i+1,j+1);
            scanf("%d",&aG->wt[i][j]);
        } 
        else
            aG->wt[i][j]=INFINITE;
    }
}


void initialisation_stack(STACK *s, int stack_size){
    s->top=-1;
    s->vertex=(int *)malloc(sizeof(int)*stack_size);
}

void initialisation_queue(QUEUE *q, int queue_size){
    q->front=-1;
    q->rear=-1;
    q->vertex=(int *)malloc(sizeof(int)*queue_size);
}

void push(STACK *s, int v){
    s->vertex[++(s->top)]=v;
}

void insert_q(QUEUE *q, int v){
    q->vertex[++(q->rear)]=v;
}

int pop(STACK *s){
    if(s->top==-1){
        printf("\n Empty stack...");
        return EMPTY_ERROR;
    }
    return s->vertex[(s->top)--]; 
}

int delete_q(QUEUE *q){
    if(q->front==q->rear){
       printf("\n Empty queue...");
       q->front=-1;
       q->rear=-1;
       return EMPTY_ERROR;
    }
    else
       return q->vertex[++(q->front)];
}

void DFS(GRAPH G, int v){
    STACK stk;
    int *visited;
    int i, p;
    printf("\n");
    initialisation_stack(&stk, G.n);
    visited=(int *)malloc(sizeof(int)*G.n);
    for(i=0;i<G.n;i++)
        visited[i]=0;
    visited[v]=1;
    push(&stk,v);
    while(stk.top!=-1){
        p=pop(&stk);
        printf("Visited %c  ", G.V[p]);
        for (i=0;i<G.n;i++)
            if(G.wt[p][i]!=0 && G.wt[p][i]!=INFINITE && visited[i]==0){
                push(&stk,i);
                visited[i]=1;
            }
    }
    free(visited);
    printf("\n");
}

void BFS(GRAPH G, int v){
    QUEUE queue;
    int *visited;
    int i, p;
    printf("\n");
    initialisation_queue(&queue, G.n);
    visited=(int *)malloc(sizeof(int)*G.n);
    for(i=0;i<G.n;i++)
        visited[i]=0;
    visited[v]=1;
    insert_q(&queue,v);
    while(queue.front != queue.rear){
        p=delete_q(&queue);
        printf("Visited %c  ", G.V[p]);
        //printf("\n %d %d", queue.front, queue.rear);
        for (i=0;i<G.n;i++)
        if(G.wt[p][i]!=0 && G.wt[p][i]!=INFINITE && visited[i]==0){
            insert_q(&queue,i);
            visited[i]=1;
        }
    }
    free(visited);
    printf("\n");
}

void free_graph (GRAPH *G){
    int i,j;

    free(G->V);
    for(i=0; i<G->n; i++)
        free(G->wt[i]);
    free(G->wt);
}

void main()  {
    GRAPH *G;
    G=(GRAPH *)malloc(sizeof(GRAPH));
    input_graph(G);
    DFS(*G, 0);
    BFS(*G, 0);
    free_graph(G);
}
