import java.util.*;
class sort
{
    public static void main() throws Exception
    {
        int a[] =new int[5],i,j,k,l=-1,temp;
        Scanner sc = new Scanner(System.in);
        System.out.println("\fENTER 5 NUMBERS");
        for (i=0;i<5;i++)
           a[i] = sc.nextInt();
        for (i=0;i<4;i++)
        {
            for (j=0;j<5;j++)
            {
               if (a[i]>a[j])
               {
                   temp=a[i];
                   a[i]=a[j];
                   a[j]=temp;
               }
            }
            l--;
        }
    }

    void merge(int arr[], int l, int m, int u){
        int[] A = new int[u-l+1];
        int i, j, k;

        i = l;
        j = m+1;
        k = 0;
        while((i <= m) && (j <= u)){
            if(arr[i]<arr[j])
                A[k++] = arr[i++];
            else
                A[k++] = arr[j++];
        }

        while(i <= m)
            A[k++] = arr[i++];
        while(j <= u)
            A[k++] = arr[j++];

        for(i = l; i <= u; i++)
            arr[i] = A[i-l];
    }

    void mergeSort(int arr[], int i, int j){
        int mid = (i+j)/2;
        if(i<j){
            mergeSort(arr, i , mid);
            mergeSort(arr, mid+1, j);
            merge(arr, i, mid, j);
        }
    }
}
