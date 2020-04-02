/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		//code
		int t=0, n=0,i,j,k=0,l,a[],temp = 0,flag = 0;
		Scanner sc = new Scanner(System.in);
		t = sc.nextInt();
		int b[][] = new int[t][2];
		for(l=0;l<t;l++)
		{
		    n = sc.nextInt();
		    k = sc.nextInt();
		    a = new int[n];
		    for (i=0;i<n;i++)
               a[i] = sc.nextInt();
            for (i=0;i<n-1;i++)
            {
                flag = 0;
               for (j=i+1;j<n;j++)
               {
                  if (a[i]>a[j])
                  {
                      temp=a[i];
                      a[i]=a[j];
                      a[j]=temp;
                      flag=1;
                  }
               }
               if(flag!=1)
                  break;
            }
            b[l][0]=a[k-1];
            b[l][1]= a[n-k];
            for(i=0;i<n;i++)
		   System.out.println(a[i]);
		}
		for(i=0;i<t;i++)
		   System.out.println(b[i][0]+" "+b[i][1]);
		
	}
}