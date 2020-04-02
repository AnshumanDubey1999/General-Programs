#include<stdio.h>
#include<stdlib.h>

typedef struct avl{
    int data, ht;
    struct avl *l, *r;
}node;

int max(int a, int b){
    return a>b?a:b;
}

int height(node *aah){
    if(aah == NULL)
        return 0;
    return aah->ht;
}

node *rr(node *y){
    node *x = y->l;
    node *T2 = x->r;
    
    //rotation
    x->r = y;
    y->l = T2;
    
    //Height update
    y->ht = max(height(y->l), height(y->r))+1;
    x->ht = max(height(x->l), height(x->r))+1;
    
    return x;
}

node *lr(node *x){
    node *y = x->r;
    node *T2 = y->l;
    
    //rotation
    y->l = x;
    x->r = T2;
    
    //Height update
    x->ht = max(height(x->l), height(x->r))+1;
    y->ht = max(height(y->l), height(y->r))+1;
    
    return y;
}

int getBalance(node *n){
    if(n==NULL)
        return 0;
    return height(n->l)-height(n->r);
}

node *create(int data){
    node *n = (node *)malloc(sizeof(node));
    n->data = data;
    n->l = n->r = NULL;
    n->ht = 1;
    return n;
} 

node *insert(node *n, int data){
    if(n == NULL)
        return create(data);
        
    if(data < n->data)
        n->l = insert(n->l, data);
    else if(data>n->data)
        n->r = insert(n->r, data);
    else
        return n;
    //height update
    n->ht = 1 + max(height(n->l), height(n->r));
    
    int bal = getBalance(n);
    
    //LLC
    if(bal > 1 && data<(n->l->data))
        return rr(n);
    //RRC
    if(bal<-1 && data>(n->r->data))
        return lr(n);
    //LRC
    if(bal > 1 && data>(n->l->data)){
        n->l = lr(n->l);
        return rr(n);
    }
    //RLC
    if(bal<-1 && data<n->r->data){
        n->r = rr(n->r);
        return lr(n);
    }
    
    //If already balanced
    return n;
}


void preOrder(node *n){
    if(n != NULL){
        printf("%3d, ", n->data);
        preOrder(n->l);
        preOrder(n->r);
    }
}

void inOrder(node *n){
    if(n != NULL){
        inOrder(n->l);
        printf("%3d, ", n->data);
        inOrder(n->r);
    }
}

void main(){
    int size;
    printf("Enter the number of inputs: ");
    scanf("%d", &size);
    node *root = NULL;
    printf("Enter %d Numbers to be inserted:\n", size);
    int n, i;
    for(i = 0; i < size; i++){
        scanf("%d", &n);
        root = insert(root, n);
        preOrder(root);
        printf("\n");
        inOrder(root);
        printf("\n");
    }
}