#include<stdio.h>
#include<limits.h>                           /*Imports the limits of a datatype, i.e. the min & max number that 
											   can be stored in it.*/
#define MAX_SIZE 20                          //Because sir said so
int main()
{
	int a[MAX_SIZE];                         //Creating an array asking compiler to leave 20 int places on RAM
	int i, n, h = INT_MIN, h2 = INT_MIN;     /*h and h2 will store the highest and 2nd highest numbers. Therefore 
											   there initial values should be as low as possible. The user can't 
											   store a value lower than INT_MIN in an int array.*/
	scanf("%d", &n);

	if(n<2 || n > MAX_SIZE)                  /*If the value of n (number of inputs the user will provide) is lesser
	 										   than 2(can't have a 2nd highest), or greater than 20(overload), print
	 										   "ERROR" and exit program.*/
	{
		printf("ERROR");
		return 0;                            //Exit Program
	}

	for(i = 0; i < n; i++)                   //Taking input in each box of the array.
	{
		scanf("%d", &a[i]);
	}

	for(i = 0; i < n; i++)
	{
		if(a[i]>h)                           //If the current box has a bigger number than previously found numbers
		{
			h2 = h;                          //The highest becomes the 2nd highest
			h = a[i];                        //The new number becomes highest number
		}
		else if(a[i]>h2)                     //If number is not bigger than highest number but bigger than the 2nd highest number
		{
			h2 = a[i];                       //The new number becomes the 2nd highest numbers
		}
	}
	printf("%d\n", h2);                      //Print 2nd highest number
	return 0;
}