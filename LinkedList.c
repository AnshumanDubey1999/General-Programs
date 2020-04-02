/*******************************************************************************************************************************
* Program name      : LinkedList.c
*
* Author            : Anshuman Dubey
*
* Date created      : 24-07-2019
*
* Purpose           : To write a menu based program to perform basic tasks in a linked list.
*
*********************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EmptyListError -98779530
#define IndexOutOfBoundError -87457543
#define MemoryAllocationFailureError -78946554

typedef struct node{
		int value;
		struct node *next;
}Node;

void init(Node **aah){
	*aah = NULL;
}

int add(Node **aah, int n, int index){
	Node *temp = (Node *)malloc(sizeof(Node));        //Creating Node;
	if(temp == NULL){
			printf("Memory allocation failure.\n");
			return MemoryAllocationFailureError;
	}
	temp->value = n;

	if(*aah == NULL){                           //Empty list
		if(index!=0){
			printf("Index out of bound!\n");                           //Index Unavailable
			return IndexOutOfBoundError;
		}
		*aah = temp;                                 //Value at Pointer to Address of Header is changed, i.e. Address of header changes
		temp->next = NULL;                     //Setting up the first node
		return 1;
	}
	
	int i = 0;
	Node *prev, *nxt;
	prev = NULL;
	nxt = *aah;
	while(nxt!=NULL && i<index){               //Until the list finishes or desired index is reached
		prev = nxt;
		nxt = nxt->next;
		i++;
	}
	if(i!=index){
		printf("Index out of bound!\n");                              //Index unavailable
		return IndexOutOfBoundError;
	}
	if(prev==NULL){                            //At 0th Index
		temp->next = *aah;
		*aah = temp;
	}
	else{
		temp->next = nxt;
		prev->next = temp;
	}
	return 0;
}

int removeByIndex(Node **aah, int lower, int upper){
	Node *del, *jumpPoint, *prev;
	int i=-1;

	if(*aah==NULL){
		printf(" Empty List!\n");
		return EmptyListError;
	}

	prev = *aah;
	while(prev!=NULL && i<upper){
		if(i==(lower-1))
			jumpPoint = prev;
		if(i>=lower)
			del = prev;
		prev = prev->next;
		free(del);
		i++;
	}

	if(i<lower){
		printf("Lower limit out of bound.\n");
		return IndexOutOfBoundError;
	}

	jumpPoint->next = prev;
	if(i!=upper){
		printf("Upper limit out of bound. Range Adjusted from %d to %d.\n", lower, i);
	}
	return i;
}

int removeByValue(Node **aah, int n, int mode){
    Node *del,*prev,*cur;
    int isFound=0, i=1;
    cur = *aah;
    prev = NULL;
    while(cur!=NULL){
        if(n==cur->data){
        	isFound = 1;
            del = cur;
            if(prev!=NULL)
                prev->next = cur->next;
            else
                *aah = cur->next;
            free(del);
            if(mode==0){                      //If only first occurence
            	printf("Deletion is successful.\n");
            	return i;                      //Returns position at which number was deleted(index+1).
            }
        }
        else{
            prev = cur;
            cur = cur->next;
            i++;
        }
    }
    if(!isFound){
    	printf("Element not found.\n");   //If found, the control will never go to this line
    	return -1;
    }
    return 0;           //Successful execution
}

void display(Node *ah){
	if(ah==NULL){
		printf("Empty Linked List!\n");
		return;
	}
	Node *nxt = ah;
	printf("\nCurrent List : ");
	while(nxt!=NULL){
		printf("%-5d", nxt->value);
		nxt = nxt->next;
	}
	printf("\n");
}

int isSorted(Node *ah){
	if(ah==NULL || ah->next==NULL)
		return 1;

	int prev = ah->next->value, inAscending = ah->value - ah->next->value;
	Node *i = ah->next->next;
	while(i!=NULL){
		if(((prev - i->value > 0) && (inAscending<0)) || ((prev - i->value < 0) && (inAscending>0)))    //Not Sorted
			return -1;
		inAscending = prev - i->value;
		prev = i->value;
		i = i->next;
	}
	if(inAscending>0){
		printf("\n          Descending order found.\n");
		return 0;
	}
	printf("\n          Ascending order found.\n");
	return 1;
}

w

void sort(Node **aah, int inAscending){
	if(*aah == NULL){
		printf("Empty Linked List!\n");
		return;
	}

	Node *i, *sah, *del;
	init(&sah);
	i = *aah;
	while(i!=NULL){
		sortedAddition(&sah, i->value, inAscending);
		del = i;
		i = i->next;
		free(del);                          //Removing the previous node
	}
	*aah = *saah;
}

void main(){
	system("title Linked List");
    system("color 03");
    system("mode 100, 30");

	Node *ah;
	init(&ah);

	int n, choice = 0, size = 0, index, choice2, inAscending, i, length, upperLimit;

	while(choice!=8){
		printf("\n       --: MENU :--      \n");
		printf(" 1. Add\n");
		printf(" 2. Add Multiple\n");
		printf(" 3. Get\n");
		printf(" 4. Find\n");
		printf(" 5. Sort\n");
		printf(" 6. Remove\n");
		printf(" 7. Display\n");
		printf(" 8. Exit\n");
		printf("\n Enter your choice: ");
		scanf("%d", &choice);

		if(choice == 1){
			printf("\n       --: Add :--       \n");
			printf(" 1. At the Beginning\n");
			printf(" 2. At the End\n");
			printf(" 3. At given Index\n");
			printf(" 4. In Sorted Manner\n");
			printf(" 5. Back\n");
			printf(" 6. Exit\n");
			printf("\n Enter your choice: ");
			scanf("%d", &choice2);

			if(choice2 == 1 ||choice2 == 2 ||choice2 == 3){
				printf(" Enter the number to be added: ");
				scanf("%d", &n);
				if(choice2==1)
					index = 0;
				else if(choice2==2)
					index = size;
				else{
					printf(" Enter the index: ");
					scanf("%d", &index);
				}

				if(add(&ah, n, index)){
					printf("\n          %d successfully added.\n", n);
					size++;
				}
				else
					printf("\n          %d couldn't be added.\n", n);
			}

			else if(choice2 == 4){
				inAscending = isSorted(ah);
				if(inAscending == -1){
					printf("\n          List not in sorted order!\n");
					continue;
				}

				printf(" Enter the number to be added: ");
				scanf("%d", &n);
				sortedAddition(&ah, n, inAscending);
				printf("\n          %d successfully added.\n", n);
				size++;
			}

			else if(choice2 == 5)
				continue;

			else if(choice2 == 6)
				break;

			else
				printf(" Invalid Input. Please try again!\n");
		}

		if(choice == 2){
			printf("\n   --: Add Multiple :--   \n");
			printf(" 1. At the Beginning\n");
			printf(" 2. At the End\n");
			printf(" 3. At given Index\n");
			printf(" 4. In Sorted Manner\n");
			printf(" 5. Back\n");
			printf(" 6. Exit\n");
			printf("\n Enter your choice: ");
			scanf("%d", &choice2);

			if(choice2 == 1 ||choice2 == 2 ||choice2 == 3){
				printf(" Enter the number of inputs: ");
				scanf("%d", &length);
				if(choice2==1)
					index = 0;
				else if(choice2==2)
					index = size;
				else{
					printf(" Enter the index: ");
					scanf("%d", &index);
				}

				for(i = 1; i <= length; i++){
					printf(" Input %3d: ", i);
					scanf("%d", &n);
					if(add(&ah, n, index)){
						printf("\n          %d successfully added.\n", n);
						size++;
					}
					else{
						printf("\n          %d couldn't be added.\n", n);
						break;
					}
				}
			}

			else if(choice2 == 4){
				inAscending = isSorted(ah);
				if(inAscending == -1){
					printf("\n          List not in sorted order!\n");
					continue;
				}

				for(i = 1; i <= length; i++){
					printf(" Input %3d: ", i);
					scanf("%d", &n);
					sortedAddition(&ah, n, inAscending);
					printf("\n          %d successfully added.\n", n);
					size++;
				}
			}
			
			else if(choice2 == 5)
				continue;

			else if(choice2 == 6)
				break;

			else
				printf(" Invalid Input. Please try again!\n");
		}

		else if(choice == 5){
			printf("\n       --: Sort :--      \n");
			printf("\n 1. Ascending Order\n 2. Descending Order\n\n Enter your choice: ");
			scanf("%d", &choice2);
			if(choice2==1){
				sort(&ah, 1);
				printf("\n          List sorted in Ascending Order.\n");
			}
			else if(choice2==2){
				sort(&ah, 0);
				printf("\n          List sorted in Descending Order.\n");
			}
			else
				printf("Invalid Input!\n");
		}

		if(choice == 6){
			printf("\n      --: Remove :--      \n");
			printf(" 1. First Element\n");
			printf(" 2. Last Element\n");
			printf(" 3. By Value(First Occurence)\n");
			printf(" 4. By Value(All Occurences)\n");
			printf(" 5. By index\n");
			printf(" 6. Range of Elements\n");
			printf(" 7. Delete List\n");
			printf(" 8. Back\n");
			printf(" 9. Exit\n");
			printf("\n Enter your choice: ");
			scanf("%d", &choice2);

			if(choice2 == 1 ||choice2 == 2 ||choice2 == 5|| choice2 == 6){
				if(choice2==1){
					index = 0;
					upperLimit = 1;
				}
				else if(choice2==2){
					index = size-1;
					upperLimit = size;
				}
				else{
					printf(" Enter the lower index: ");
					scanf("%d", &index);
					printf(" Enter the upper index: ");
					scanf("%d", &upperLimit);
					if(index>=upperLimit){
						printf("Invalid Range!\n");
						continue;
					}
				}

				if(add(&ah, n, index)){
					printf("\n          %d successfully added.\n", n);
					size++;
				}
				else
					printf("\n          %d couldn't be added.\n", n);
					}
			}

			else if(choice2 == 4){
				inAscending = isSorted(ah);
				if(inAscending == -1){
					printf("\n          List not in sorted order!\n");
					continue;
				}

				printf(" Enter the number to be added: ");
				scanf("%d", &n);
				sortedAddition(&ah, n, inAscending);
				printf("\n          %d successfully added.\n", n);
				size++;
			}

			else if(choice2 == 5)
				continue;

			else if(choice2 == 6)
				break;

			else
				printf(" Invalid Input. Please try again!\n");
		}

		else if(choice == 7){
			display(ah);
		}

		else if(choice != 8){
			printf("Invalid Input. Please try again.\n");
		}

	}
	
}