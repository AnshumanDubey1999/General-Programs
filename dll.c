#include <stdio.h>
#include <stdlib.h>
#define ERR -9999999

typedef struct dll{
	int data;
	struct dll *prev, *next;
}DLL;

void init(DLL **aah){
	*aah = NULL;
}

int insert(DLL **aah, int n, int index){
	DLL *t, *cur, *prv;
	int i;
	t = (DLL *)malloc(sizeof(DLL));
	if(t==NULL){
		printf("Memory allocation failure!\n");
		return ERR;
	}
	t->data = n;
	t->prev = NULL;
	t->next = NULL;
	
	if(*aah==NULL || index == 0){
		if(index != 0){
			printf("Invalid Position!\n");
			return ERR;
		}
		
		t->next = *aah;
		if(*aah != NULL)
			(*aah)->prev = t;
		*aah = t;
		return 0;
	}
	
	prv = *aah;
	cur = (*aah)->next;
	i = 1;
	while(cur != NULL && i!=index){
		prv = cur;
		cur = cur->next;
		i++;
	}
	
	if(i!=index){
		printf("Invalid Position!\n");
		return ERR;
	}
	
	
	
	t->prev = prv;
	t->next = cur;
	if(cur != NULL)
		cur->prev = t;
	prv->next = t;
	return 0;
}

void display(DLL *ah){
	if(ah==NULL)
		return;
	printf("%3d, ", ah->data);
	display(ah->next);
}

void rev_display(DLL *ah){
	if(ah==NULL)
		return;
	rev_display(ah->next);
	printf("%3d, ", ah->data);
}

int delete(DLL **aah, int n){
	DLL *t;
	if((*aah)->data==n){
		t = *aah;
		*aah = t->next;
		if(*aah !=NULL)
			(*aah)->prev = NULL;
		free(t);
		return 0;
	}
	
	t = (*aah)->next;
	while(t!=NULL && t->data != n)
		t = t->next;
		
	if(t==NULL){
		printf("Number not found!\n");
		return ERR;
	}
	
	t->prev->next = t->next;
	if(t->next != NULL)
		t->next->prev = t->prev;
	free(t);
	return 0;
}

void main()
{
	DLL *d;

	init(&d);
	int c=0, n, i;
	
	while(c!=5){
		printf("\n      --: MENU :--\n");
		printf(" 1. Insert\n 2. Delete\n 3. Display\n 4. Reverse Display\n 5. Exit\n    Enter your choice: ");
		scanf("%d", &c);
		
		if(c==1){
			printf(" Enter number: ");
			scanf("%d", &n);
			printf(" Enter position: ");
			scanf("%d", &i);
			if(insert(&d, n, i-1)==0)
				printf("%d successfully stored at %d  position.\n", n, i);
		}
		else if(c==2){
			printf(" Enter number: ");
			scanf("%d", &n);
			if(delete(&d, n)==0)
				printf("%d successfully deleted.\n", n);
		}
		else if(c==3){
			if(d == NULL){
				printf("Empty List!\n");
				continue;
			}
			printf("List: ");
			display(d);
			printf("\n");
		}
		else if(c==4){
			if(d == NULL){
				printf("Empty List!\n");
				continue;
			}
			printf("Reverse List: ");
			rev_display(d);
			printf("\n");
		}
		else if(c!=5)
			printf("Invalid Input!\nPlease try again.\n");
	}
	printf("Thank You!\n");
}
	
		
		
	
	
	
		
		
		
