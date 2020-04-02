/*******************************************************************************************************************************
* Program name      : josephus.c
*
* Author            : Anshuman Dubey
*
* Date created      : 02-11-2019
*
* Question          : Implement queue using Circular linked list and demonstrate JOSEPHUS problem in C.
*
*********************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define ERR -9999999

typedef struct cq{
    int data;
    struct cq *next;
}CQ;


void init(CQ **f, CQ **r){
    *f = *r = NULL;
}

int enque(CQ **f, CQ **r, int n){
    CQ *t;
    int i;
    t = (CQ *)malloc(sizeof(CQ));
    if(t==NULL){
        printf("Memory allocation failure!\n");
        return ERR;
    }
    t->data = n;
    t->next = NULL;
    
    if(*f==NULL){
        *f = t;
        *r = t;
        t->next = t;
        return 0;
    }
    
    (*r)->next  = t;
    *r = t;
    t->next = *f;
    return 0;
}

CQ * execute(CQ *x, CQ *prev, int k){
    if(x==NULL)
        printf("Empty Queue!\n");
    int i = 0;
    CQ *t;
    while(x->next != x){
        for(i = 0; i < k-1; i++){
            prev = x;
            x = x->next;
        }
        t = x;
        prev->next = x->next;
        x = x->next;
        //printf("%d KILLED!\n", t->data);
        free(t);
    }
    return x;
}

void main()
{
    CQ *f, *r;

    init(&f, &r);
    int n, k, i;
    printf("Enter the number of people: ");
    scanf("%d", &n);
    printf("Enter skipping size: ");
    scanf("%d", &k);
    for(i = 0;  i < n; i++)
        enque(&f, &r, i);
    printf("You should be %d places from the starting point.\n", execute(f, r, k)->data);
}