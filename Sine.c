#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{   float x, pow = 1.0, sum=0.0;
    int n,i, fact = 1;
    printf("Enter angle in degree : ");
    scanf("%f",&x);
    printf("Enter a value to extend the expansion : ");
    scanf("%d",&n);
    x= x * (3.14159/180);
    sum = x;
    pow = x;
    if(n<=0){
        printf("ERROR");
        return 0;
    }
    for(i=1;i<n;i++)
    {
        pow *= x*x;
        fact *= (i*2)*(i*2 + 1);
        if(i%2==0)
            sum += pow/fact;
        else
            sum -= pow/fact;
    }
    printf("%.4f",sum);
}