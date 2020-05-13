#include<stdio.h>
#include<stdlib.h>

void swap(int *arr, int i, int j){
	int t = arr[i];
	arr[i] = arr[j];
	arr[j] = t;
}

void display(int *arr, int size){
	int i;
	for(i = 0; i < size; i++)
		printf("%3d, ", arr[i]);
	printf("\n");
}

void bubbleSort(int *arr, int size){
	int i, j;
	
}


int find(int *arrays, int size, int key){
	int i;
	for(i = 0; i < size; i++){
		if(arrays[i]==key)
			return i;
	}
	return -1;
}


void solve(){
	int **arrays;
	int n,i,j, t, size, p;
	scanf("%d", &n);

	arrays = (int **)malloc(sizeof(int)*3);
	for(i = 0; i < 3; i++){
		arrays[i] = (int *)malloc(sizeof(int)*n);
	}
	for(i = 0; i < n; i++){
		scanf("%d", &arrays[0][i]);
	}
	size = 0;
	for(i = 0;i<n;i++){
		p = find(arrays[1], size, arrays[0][i]);
		printf("%d\n", p);
		if(p!=-1){
			arrays[2][p]++;
		}
		else{
			arrays[1][size] = arrays[0][i];
			arrays[2][size] = 1;
			size++;
		}
	}
	display(arrays[1], size);
	display(arrays[2], size);
	for (i = 0; i < size; ++i){
		for (j = 0; j < (size-i-1); ++j){
			if((arrays[2][j]<arrays[2][j+1]) || (arrays[2][j]==arrays[2][j+1] && arrays[1][j]>arrays[1][j+1])){
				swap(arrays[1], j, j+1);
				swap(arrays[2], j, j+1);
			}
		}
	}
	for(i = 0; i < size; i++){
		for(j = 0; j < arrays[2][i];j++)
			printf("%d ", arrays[1][i]);
	}
	printf("\n");
}

void main(){
	int t;
	scanf("%d", &t);
	while(t>0){
		solve();
		t--;
	}
}
