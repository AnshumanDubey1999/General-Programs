#include<stdio.h>
#include<stdlib.h>
#define MemErr -98879898
#define EmptyErr -98787984
#define IndexOutOfBoundErr -98781244

typedef struct node{
    int data;
    struct node *next;
}NODE;

void init(NODE **aah){
    *aah = NULL;
}

int sortedInsertion(NODE **aah, int n){
    NODE *t, *i;
    t = (NODE*)malloc(sizeof(NODE));
    if(t==NULL)
        return MemErr;
    t->data = n;

    if(*aah==NULL || (*aah)->data > n){
        t->next = *aah;
        *aah=t;
        return 0;
    }

    i = *aah;
    while(i->next!=NULL && (i->next)->data < n)
        i = i->next;

    t->next = i->next;
    i->next = t;
    return 0;
}

int display(NODE *ah){
    if(ah==NULL)
        return EmptyErr;
    printf(" The linked list contains : ");
    while(ah->next != NULL){
        printf(" %3d, ", ah->data);
        ah = ah->next;
    }
    printf(" %3d.\n", ah->data);
    return 0;
}

int reverse(NODE **aah){
    if(*aah==NULL)
        return EmptyErr;

    NODE *i, *e = *aah;
    i = e->next;
    //display(*aah);
    while(i!=NULL){
        e->next = i->next;
        i->next = *aah;
        *aah = i;
        i = e->next;
        //display(*aah);
    }
    return 0;
}

int delete(NODE **aah, int index){
    if(*aah==NULL)
    return EmptyErr;

    NODE *i, *p, *t;
    int num;
    i = *aah;
    p = NULL;

    while(i!=NULL && index>0){
        p = i;
        i = i->next;
        index--;
    }

    if(index!=0 || i==NULL)
        return IndexOutOfBoundErr;

    t = p->next;
    num = t->data;
    p->next = i->next;
    free(t);
    return num;
}



int sort(NODE **aah){
    if(*aah == NULL)
        return EmptyErr;

    NODE *i = *aah, *sortedList, *t;
    init(&sortedList);
    while(i!=NULL){
        sortedInsertion(&sortedList, i->data);
        t = i;
        i = i->next;
        free(t);
    }
    *aah = sortedList;
    return 0;
}

void main(){
    NODE *ah;
    init(&ah);
    int c = 0, n, i;

    while(c !=6){
        printf("\n -: MENU :-\n");
        printf(" 1. Insert (Ascending Order)\n");
        printf(" 2. Display\n");
        printf(" 3. Reverse\n");
        printf(" 4. Delete (by Index)\n");
        printf(" 5. Sort (Ascending Order)\n");
        printf(" 6. Exit\n");
        printf(" Enter your choice : ");
        scanf("%d", &c);

        if(c==1){
            printf("\n Enter the number to be inserted : ");
            scanf("%d", &n);
            if(sortedInsertion(&ah, n)==MemErr)
                printf(" MEMORY ALLOCATION FAILURE!\n");
            else
                printf(" %d was successfully added.\n", n);
        }
        else if(c==2){
            if(display(ah))
                printf(" EMPTY LIST!\n");
        }
        else if(c==3){
            if(reverse(&ah))
                printf(" EMPTY LIST!\n");
            else
                printf(" List successfully reversed.\n");
        }
        else if(c==4){
            printf("\n Enter the index to be deleted : ");
            scanf("%d", &i);
            n = delete(&ah, i);
            if(n==EmptyErr)
                printf(" EMPTY LIST!\n");
            else if(n==IndexOutOfBoundErr)
                printf(" INDEX OUT OF BOUND!\n");
            else
                printf(" %d was successfully deleted from index %d.", n, i);
        }
        else if(c==5){
            if(sort(&ah))
                printf(" EMPTY LIST!\n");
            else
                printf(" List successfully sorted in Ascending Order.\n");
        }
        else if(c!=6)
            printf(" INVALID INPUT!\n Please try again.\n");
    }
    printf(" Thank You.\n");
}