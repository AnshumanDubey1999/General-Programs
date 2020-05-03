#include<stdio.h>
#include<stdlib.h>

int binarySearch(int *arr, int size, int key){
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
	int *arr, size, key, i;
	printf("Enter size of array: ");
	scanf("%d", &size);
	arr = (int *)malloc(sizeof(int)*size);
	printf("Enter array in ascending order:\n");
	for(i = 0; i < size; i++)
		scanf("%d", &arr[i]);
	printf("Enter the number to be searched: ");
	scanf("%d", &key);
	i = binarySearch(arr, size, key);
	if(i==-1)
		printf("%d not present in given array!\n", key);
	else
		printf("%d presnt at index %d.\n", key, i);
}