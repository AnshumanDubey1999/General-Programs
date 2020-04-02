#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
        int coefficient, exponent;
        struct node *next;
}Node;

void init(Node **aah){
    *aah = NULL;
}

void sortedAddition(Node **aah, int c, int e){
    Node *temp = (Node *)malloc(sizeof(Node));        //Creating Node;
    if(temp == NULL){
            printf("Memory allocation failure.\n");
            return;
    }
    temp->coefficient = c;
    temp->exponent = e;
    
    if(*aah == NULL){  
        *aah = temp;                                 //Value at Pointer to Address of Header is changed, i.e. Address of header changes
        temp->next = NULL;                     //Setting up the first node
        return;
    }

    Node *prev, *nxt;
    prev = NULL;
    nxt = *aah;
    while(nxt != NULL && (nxt->exponent)>e){
        prev = nxt;
        nxt = nxt->next;
    }
    if(nxt!= NULL && nxt->exponent == e){             //If exponent already present, add coefficent
        nxt->coefficient += c;
        return;
    }
    if(prev == NULL){
        temp->next = *aah;
        *aah = temp;
    }
    else{
        prev->next = temp;
        temp->next = nxt;
    }
}

void input(Node **aah, char *equation){
    char ch = equation[0];
    int c = 0, e = 0, isExponent = 0, isNegetive = 0, hasX=0;

    for (int i = 0; ch != '\0'; i++){
        ch = equation[i];
        //printf("%c\n", ch);

        if(ch=='x' || ch=='X'){
            if(c==0)
                c=1;
            isExponent = 1;
            hasX = 1;
        }

        else if(ch == ' ' || ch == '\0'){
            if(c==0)
                continue;

            if(isNegetive)
                c *= -1;
            if(hasX && e==0)
                e=1;
            sortedAddition(aah, c, e);
            c = 0;
            e = 0;
            isExponent = 0;
            isNegetive = 0;
            hasX = 0;
        }

        else if(ch == '-')
            isNegetive = 1;

        else if(ch>='0' && ch<='9'){
            if(isExponent)
                e = e*10 + (ch-'0');
            else
                c = c*10 + (ch-'0') ;
        }

    }
}

void add(Node *a, Node *b, Node **c){
    while(a!=NULL){
        sortedAddition(c, a->coefficient, a->exponent);
        a = a->next;
    }
    while(b!=NULL){
        sortedAddition(c, b->coefficient, b->exponent);
        b = b->next;
        
    }
}

void display(Node *aah){
    if(aah == NULL){
        printf("1");
        return;
    }

    int c, e;
    Node *i;
    i = aah;
    while(i!=NULL){
        c = i->coefficient;
        e = i->exponent;
        if(e==0)
            printf("%+d ", c);
        else if(e==1)
            printf("%+dx ", c);
        else if(c==1)
            printf(" x^%d ", e);
        else if(c!=0)
            printf("%+dx^%d ", c, e);
        i = i->next;
    }
}

void main(){
    Node *p1, *p2, *p4;
    init(&p1);
    init(&p2);
    init(&p4);
    char eq[1000];

    printf("Enter the 1st polynomial(with spaces): ");
    scanf("%[^\n]%*c", eq);
    input(&p1, eq);

    //printf("%s\n", eq);

    printf("Enter the 2nd polynomial(with spaces): ");
    scanf("%[^\n]%*c", eq);
    input(&p2, eq);

    add(p1, p2, &p4);
    //printf("%s\n", eq);


    printf("      ");
    display(p1);
    printf("\n +    ");
    display(p2);
    printf("\n");
    for (int i = 0; i < 75; ++i)
        printf("-");
    printf("\n =    ");
    display(p4);
    printf("\n");
    for (int i = 0; i < 75; ++i)
        printf("-");
    printf("\n");
}