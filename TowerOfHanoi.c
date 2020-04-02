/*******************************************************************************************************************************
* Program name      : towerOfHanoi.c
*
* Author            : Anshuman Dubey
*
* Date created      : 02-11-2019
*
* Question          : Implement Tower of Hanoi recursively in C.
*
*********************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void towerOfHanoi(int n, char from, char to, char extra, int *counter) 
{ 
    if (n == 1) 
    {
        ++(*counter);
        printf("%3d. Move disk 1 from rod %c to rod %c.\n", *counter, from, to);
        return; 
    } 
    towerOfHanoi(n-1, from, extra, to, counter);
    ++(*counter);
    printf("%3d. Move disk %d from rod %c to rod %c.\n", *counter, n, from, to); 
    towerOfHanoi(n-1, extra, to, from, counter); 
} 

void main(){
    int n, counter = 0;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    towerOfHanoi(n, 'A', 'C', 'B', &counter);
}