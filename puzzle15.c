#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 4
typedef struct Node{
   int cost, level, blankX, blankY;
   char *pastDirections;
   int state[N][N];
}NODE;

typedef struct heap{
  NODE arr[10000];
  int size;
}HEAP;

void swap(HEAP *heap, int i, int j){
  NODE temp;
  temp = heap->arr[i];
  heap->arr[i] = heap->arr[j];
  heap->arr[j] = temp;
}

void heapifyUp(HEAP *heap, int i){
  if(i==0)
    return;
  int parent = (i%2==0)?((i/2)-1):(i/2);
  if(heap->arr[i].cost>heap->arr[parent].cost)
    return;
  swap(heap, i , parent);
  heapifyUp(heap, parent);
}

void enqueue(HEAP *heap, NODE node){
  heap->arr[heap->size] = node;
  heapifyUp(heap, heap->size);
  heap->size += 1;
}

void heapifyDown(HEAP *heap, int i){
  int l = 2*i+1, r = 2*i + 2, max;
  if((l<heap->size) && (heap->arr[l].cost<heap->arr[i].cost))
    max = l;
  else
    max = i;

  if((r<heap->size) && (heap->arr[r].cost<heap->arr[max].cost))
    max = r;

  if(max != i){
    swap(heap, i, max);
    heapifyDown(heap, max);
  }
}

NODE dequeue(HEAP *heap){
  NODE t = heap->arr[0];
  heap->arr[0] = heap->arr[heap->size-1];
  heap->size-=1;
  heapifyDown(heap, 0);
}

void display(NODE node){
  int i,j;
  for(i=0;i<N;i++){
    for(j=0;j<N;j++)
      printf("%2d ",node.state[i][j]);
    printf("\n");
  }
}

void copyState(NODE *from, NODE *to){
  int i, j;
  for(i = 0; i < N; i++){
    for(j = 0; j < N; j++){
      to->state[i][j] = from->state[i][j];
    }
  }
}

void solved(NODE node){
  printf("The puzzle is solved in %d steps.\n", node.level);
  display(node);
  printf("The steps taken to solve this puzzle is: %s\n", node.pastDirections);
}

void setCost(NODE *node, NODE finalState){
  int i,j;
  printf("setCost %d %d\n", node->cost, node->level);
  node->cost = node->level;
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      if(node->state[i][j]!=finalState.state[i][j])
        node->cost++;
    }
  }
}

void setNode(NODE *temp, NODE *current, char *str){
  temp->level = current->level + 1;
  temp->pastDirections = "";
  strcat(temp->pastDirections, current->pastDirections);
  strcat(temp->pastDirections, str);
  copyState(current, temp);
  temp->state[current->blankX][current->blankY] = temp->state[temp->blankX][temp->blankY];
  temp->state[temp->blankX][temp->blankY] = 0;
}

void solveProblem(HEAP *heap, NODE finalState){
  printf("%d\n", heap->size);
  if(heap->size==0){
    printf("No possible number of moves can restore the inital state to the final state.\n");
    return;
  }
  NODE current = dequeue(heap);
  solved(current);
  if(current.blankX > 0){                //UP
    NODE temp;
    temp.blankX = current.blankX-1;
    temp.blankY = current.blankY;
    setNode(&temp, &current, "U");
    setCost(&temp, finalState);
    printf("%d %d\n", temp.cost, temp.level);
    if(temp.cost == temp.level){
      solved(temp);
      return;
    }
    enqueue(heap, temp);
    printf("Went up\n");
  }
  if(current.blankX < (N-1)){                //DOWN
    NODE temp;
    temp.blankX = current.blankX+1;
    temp.blankY = current.blankY;
    setNode(&temp, &current, "D");
    setCost(&temp, finalState);
    if(temp.cost == temp.level){
      solved(temp);
      return;
    }
    enqueue(heap, temp);
    printf("Went down\n");
  }
  if(current.blankY < (N-1)){                //RIGHT
    NODE temp;
    temp.blankX = current.blankX;
    temp.blankY = current.blankY+1;
    setNode(&temp, &current, "R");
    setCost(&temp, finalState);
    if(temp.cost == temp.level){
      solved(temp);
      return;
    }
    enqueue(heap, temp);
    printf("Went right\n");
  }
  if(current.blankY > 0){                //LEFT
    NODE temp;
    temp.blankX = current.blankX;
    temp.blankY = current.blankY-1;
    setNode(&temp, &current, "L");
    setCost(&temp, finalState);
    if(temp.cost == temp.level){
      solved(temp);
      return;
    }
    enqueue(heap, temp);
    printf("Went left\n");
  }
  solveProblem(heap, finalState);
}

void main (){
	int i, j;
  int start[] = {1,2,3,4,5,6,0,8,9,10,7,11,13,14,15,12};
  int end[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0};
  NODE initial, final;
  HEAP heap;
  heap.size = 0;
  for(i = 0; i < N; i++){
    for(j = 0; j < N; j++){
      initial.state[i][j] = start[i*4+j];
    }
  }
  for(i = 0; i < N; i++){
    for(j = 0; j < N; j++){
      final.state[i][j] = end[i*4+j];
    }
  }
  initial.level = 0;
  initial.blankX = 1;
  initial.blankY = 2;
  initial.pastDirections = "";
  setCost(&initial, final);
  display(initial);
  display(final);
  enqueue(&heap, initial);
  printf("%d\n", heap.size);
  solveProblem(&heap, final);
}


