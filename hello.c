#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int t,n,m,sum,i,j;
	int *f,*p, *arr;
	int min;
	
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d %d",&n,&m);
	    f = (int *)malloc(sizeof(int)*n);
	    p = (int *)malloc(sizeof(int)*n);  //Memory Allocation
	    arr = (int *)malloc(sizeof(int)*(m+1));
	    for (i = 0; i <= m; ++i)
	    {
	    	arr[i] = 0;
	    }
	    for(i=0;i<n;i++)
	    {
	        scanf("%d",&f[i]);
	    }
	    for(i=0;i<n;i++)
	    {
	        scanf("%d",&p[i]);
	        arr[f[i]]+=p[i];
	    }
	    for (i = 1; i <= m; ++i)
	    {
	    	if(arr[i]!=0){
	    		min = arr[i];
	    		break;
	    	}
	    }
	    for(i=2;i<=m;i++)
	    {   
	        if(arr[i]<min && arr[i]!=0)
	        	min = arr[i];
	    }
	    printf("%d\n",min);
	    free(f);
	    free(p);
	    free(arr);
	}
	return 0;
}