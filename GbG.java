/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GbG {
	public static void main (String[] args) {
		//code
	    int t=0;
	    Scanner sc = new Scanner(System.in);
	    t= sc.nextInt();
	    while(t>0)
	    {
	        func();
	        t--;
	    }
	}
	public static void func()
	{
	     int a[],k=0,n=0,i,j,m,l;
    	Scanner sc = new Scanner(System.in);
    	k = sc.nextInt();
    	n= sc.nextInt();
    	a = new int[k*n];
    	for(i=0;i<k*n;i++)
    	{
    	    j = sc.nextInt();
    	    m=0;
    	    while(j<a[m])
        	    m++;
	    
	       for(l=i;l>m;l--)
	          a[l]= a [l-1];
	       a[m] = j;
	       
    	}
    	for(i=0;i<k*n;i++)
    	    System.out.print(a[i]);
    	    return;
	}
}