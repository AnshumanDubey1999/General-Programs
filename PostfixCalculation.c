#include <stdio.h>
#include <stdlib.h>
#define mallocerr -9876464
#define emptyerr -9876278
#define insufficientOperandErr -9797792

typedef struct n{
	int data;
	struct n* next;
}stack;

void init(stack **aah){
	*aah = NULL;
}

int push(stack **aah, int n){
	stack *t;
	t = (stack *)malloc(sizeof(stack));
	if(t==NULL)
		return mallocerr;
	t->data = n;

	t->next = *aah;
	*aah = t;
	return 0;
}

int pop(stack **aah){
	if(*aah==NULL)
		return emptyerr;
	int n = (*aah)->data;
	stack *t = *aah;
	*aah = (*aah)->next;
	free(t);
	return n;
}

int add(stack **aah)
{
	if(*aah==NULL || (*aah)->next==NULL)
		return insufficientOperandErr;

	int m = pop(aah);
	int n = pop(aah);
	return m+n;
}

int subtract(stack **aah)
{
	if(*aah==NULL || (*aah)->next==NULL)
		return insufficientOperandErr;

	int m = pop(aah);
	int n = pop(aah);
	return n-m;
}

int multiply(stack **aah)
{
	if(*aah==NULL || (*aah)->next==NULL)
		return insufficientOperandErr;

	int m = pop(aah);
	int n = pop(aah);
	return m*n;
}

int divide(stack **aah)
{
	if(*aah==NULL || (*aah)->next==NULL)
		return insufficientOperandErr;

	int m = pop(aah);
	int n = pop(aah);
	return n/m;
}

void main(){
	stack *s;
	init(&s);

	char eq[100];
	printf("Enter the postfix equation: ");
	scanf("%[^\n]%*c", eq);

	char c=eq[0];
	int n=0, i;

	for(i=1;c!='\0';i++){
		if(c==' '){
			if(n!=0)
				push(&s, n);
			n=0;
		}

		else if(c>='0' && c<='9')
			n = n*10 + (c-'0');

		else if(c=='+')
			push(&s, add(&s));

		else if(c=='-')
			push(&s, subtract(&s));

		else if(c=='*')
			push(&s, multiply(&s));

		else if(c=='/')
			push(&s, divide(&s));

		c = eq[i];
	}
	printf("OUTPUT: %d\n", pop(&s));
}