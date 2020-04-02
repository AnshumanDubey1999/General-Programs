#include <stdio.h>
#include <stdlib.h>
#define ERROR -9999999

typedef struct node                   //Structure for node of queue
{
	int data;
	struct node* next;
} NODE;

typedef struct queue                 //Structure for pointers of queue
{
	NODE *front, *rear;
} QUEUE;


void init(QUEUE *q){                 //Initialization
	q->front = q->rear = NULL;
}

int isEmpty(QUEUE *q){
	return (q->front==NULL);
}

int enque(QUEUE *q, int n){          //Inserting in the queue
	NODE *t, *r;
	t = (NODE *)malloc(sizeof(NODE));
	if(t==NULL){
		printf("Memory Allocation Failure!\n");
		return ERROR;
	}                               //Memory allocation of a node
	t->next = NULL;
	t->data = n;

	if(isEmpty(q))
		q->front = q->rear = t;    //Both rear and front point at t
	else {
		r = q->rear;               //last node is stored in r
		r->next = t;               //t is attached to the back of r
		q->rear = t;               //rear pointer's value is updated
	}
	return 0;
}

int deque(QUEUE *q){               //Deleting from a queue
	NODE *t;
	int n;
	if(isEmpty(q))
		return ERROR;

	if(q->front==q->rear)          //If single element queue
		q->rear = NULL;            //As deletion is about to occour, rear is set to null

	t = q->front;                  //first element of queue stored in t
	n = t->data;                   //n stores the data to be deleted
	q->front = t->next;            //front pointer changes to the next pointer in queue
	free(t);                       //First node is deleted
	return n;
}

int display(QUEUE *q){
	NODE *t;
	if(isEmpty(q))
		return ERROR;

	t = q->front;
	printf(" QUEUE elements : ");
	while(t->next!=NULL){         //Print till the 2nd last element of queue.
		printf("%3d, ", t->data);
		t = t->next;
	}
	printf("%3d.\n", t->data);
	return 0;
}


void main(){
	QUEUE q1;
	init(&q1);
	int c=0, n;

	while(c!=4){                   //If not an Exit request
		printf("\n   --: MENU :--\n");
		printf(" 1. Insert\n 2. Delete\n 3. Display\n 4. Exit\n Enter your choice: ");
		scanf("%d", &c);

		if(c==1){                 //Insert or Enque
			printf(" Enter number: ");
			scanf("%d", &n);
			if(enque(&q1, n)==ERROR)
				printf("Queue Overflow!");
		}
		else if(c==2){            //Delete or Deque
			n = deque(&q1);
			if(n != ERROR)
				printf("Removed number: %d\n", n);
			else
				printf("EMPTY QUEUE!\n");
		}
		else if(c==3){            //Display
			if(display(&q1)==ERROR)
				printf("EMPTY QUEUE!\n");
		}
		else if(c!=4)             //Error
			printf("Invalid Input!\nPlease try again.\n");
	}
	printf("Thank You!");
}