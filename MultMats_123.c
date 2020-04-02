/*******************************************************************************************************************************
* Program name      : MultMats_123.c
*
* Author            : Anshuman Dubey
*
* University Roll   : 13000118123
*
* Date created      : 26-03-2019
*
* Purpose           : To Multiply 2 given matrices and print the result.
*
* Theory  :
*
* The first condition that needs to be satisfied to multiply a matrix is column(Matrix 1) = row(Matrix 2).
* Each element of the resultant matrix at index (i,j) is the sum of products of each elemet from ith row of 1st matrix and each 
* element of the jth column of 2nd matrix.
*
*********************************************************************************************************************************/


#include <stdio.h>
#define MAX_ROWS 25
#define MAX_COLS 25
int isMultiplicationValid(int r1, int c1, int r2, int c2)
{
	if(c1==r2)                                                          //If multiplicable
		return 1;
	return 0;
}
int readMat(int r, int c, int mat[MAX_ROWS][MAX_COLS])
{
	int i, j;
	for(i = 0; i < r; i++)
	{
		for(j = 0; j < c; j++)
			scanf("%d", &mat[i][j]);                                   //Taking input in each box of the array
	}
	return 0;
}
int dispMat(int r, int c, int mat[MAX_ROWS][MAX_COLS])
{
	int i, j;
	for(i = 0; i < r; i++)
	{
		for(j = 0; j < c; j++)
			printf("%3d ", mat[i][j]);                                 //Printing in matrix format with a single space.
		printf("\n");
	}
	return 0;
}
int multMats(int r1, int c1, int c2, int mat1[MAX_ROWS][MAX_COLS], int mat2[MAX_ROWS][MAX_COLS], int res[MAX_ROWS][MAX_COLS])
{
	int i, j, k, s;
	for(i = 0; i < r1; i++)                                          //For each row of 1st Matrix.
	{
		for(j = 0; j < c2; j++)                                      //For each column of 2nd Matrix.
		{
			s = 0;                                                   //Reseting sum variable.
			for(k = 0; k < c1; k++)               
				s += mat1[i][k]*mat2[k][j];                          //Calculating the sum of products.
			res[i][j] = s;
		}
	}
	return 0;
}
int main()
{
	int r1, c1, mat1[MAX_ROWS][MAX_COLS], r2, c2, mat2[MAX_ROWS][MAX_COLS], res[MAX_ROWS][MAX_COLS], isMultiplied = 0;
	printf("Enter the number of rows for Matrix A : ");
	scanf("%d", &r1);
	printf("Enter the number of columns for Matrix A : ");
	scanf("%d", &c1);
	if(r1<1 || c1<1)
	{
		printf("Invalid Size!\n");
		return 0;
	}
	printf("Enter %d numbers to fill up Matrix A : \n", r1*c1);
	readMat(r1, c1, mat1);
	printf("Enter the number of rows for Matrix B : ");
	scanf("%d", &r2);
	printf("Enter the number of columns for Matrix B : ");
	scanf("%d", &c2);
	if(r2<1 || c2<1)
	{
		printf("Invalid Size!\n");
		return 0;
	}
	printf("Enter %d numbers to fill up Matrix B : \n", r2*c2);
	readMat(r2, c2, mat2);
	printf("\nMatrix A :\n");
	dispMat(r1, c1, mat1);
	printf("\nMatrix B :\n");
	dispMat(r2, c2, mat2);                                        //Printing the 2 Matrices
	if(isMultiplicationValid(r1, c1, r2, c2))                     //If A*B is possible
	{
		multMats(r1, c1, c2, mat1, mat2, res);
		printf("\nMatrix A*B :\n");
		dispMat(r1, c2, res);
		isMultiplied++;                                          //Multiplication occured
	}
	if(isMultiplicationValid(r2, c2, r1, c1))                    //If B*A is possible
	{
		multMats(r2, c2, c1, mat2, mat1, res);
		printf("\nMatrix B*A :\n");
		dispMat(r2, c1, res);
		isMultiplied++;                                          //Multiplication occured
	}
	if(isMultiplied==0)                                          //If no multiplication occured.
		printf("\nThe 2 matrices can't be multiplied.\n");
	return 0;
}