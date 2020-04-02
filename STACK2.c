#include <stdio.h>
#include <stdlib.h>
#define ERROR -9999999

typedef struct stack{                  //Declaring a node of the stack
	int data;
	struct stack* next;
}STACK;

void init(STACK **aah){               //Initialization
	*aah = NULL;
}

int isEmpty(STACK *ah){
	return ah==NULL;                  //If header points to nothing
}

int push(STACK **aah, int n){
	STACK *t;
	t = (STACK *)malloc(sizeof(STACK));
	if(t==NULL){
		printf("Memory Allocation Failure!\n");
		return ERROR;
	}                               //Memory allocation of new node
	t->data = n; 

	t->next = *aah;                 //Putting the entire stack at the back of new node
	*aah = t;                       //Changing address of the stack header to the new node
	return 0;
}

int pop(STACK **aah){
	STACK *t;
	t = *aah;                       //t stores the 1st node of stack
	if(isEmpty(*aah))
		return ERROR;

	int n = t->data;                //n stores the data to be popped
	*aah = (*aah)->next;            //stack header changes to the next node
	free(t);                        //original top node is deleted
	return n;
}

int peek(STACK *ah){
	if(isEmpty(ah))
		return ERROR;

	return ah->data;                //Value in top node is sent
}

void main(){
	STACK *ah;
	init(&ah);
	int c=0, n;

	while(c!=4){                      //If not an Exit request
		printf("\n   --: MENU :--\n");
		printf(" 1. Push\n 2. Pop\n 3. Peek\n 4. Exit\n Enter your choice: ");
		scanf("%d", &c);

		if(c==1){                     //Push
			printf(" Enter number: ");
			scanf("%d", &n);
			if(push(&ah, n)==ERROR)
				printf("Stack Overflow!");
		}
		else if(c==2){               //Pop
			n = pop(&ah);
			if(n == ERROR)
				printf("Empty Stack!\n");
			else
				printf(" Popped number: %d\n", n);
		}
		else if(c==3){              //Peek
			n = peek(ah);
			if(n == ERROR)
				printf("Empty Stack!\n");
			else
				printf(" Last number: %d\n", n);
		}
		else if(c!=4)               //Error
			printf("Invalid Input!\nPlease try again.\n");
	}
	printf("Thank You!\n");
}
