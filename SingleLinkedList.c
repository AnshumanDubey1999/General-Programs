#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
        int data;
        struct node *next;
}Node;

void init(Node **aah){
    *aah = NULL;
}

int add(Node **aah, int n){                           //Insert in end
    Node *temp = (Node *)malloc(sizeof(Node));        //Creating Node;
    if(temp == NULL){
            printf("Memory allocation failure.\n");
            return 0;
    }
    temp->data = n;
    temp->next = NULL;

    if(*aah == NULL){ 
        *aah = temp;                           //Value at Pointer to Address of Header is changed, i.e. Address of header changes
        return 1;
    }
    
    Node *prev, *nxt;
    prev = NULL;
    nxt = *aah;
    while(nxt!=NULL){               //Until the list finishes
        prev = nxt;
        nxt = nxt->next;
    }
    prev->next = temp;
    return 1;
}

int removeValue(Node **aah, int n){
    Node *del,*prev,*cur;
    cur = *aah;
    prev = NULL;
    while(cur!=NULL){
        if(n==cur->data){
            del = cur;
            if(prev!=NULL)
                prev->next = cur->next;
            else
                *aah = cur->next;
            free(del);
            printf("Deletion is successful.\n");
            return 1;
        }
        else{
            prev = cur;
            cur = cur->next;
        }
    }
    printf("Element not found.\n");   //If found, the control will never go to this line
    return 0;
}

void display(Node *ah){
    if(ah==NULL){
        printf("Empty Linked List!\n");
        return;
    }
    Node *nxt = ah;
    printf("\nCurrent List : ");
    while(nxt!=NULL){
        printf("%3d", nxt->data);
        nxt = nxt->next;
    }
    printf("\n");
}


void sort(Node **aah){
    if(*aah == NULL){
        printf("Empty Linked List!\n");
        return;
    }
    int swapped, temp;
    Node *i, *last;
    last = NULL;
    while(last != *aah){              //Bubble Sort
        swapped = 0;
        i = *aah;
        while(i->next != last){
            if(i->data > i->next->data){
                temp = i->data;
                i->data = i->next->data;
                i->next->data = temp;
                swapped = 1;
            }
            i = i->next;
        }
        last = i;
        if(!swapped)
            break;
    }
}

void reverse(Node** aah, Node *i, Node *prev) {
    Node *t;
    if(i == NULL)
        return;
    else
        reverse(aah, i->next, i);
    if(i->next == NULL){
        i->next = *aah;
        *aah = i;
    }
    else if(prev != NULL){
        t = i->next;
        i->next = t->next;
        t->next = i;
    }
    else
        i->next = NULL;
} 

void main(){
    Node *ah;
    init(&ah);

    int n, choice = 0;

    while(choice!=6){
        printf("\n       --: MENU :--      \n");
        printf(" 1. Add\n");
        printf(" 2. Remove\n");
        printf(" 3. Reverse\n");
        printf(" 4. Sort\n");
        printf(" 5. Display\n");
        printf(" 6. Exit\n");
        printf("\n Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1){
            printf(" Enter the number to be added: ");
            scanf("%d", &n);
            if(add(&ah, n))
                printf("\n%d successfully added.\n", n);
            else
                printf("\n%d couldn't be added.\n", n);
        }
        else if(choice == 2){
            printf(" Enter the number to be removed: ");
            scanf("%d", &n);
            if(removeValue(&ah, n))
                printf("\n%d successfully removed.\n", n);
            else
                printf("\n%d couldn't be added.\n", n);
        }
        else if(choice == 3)
            reverse(&ah, ah, NULL);

        else if(choice == 4)
            sort(&ah);

        else if(choice == 5)
            display(ah);

        else if(choice != 6)
            printf("Invalid Input. Please try again.\n");

    }
    
}