#include <stdio.h>
#include <stdlib.h>

void display(int *positions, int size){
	int i,j;
	for(i=0; i < size; i++){
		for (j = 0; j < size; ++j)
			if(positions[i] == j)
				printf("Q ");
			else
				printf("_ ");
		printf("\n");
	}
}

int abs(int x){
	return x>=0?x:-x;
}

int isPlacable(int *positions, int row, int column){
	int i;
	for(i = 0; i < row; i++){
		if(positions[i] == column || abs(column - positions[i]) == abs(i - row))
			return 0;
	}
	return 1;
}

int getPosition(int *positions, int depth, int size){
	if(depth == size){
		//printf("\nRequired Arrangement: \n");
		//display(positions, size);
		return 1;
	}
	int found = 0, i;
	for(i = 0; i < size; i++){
		if(!isPlacable(positions, depth, i))
			continue;
		positions[depth] = i;
		if(getPosition(positions, depth + 1, size))
			found = 1;
		if(found)
		 	return 1;
	}
	//return found;
	return 0;
}

void main(){
	int *positions;
	int n, i, found;
	printf("Enter the size of board: ");
	scanf("%d", &n);
	
	positions = (int *)malloc(sizeof(int)*n);

	if(positions == NULL){
		printf("Memory Allocation Failure!\n");
		return;
	}

	found = getPosition(positions, 0, n);
	if(!found)
		printf("No such Arrangement Possible.\n");
	else{
		printf("\nRequired Arrangement: \n");
		display(positions, n);
	}
	return;
}