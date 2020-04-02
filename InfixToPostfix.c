/*******************************************************************************************************************************
* Program name      : inToPost.c
*
* Author            : Anshuman Dubey
*
* Date created      : 02-11-2019
*
* Question          : Write a C program to convert a given infix expression to postfix expression.
*
*********************************************************************************************************************************/

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

void push(STACK *s, int n){
    if(s->top == (s->size-1)){
        printf("Stack Overflow!\n");
        return;
    }
    s->a[++(s->top)] = n;                   //add n to top+1 and then increase top by 1
}

int pop(STACK *s){
    if(s->top == -1){
        return -99999;
    }
    return s->a[(s->top)--];                //send a[top] and then reduce top by 1
}

int peek(STACK *s){
    if(s->top == -1){
        return -99999;
    }
    return s->a[s->top];                //send a[top] and then reduce top by 1
}

int isOperand(char ch) { 
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch>='0' && ch<='9'); 
} 

int prec(char ch) { 
    switch (ch) { 
        case '+': 
        case '-': 
            return 1; 
      
        case '*': 
        case '/': 
            return 2; 
      
        case '^': 
            return 3; 
    } 
    return -1; 
} 

void main(){
    STACK s;
    s.size = 100;           //Size of stack
    init(&s);

    char eq[100];
    printf("Enter the infix equation: ");
    scanf("%[^\n]%*c", eq);

    int i, k; 
  
    for (i = 0, k = -1; eq[i] != '\0'; i++) { 
        if (isOperand(eq[i])) 
            eq[++k] = eq[i]; 
          
        else if (eq[i] == '(') 
            push(&s, eq[i]); 
          
        else if (eq[i] == ')') { 
            while (s.top!=-1 && peek(&s) != '(') 
                eq[++k] = pop(&s); 
            if (s.top!=-1 && peek(&s) != '('){
                printf("Invalid Equation!\n");
                return;              
            }
            else
                pop(&s); 
        } 
        else { 
            while (s.top!=-1 && prec(eq[i]) <= prec(peek(&s))) 
                eq[++k] = pop(&s); 
            push(&s, eq[i]); 
        }  
    }

    while (s.top!=-1) 
        eq[++k] = pop(&s); 
  
    eq[++k] = '\0'; 
    printf("Postfix equation: %s\n", eq ); 
}