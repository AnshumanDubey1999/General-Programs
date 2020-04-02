#include <stdio.h>
#include<stdlib.h>

typedef struct node{
	short int digit;
	struct node *next;
}DIGITS;

typedef struct number{
	struct node *num;
	int isNegetive;
	int decimalPosition;
	int length;
}NUMBER;

void init(NUMBER *n){
	n->num = NULL;
	n->isNegetive = 0;
	n->decimalPosition = 0;
	n->length = 0;
}

void delete(DIGITS *ah){
	if(ah==NULL)
		return;
	delete(ah->next);
	free(ah);
}

void displayInteger(DIGITS* ah){
	if(ah==NULL)
		return;
	displayInteger(ah->next);
	printf("%d", ah->digit);
}

DIGITS* getInteger(char *number){
	int i = 0;
	char c;
	DIGITS *num, *cur;
	cur = NULL;

	while(number[i]!='\0'){
		//printf("getInteger Loop: %c\n", number[i]);
		c = number[i];
		if(!(c>='0' && c<='9')){
			printf("Invalid Number!\n");
			return NULL;
		}
		num = (DIGITS*)malloc(sizeof(DIGITS));
		if(num==NULL){
			printf("Memory Allocation Failure!\n");
			return NULL;
		}                               //Memory allocation of new node
		num->next=cur;
		num->digit = c-'0';
		cur = num;
		i++;
	}
	return cur;
}

void insert(DIGITS **aah, DIGITS **cur, int n){
	//printf("Inserting %d in ", n);
	//displayInteger(*aah);
	//printf("\n");
	DIGITS *t;
	t = (DIGITS*)malloc(sizeof(DIGITS));
	if(t==NULL){
		printf("Memory Allocation Failure!\n");
		return;
	}                               //Memory allocation of new node
	t->next=NULL;
	t->digit = n;
	if(*cur!=NULL)
		(*cur)->next = t;
	else
		*aah = t;
	*cur = t;
}

DIGITS* add(DIGITS *a, DIGITS *b){
	if(a==NULL)
		return b;
	if(b==NULL)
		return a;
	DIGITS *num, *cur;
	int sum, carry = 0;
	num = NULL;
	cur = NULL;
	while(!(a==NULL && b==NULL)){
		//printf("Add digits %d + %d\n", ((a==NULL)?0:a->digit), ((b==NULL)?0:b->digit));
		sum = ((a==NULL)?0:a->digit) + ((b==NULL)?0:b->digit) + carry;
		carry = sum/10;
		sum = sum%10;
		insert(&num, &cur, sum);
		if(a!=NULL)
			a = a->next;
		if(b!=NULL)
			b = b->next;
	}
	while(carry!=0){
		//printf("carry Loop\n");
		insert(&num, &cur, carry%10);
		carry/=10;
	}
	//printf("Sum = ");
	//displayInteger(num);
	//printf("\n");
	return num;
}

DIGITS* multiply(DIGITS *a, DIGITS *b){
	DIGITS *num, *cur, *sum, *x, *t;
	int mul, carry = 0, i = 0, j;
	sum = NULL;
	x = b;
	while(a!=NULL){
		delete(num);
		num = NULL;
		cur = NULL;
		j=0;
		b = x;
		while(j<i){                                 //Inserting zeroes
			insert(&num, &cur, 0);
			j++;
		}
		while(b!=NULL){
			//printf("Multiplyer Loop\n");
			mul = (a->digit)*(b->digit) + carry;
			carry = mul/10;
			mul = mul%10;
			//printf("Sum: %d,  Carry: %d\n", mul, carry);
			insert(&num, &cur, mul);
			b = b->next;
		}
		while(carry!=0){
			//printf("carry Loop\n");
			insert(&num, &cur, carry%10);
			carry/=10;
		}
		//displayInteger(num);
		//printf("\n");
		t = sum;
		sum = add(sum,num);
		if(t!=sum)
			delete(t);
		a = a->next;
		i++;
	}
	return sum;
}

int main(){
	DIGITS *a, *b, *c;
	char num1[100], num2[100];
	printf("Enter the first  number: ");
	scanf("%[^\n]%*c", num1);
	printf("Enter the second number: ");
	scanf("%[^\n]%*c", num2);
	a = getInteger(num1);
	//displayInteger(a);
	//printf("\n");
	b = getInteger(num2);
	//displayInteger(b);
	//printf("\n");
	c = multiply(a,b);
	printf("------------------------------------------------------------------------------------------------\n");
	printf("               ");
	displayInteger(a);
	printf("\n  x            ");
	displayInteger(b);
	printf("\n------------------------------------------------------------------------------------------------\n");
	printf("  =            ");
	displayInteger(c);
	printf("\n------------------------------------------------------------------------------------------------\n");
	return 0;
}