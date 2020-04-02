#include <stdio.h>
#include <stdlib.h>

typedef struct{                              //Declaring a Data Structure STACK
    int *a;
    int size;
    int top;
}STACK;

void init(STACK *s){                            //Initialization
    s->a = (int*)calloc(s->size, sizeof(int));
    s->top = -1;                             //Represents Empty Stack
}

int isFull(STACK s){
    return s.top == (s.size-1);
}

int isEmpty(STACK s){
    return s.top == -1;
}

void push(STACK *s, int n){
    if(isFull(*s)){
        printf("Stack Overflow!\n");
        return;
    }
    s->a[++(s->top)] = n;                   //add n to top+1 and then increase top by 1
}

int pop(STACK *s){
    if(isEmpty(*s)){
        printf("Empty Stack!\n");
        return -99999;
    }
    return s->a[(s->top)--];                //send a[top] and then reduce top by 1
}

int peek(STACK *s){
    if(isEmpty(*s)){
        printf("Empty Stack!\n");
        return -99999;
    }
    return s->a[s->top];                     //send a[top] without reducing top by 1
}

void main(){
    int choice = 0, n;
    STACK s;
    printf(" Enter the size of the stack: ");
    scanf("%d", &s.size);                          //Getting size for stack 
    init(&s);                              //Initialization
    while(choice!=4){
        printf("\n   --: MENU :--\n");
        printf(" 1. Push\n 2. Pop\n 3. Peek\n 4. Exit\n Enter your choice : ");
        scanf("%d", &choice);

        if(choice==1){                   
            printf(" Enter the number to be inserted : ");
            scanf("%d", &n);
            push(&s, n);
        }
        else if(choice==2){
            n = pop(&s);
            if(n!=-99999)              //If empty stack
                printf(" %d was popped out successfully.\n", n);
        }
        else if(choice==3){
            n = peek(&s);
            if(n!=-99999)              //If empty stack
                printf(" The last entered value in stack is %d.\n", n);
        }
        else if(choice!=4){
            printf(" Invalid Input. Please try again.\n");
        }
    }
    printf("Thank You!\n");
}
