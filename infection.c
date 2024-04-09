#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

int main(){
	int blocks[5][5];
	int min = 9999999;
	int max = 0;
	int sum = 0;
	int i, j, k, runs, temp, temp2;

	for(runs = 0; runs<10; runs++){
		//SET to 0
		for(i = 0; i < 5; i++){
			for(j=0; j<5; j++){
				blocks[i][j]=0;
			}
		}
		blocks[0][0]=1;

		//Simulate
		sleep(1);
		for(k = 0; k < 10; k++){
			srand(time(0));
			temp= (k%2==0)?1:-1; //Changing mode
			temp2= (k%2==0)?-1:1;

			for(i=0; i<5; i++){
				for(j=0;j<5;j++){
					if(blocks[i][j]==temp){
						if(i>0){
							if(rand()%2)
								blocks[i-1][j]=temp2;
						}
						if(j>0){
							if(rand()%2)
								blocks[i][j-1]=temp2;
						}
						if(i<4){
							if(rand()%2)
								blocks[i+1][j]=temp2;
						}
						if(j<4){
							if(rand()%2)
								blocks[i][j+1]=temp2;
						}
					}
				}
			}
		}

		//Display and calculate
		temp = 0;
		printf("Result of Simulation %d:\n", runs+1);
		for(i = 0; i < 5; i++){
			for(j=0; j<5; j++){
				printf("%d\t", blocks[i][j]);
				if(blocks[i][j]!=0)
					temp++;
			}
			printf("\n");
		}
		printf("Number of infected blocks: %d\n", temp);
		sum+=temp;
		min = temp<min? temp:min;
		max = temp>max?temp:max;

	}
	printf("Max: %d\nMin: %d\nAverage: %.1f\n", max, min, sum/10.0);
}