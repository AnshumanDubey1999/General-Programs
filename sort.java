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
}
