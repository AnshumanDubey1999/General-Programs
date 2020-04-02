/*******************************************************************************************************************************
* Program name      : doubleQueue.c
*
* Author            : Anshuman Dubey
*
* Date created      : 02-11-2019
*
* Question          : Write a menu driven C program to implement double ended queue.
*
*********************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{                              //Declaring a Data Structure QUEUE
    int *a;
    int size, front, rear;
}QUEUE;

void init(QUEUE *q){                            //Initialization
    q->a = (int*)calloc(q->size, sizeof(int));
    q->front = q->rear = -1;                             //Represents Empty QUEUE
}

int isEmpty(QUEUE *q){
    if(q->front == -1 && q->rear == -1)
        return 1;
    return 0;
}

void enQueue_left(QUEUE *q, int element){
    if(q->front == 0){
        printf("No space in front!\n");
        return;
    }
    if(isEmpty(q)){                     //For empty queue
        q->front = 0;
        q->rear = 0;
    }
    else
        q->front -= 1;
    q->a[q->front] = element;
    printf("Inserted: %d.\n", element);
}
void enQueue_right(QUEUE *q, int element){
    if(q->rear == q->size-1){
        printf("No space in rear!\n");
        return;
    }
    if(isEmpty(q)){                     //For empty queue
        q->front = 0;
        q->rear = 0;
    }
    else
        q->rear += 1;
    q->a[q->rear] = element;
    printf("Inserted: %d.\n", element);
}
int deQueue_left(QUEUE *q){
    int element;
    if(isEmpty(q)) {
        printf("Empty Queue!\n");
        return(-1);
    }
    element = q->a[q->front];
    if (q->front == q->rear){
        q->front = -1;
        q->rear = -1;
    }// Reset to empty Queue
    else 
        q->front += 1;
    printf("Deleted element: %d.\n", element);
    return(element);
}
int deQueue_right(QUEUE *q){
    int element;
    if(isEmpty(q)) {
        printf("Empty Queue!\n");
        return(-1);
    }
    element = q->a[q->rear];
    if (q->front == q->rear){
        q->front = -1;
        q->rear = -1;
    }// Reset to empty Queue
    else 
        q->rear -= 1;
    printf("Deleted element: %d.\n", element);
    return(element);
}
void display(QUEUE *q){
    int i;
    if(isEmpty(q)){
        printf("Empty Queue!\n");
        return;
    }
    printf("Elements: ");
    for(i = q->front; i!=q->rear; i++) {
        printf("%3d, ",q->a[i]);
    }
    printf("%3d.\n",q->a[i]);
}


void main(){
    QUEUE q;
    int c=0, n;

    printf(" Enter the size of the queue: ");
    scanf("%d", &q.size);                          //Getting size for queue
    init(&q);
    while(c!=6){
        printf("\n      --: MENU :--\n");
        printf(" 1. Insert Left\n 2. Insert Right\n 3. Delete Left\n 4. Delete Right\n 5. Display\n 6. Exit\n    Enter your choice: ");
        scanf("%d", &c);
        
        if(c==1){
            printf(" Enter number: ");
            scanf("%d", &n);
            enQueue_left(&q, n);
        }
        else if(c==2){
            printf(" Enter number: ");
            scanf("%d", &n);
            enQueue_right(&q, n);
        }
        else if(c==3)
            deQueue_left(&q);
        else if(c==4)
            deQueue_right(&q);
        else if(c==5)
            display(&q);
        else if(c!=6)
            printf("Invalid Input!\nPlease try again.\n");
    }
    printf("Thank You!\n");
}