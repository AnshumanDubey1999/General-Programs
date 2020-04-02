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

void display(CQ *ah, CQ *f){          //Prints from index 2 to n
	if(ah==f)
		return;
	printf("%3d, ", ah->data);
	display(ah->next, f);
}


int deque(CQ **f, CQ **r){
	CQ *t;
	int n;
	if(*f==NULL){
		printf("Empty Queue!\n");
		return ERR;
	}
		
	t = *f;
	n = t->data;
	if(*f==*r){
		*f = *r = NULL;
		free(t);
		return n;
	}
	*f = (*f)->next;
	(*r)->next = *f;
	free(t);
	return n;
}

void main()
{
	CQ *f, *r;

	init(&f, &r);
	int c=0, n;
	
	while(c!=4){
		printf("\n      --: MENU :--\n");
		printf(" 1. Insert\n 2. Delete\n 3. Display\n 4. Exit\n    Enter your choice: ");
		scanf("%d", &c);
		
		if(c==1){
			printf(" Enter number: ");
			scanf("%d", &n);
			enque(&f, &r, n);
		}
		else if(c==2){
			n = deque(&f, &r);
			if(n != ERR)
				printf("Removed number: %d\n", n);
		}
		else if(c==3){
			if(f==NULL){
				printf("Empty Queue!\n");
				continue;
			}
			printf("Queue: %3d, ", f->data);
			display(f->next, f);
		}
		else if(c!=4)
			printf("Invalid Input!\nPlease try again.\n");
	}
	printf("Thank You!\n");
}
	
		
		
	
	
	
		
		
		
