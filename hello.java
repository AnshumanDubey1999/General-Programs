import java.util.*;

public class abc{
    public static void main(String args[]){
        int a,b;
        Scanner sc = new Scanner(System.in);
        a = sc.nextInt();
        b = sc.nextInt();
        int arr[][] = new int[a][b];
        for(int i = 0; i &lt; a; i++){
            for(int j = 0; j&lt; b; j++)
                arr[i][j]=sc.nextInt();
        }
        for(int i = 0; i &lt; a; i++){
            for(int j = b-1; j&gt;=0; j--)
                System.out.print(arr[i][j]+" ");
            System.out.println();
        }
    }
}