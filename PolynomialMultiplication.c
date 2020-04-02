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
	//printf("Enter Loop\n");
	while(nxt != NULL && (nxt->exponent)>e){
		prev = nxt;
		nxt = nxt->next;
	}
	//printf("Exit Loop\n");
	if(prev == NULL){
		temp->next = *aah;
		*aah = temp;
	}
	else{
		prev->next = temp;
		temp->next = nxt;
	}
}

void addition(Node **aah, int c, int e){
	//printf("%d, %d\n", c, e);
	Node *i;
	i = *aah;
	while(i!=NULL){
		if(i->exponent == e){
			i->coefficient += c;
			return;
		}
		i = i->next;
	}

	sortedAddition(aah, c, e);
	//printf("Addition End\n");
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
			addition(aah, c, e);
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

void multiply(Node *p1, Node *p2, Node **p3){
	if(p1 == NULL){
		*p3 = p2;
	}
	if(p2 == NULL){
		*p3 = p1;
	}

	int c, e;
	Node *t1, *t2;
	t1 = p1;
	while(t1 != NULL){
		t2 = p2;
		while(t2 != NULL){
			c = t1->coefficient * t2->coefficient;
			e = t1->exponent + t2->exponent;
			addition(p3, c, e);
			t2 = t2->next;
		}
		t1 = t1->next;
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
			printf("%+d ", i->coefficient);
		else if(e==1)
			printf("%+dx ", i->coefficient);
		else if(c!=0)
			printf("%+dx^%d ", i->coefficient, i->exponent);
		i = i->next;
	}
}

void main(){
	Node *p1, *p2, *p3;
	init(&p1);
	init(&p2);
	init(&p3);
	char eq[1000];

	printf("Enter the 1st polynomial(with spaces): ");
	scanf("%[^\n]%*c", eq);
	input(&p1, eq);

	//printf("%s\n", eq);

	printf("Enter the 2nd polynomial(with spaces): ");
	scanf("%[^\n]%*c", eq);
	input(&p2, eq);

	multiply(p1, p2, &p3);
	//printf("%s\n", eq);

	printf("      ");
	display(p1);
	printf("\n x    ");
	display(p2);
	printf("\n");
	for (int i = 0; i < 75; ++i)
		printf("-");
	printf("\n =    ");
	display(p3);
	printf("\n");
	for (int i = 0; i < 75; ++i)
		printf("-");
	printf("\n\nThank You!\n");
}