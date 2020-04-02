#include <stdio.h>
#include <stdlib.h>

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

int display(QUEUE *q){
    if(isEmpty(*q)){
        printf("Empty Queue!\n");
        return -99999;
    }
    int i;
    printf("Queue elements:");
    for(i = 0; i <= q->top; i++)
        printf("%3d, ", q->a[i]);
    printf("\n");
    return 0;
}

void main(){
    int choice = 0, n;
    QUEUE q;
    printf(" Enter the size of the queue: ");
    scanf("%d", &q.size);                          //Getting size for queue 
    init(&q);                              //Initialization
    while(choice!=4){
        printf("\n   --: MENU :--\n");
        printf(" 1. Enqueue\n 2. Dequeue\n 3. Display\n 4. Exit\n Enter your choice : ");
        scanf("%d", &choice);

        if(choice==1){                   
            printf(" Enter the number to be inserted: ");
            scanf("%d", &n);
            enqueue(&q, n);
        }
        else if(choice==2){
            n = dequeue(&q);
            if(n!=-99999)              //If empty stack
                printf(" %d was removed successfully.\n", n);
        }
        else if(choice==3)
            display(&q);
        else if(choice!=4){
            printf(" Invalid Input. Please try again.\n");
        }
    }
    printf("Thank You!\n");
}
