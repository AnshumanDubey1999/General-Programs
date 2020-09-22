import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
	public static void main (String[] args) {
	   Scanner myObj2 = new Scanner(System.in);
	   int i = myObj2.nextInt();
	   while(i>0){
	       System.out.println(kadane());
	       i--;
	   }
	}
	    static int kadane(){
	    int j;
	    Scanner myObj = new Scanner(System.in);
	    int N = myObj.nextInt();
	    int[] arr = new int[N];
	    for(j=0;j<N;j++){
	        arr[j] = myObj.nextInt();
	    }
	    int max_over = Integer.MIN_VALUE,max_local=0;
	    for(int i=0;i<N;i++){
	        max_local=max_local + arr[i];
	        if(max_over < max_local){
	            max_over=max_local;
	        }
	        if(max_local<0){
	            max_local=0;
	        }
	    }
	    return max_over;
	}
}
