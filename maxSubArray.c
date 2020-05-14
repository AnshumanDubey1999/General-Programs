#include<stdio.h>
#include<stdlib.h>
int maximum(int a,int b, int c){
    return (a>b)?(a>c?a:c):(b>c?b:c);
}

int maxInMiddle(int a[],int l,int mid,int h){
    // printf("Find middle Max(%d - %d)\n", l, h);
    int i,sum = 0, max1 = 0, max2 = 0;
    //left from middle
    for(i = mid; i >= l; i--){
        sum += a[i];
        if(sum > max1)
            max1 = sum;
    }
    sum = 0;
    //right from middle
    for(i = mid+1; i <= h; i++){
        sum += a[i];
        if(sum > max2)
            max2 = sum;
    }
    return max1+max2;
}
int maxSub(int a[],int l,int h){
    // printf("Range: %d - %d\n", l, h);
    if(l<h){
        int mid = (l+h)/2;
        int max1 = maxSub(a,l,mid);
        int max2 = maxSub(a,mid+1,h);
        // printf("Current max: %d, %d\n", max1, max2);
        return maximum(max1, max2, maxInMiddle(a,l, mid, h));
    }
    else 
        return a[l];
}

int main(){
    int n,i,c;
    printf("Enter size of array: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter array elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Max SubArray Sum: %d\n", maxSub(a,0,n-1));
    return 0;
}