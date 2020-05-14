#include<stdio.h>
#include<stdlib.h>

int recursion(int depth, int *num, int *freq, int size){
	int i, initialFreq = freq[depth];
	// printf("Depth: %d\n", depth);
	// printf("Current Number: ");
	// for(i = 0; i < size; i++){
	// 	printf("%d", num[i]);
	// }
	// printf("\n");
	// printf("CurrentFrequency: ");
	// for(i = 0; i < size; i++){
	// 	printf("%d,\t", freq[i]);
	// }
	// printf("\n");
	if(depth==0){
		num[0] = freq[0];
		freq[0]=0;
		freq[num[0]]-=1;
		for(i=0; i< size; i++){
			if(freq[i]!=0){
				freq[0]=num[0];
				freq[num[0]]+=1;
				return 0;
			}
		}
		return 1;
	}

	for(i = initialFreq; i < depth; i++){
		num[depth] = i;
		freq[depth] = i - initialFreq;
		freq[i]+=1;
		if(recursion(depth-1, num, freq, size))
			return 1;
		freq[i]-=1;
	}

	if(depth!=initialFreq){
		num[depth]=depth;
		freq[depth] = depth - 1 - initialFreq;
		if(recursion(depth-1, num, freq, size))
			return 1;
	}

	for(i = depth + 1; i < size; i++){
		if(freq[i]!=0){
			num[depth] = i;
			freq[depth] = i - initialFreq;
			freq[i]-=1;
			if(recursion(depth-1, num, freq, size))
				return 1;
			freq[i]+=1;
		}
	}
	freq[depth] = initialFreq;
	return 0;
}

int main(){
	int size, *num, *freq, i;
	printf("Enter number of digits: ");
	scanf("%d", &size);
	num = (int *)malloc(sizeof(int)*size);
	freq = (int *)malloc(sizeof(int)*size);
	for(i = 0; i < size; i++){
		num[i]=freq[i]=0;
	}
	if(recursion(size-1, num, freq, size)){
		printf("Required Number: ");
		for(i = 0; i < size; i++){
			printf("%d", num[i]);
		}
		printf("\n");
	}
	else
		printf("No such number exists!\n");
	return 0;
}