import java.io.*;import java.util.*;
class p3
{
    public static void main()
    {
        int i,j,k,c=1,n=0,ch;
        Scanner sc = new Scanner(System.in);
        System.out.println("\fENTER THE NO. OF PYTHAGORAS TRIPLETS NEEDED");
        try{
        n=sc.nextInt();
        for(i=1;c<=n;i++)
        {
            for(j=1;j<i;j++)
            {
              for(k=1;k<j;k++)
              {
                if(i*i==(j*j +k*k))
                {
                 System.out.println(c+". "+i+","+j+","+k);
                 c++;
                }
              }
            }  
        }
       }catch (Exception e){err.notnum();}
       do
        {
           System.out.println("ENTER 1 TO GO BACK OR 2 TO EXIT.");
           ch = sc.nextInt();
           if(ch==2)
           {
              System.out.println("\fTHANK U.");
              System.exit(0);
            }
           else if(ch!=1)
              System.err.println("INVALID INPUT.\nPLEASE TRY AGAIN.");
        }while(ch!=1);
    }
}