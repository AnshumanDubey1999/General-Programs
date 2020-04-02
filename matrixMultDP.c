#include <stdio.h>

int paranthizeThis(int *arr, int l, int u){
	if(l==u)
		return 0;
	int i, min, count;
	min = 9999999;

	for(i = l; i<u; i++){
		count = paranthizeThis(arr, l, i) + paranthizeThis(arr, i+1, u) + arr[l-1]*arr[i]*arr[u];
		if(count<min)
			min = count;
	}
	return min;
}

int main(){
	int arr[] = { 5, 10, 3, 12, 5, 50, 6};
	printf("Number of scalar multiplications required is: %d.\n", paranthizeThis(arr, 1, 6));
}