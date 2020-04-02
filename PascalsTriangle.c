#include <stdio.h>
#include <string.h>
int main()
{
    int n, line[100], newLine[100], i, j;
    scanf("%d", &n);
    for(i = 0; i <=(n*2-1); i++)
    {
        line[i]=0;
        newLine[i]=0;
        if(i!=(n-1))
            printf("  ");
        else
            printf("1 ");
    }
    line[n-1] = 1;
    printf("\n");
    for(j = 1; j < n; j++)
    {
        for(i = 0;i < (n*2-1); i++)
        {
            if(i==0)
                newLine[0] = line[1];
            else
                newLine[i] = line[i-1]+line[i+1];
            if(newLine[i]==0)
                printf("  ");
            else
                printf("%d ", newLine[i]);
        }
        printf("\n");
        for(i = 0; i < (n*2-1); i++)
            line[i] = newLine[i];
    }
    return 0;
}