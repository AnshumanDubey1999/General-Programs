import java.util.*;

public class sortEvenOdd{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = 0, i, j, t;
        int arr[] = new int[1000];
        while(sc.hasNextInt()){
            arr[n++] = sc.nextInt();
        }
            
        for(i = 0; i < n; i++){
            for(j = 0; j < n-i-1; j++){
                if(arr[j]>arr[j+1]){
                    t = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = t;
                }
            }
        }

        for(i = 0, j = 0; i < n; i++){
            if(j%2 == arr[i]%2){
                System.out.print(arr[i]+" ");
                j++;
            }
            else{
                System.out.print("X "+arr[i]+" ");
                j+=2;
            }
        }
        System.out.println();
    }
}