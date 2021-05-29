#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int arrayInput1D(int arr[MAX], int size){
	int i;
	for(i = 0; i < size; i++){
		scanf("%d", &arr[i]);
	}
}

int arrayDisplay1D(int arr[MAX], int size){
	int i;
	for(i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int arrayInput2D(int arr[MAX][MAX], int row, int columns){
	int i,j;
	for(i = 0; i < row; i++){
		for(j = 0; j < columns; j++)
			scanf("%d", &arr[i][j]);
	}
}

int arrayDisplay2D(int arr[MAX][MAX], int row, int columns){
	int i,j;
	for(i = 0; i < row; i++){
		for(j = 0; j < columns; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
}

int binarySearch(int arr[MAX], int size, int key){
	int l, u ,m;
	l = 0;
	u = size-1;
	while(l<=u){
		m = (l+u)/2;
		if(arr[m]==key)
			return m;
		else if(arr[m]>key)
			u = m-1;
		else
			l = m+1;
	}
	return -1;
}



int main(){
	int arr[MAX][MAX];
	arrayInput2D(arr, 3,3);
	arrayDisplay2D(arr,3,3);
}