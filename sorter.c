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
}

void bubbleSort(int *arr, int size){
	int i, j;
	for (i = 0; i < size; ++i){
		for (j = 0; j < (size-i-1); ++j){
			if(arr[j]>arr[j+1])
				swap(arr, j, j+1);
		}
	}
}

void selectionSort(int *arr, int size){
	int i, j, min;
	for (i = 0; i < (size-1); ++i){
		min = i;
		for (j = i+1; j < size; ++j){
			if(arr[min]>arr[j])
				min = j;
		}
		swap(arr, i, min);
	}
}

void insertionSort(int *arr, int size){
	int i = 1, j, t;
	while(i<size){
		j = i-1;
		t = arr[i];
		while((j >= 0) && (arr[j]>t)){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = t;
		i++;
	}
}

void merge(int *arr, int l, int m, int u){
	int *A;
	int i, j, k;
	A = (int *)malloc(sizeof(int)*(u-l+1));

	i = l;
	j = m+1;
	k = 0;
	while((i <= m) && (j <= u)){
		if(arr[i]<arr[j])
			A[k++] = arr[i++];
		else
			A[k++] = arr[j++];
	}

	while(i <= m)
		A[k++] = arr[i++];
	while(j <= u)
		A[k++] = arr[j++];

	for(i = l; i <= u; i++)
		arr[i] = A[i-l];
}

void mergeSort(int *arr, int i, int j){
	int mid = (i+j)/2;
	if(i<j){
		mergeSort(arr, i , mid);
		mergeSort(arr, mid+1, j);
		merge(arr, i, mid, j);
	}
}

int partition(int *arr, int lower, int upper){
	int i, j;

	i = lower;
	j = lower;
	while(i < upper){
		if(arr[i] < arr[upper]){
			swap(arr, i, j);                  //Pushed on the lower side
			j++;
		}
		i++;
	}
	swap(arr,j,upper);                         //Putting back to its position
	return j;
}

void quickSort(int *arr, int i, int j){
	if(i<j){
		int pivot = partition(arr, i , j);
		quickSort(arr, i, pivot-1);
		quickSort(arr, pivot +1, j);
	}
}

void heapify(int *arr, int size, int i){
	int l = 2*i+1, r = 2*i + 2, max;
	if((l<size) && (arr[l]>arr[i]))
		max = l;
	else
		max = i;

	if((r<size) && (arr[r]>arr[max]))
		max = r;

	if(max != i){
		swap(arr, i, max);
		heapify(arr, size, max);
	}
}

void buildMaxHeap(int *arr, int size){
	int i;
	for(i = size/2; i >= 0; i--)
		heapify(arr, size, i);
}

void heapSort(int *arr, int size){
	buildMaxHeap(arr, size);
	int i;
	for(i = size - 1; i >= 0; i--){
		swap(arr, 0, i);
		size--;
		heapify(arr, size, 0);
	}
}

void main(){
	int **arrays;
	int n,i,j, t;
	printf("Enter the size of array: ");
	scanf("%d", &n);

	arrays = (int **)malloc(sizeof(int)*6);
	for(i = 0; i < 6; i++){
		arrays[i] = (int *)malloc(sizeof(int)*n);
	}
	printf("Enter %d elements:\n", n);;
	for(i = 0; i < n; i++){
		scanf("%d", &t);
		for(j = 0; j < 6; j++)
			arrays[j][i] = t;
	}
	bubbleSort(arrays[0], n);
	selectionSort(arrays[1], n);
	insertionSort(arrays[2], n);
	mergeSort(arrays[3], 0, n-1);
	quickSort(arrays[4], 0, n-1);
	heapSort(arrays[5], n);
	printf("\nBubble Sort    : ");
	display(arrays[0], n);
	printf("\nSelection Sort : ");
	display(arrays[1], n);
	printf("\nInsertion Sort : ");
	display(arrays[2], n);
	printf("\nMerge Sort     : ");
	display(arrays[3], n);
	printf("\nQuick Sort     : ");
	display(arrays[4], n);
	printf("\nHeap Sort      : ");
	display(arrays[5], n);
}
