#include<stdio.h>
#include<stdlib.h>

typedef struct Jhola
{
    int profit;
    int weight;
    float value;
}Sack;

int myComp(const void* a, const void* b) {
    Sack* a1 = (Sack*)a; 
    Sack* b1 = (Sack*)b; 
    return a1->value < b1->value; 
} 

double knapsackFractional(Sack *A, int n, int maxWeight){
    qsort(A, n, sizeof(Sack), myComp);
    int weightFilled = 0, i, weightLeft = 0; 
    double result = 0;
    for(i = 0; i < n; i++){
        if(weightFilled + A[i].weight <= maxWeight){
            weightFilled = weightFilled + A[i].weight;
            result = result + A[i].profit;
        }
        else{
            weightLeft = maxWeight - weightFilled;
            result = result + (double)((double)A[i].profit * ((double)weightLeft / A[i].weight));
            break;
        }
    }
    return result;
}

int max(int a, int b){
    return (a>b)?a:b;
}

int knapsackDP(Sack *A, int n, int maxWeight){
    int i, j;
    int dp[n + 1][maxWeight + 1];
    for (i = 0; i <= n; i++){
        for(j = 0; j <= maxWeight; j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(A[i].weight <= j){
                dp[i][j] = max((A[i-1].profit + dp[i - 1][j - (A[i - 1].weight)]), dp[i -1][j]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][maxWeight];
}


int main()
{
    int n, maxWeight, p, w, i,ch;
    Sack *A;
    printf("Enter the number of objects: ");
    scanf("%d",&n);
    printf("Enter the maximum weight: ");
    scanf("%d", &maxWeight);
    A = (Sack *)malloc(sizeof(Sack)*n);
    printf("Enter the profit value and wight value of the object:\n");
    for(i = 0; i < n; i++){
        scanf("%d %d",&p, &w);
        A[i].profit = p;
        A[i].weight = w;
        A[i].value = ((double)p / w);
    }
    printf("1. 0/1 Knapsack using DP\n2. Fractional KnapSack using Greedy Algorithm\n3. Both 1 & 2.\nEnter Your Choice: ");
    scanf("%d", &ch);
    if(ch==1)
        printf("The maximum profit using 0/1 Knapsack: %d.\n", knapsackDP(A, n, maxWeight));
    else if(ch==2)
        printf("The maximum profit using Fractional Knapsack: %lf.\n", knapsackFractional(A, n, maxWeight));
    else if(ch==3){
        printf("The maximum profit using 0/1 Knapsack: %d.\n", knapsackDP(A, n, maxWeight));
        printf("The maximum profit using Fractional Knapsack: %lf.\n", knapsackFractional(A, n, maxWeight));
    }
    else
        printf("Invalid Input!\n");
    return 0;
}