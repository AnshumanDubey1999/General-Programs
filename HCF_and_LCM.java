import java.io.*; import java.util.*;
class HCF_and_LCM 
{
    public static void main() throws IOException
    {
        int a,b,h=1,c=1;
        Scanner sc = new Scanner(System.in);
         while(c==1)
        {
             System.out.print("\fENTER THE 1st NUMBER: ");
             a=sc.nextInt();
             System.out.print("ENTER THE 2nd NUMBER: ");
             b=sc.nextInt();
             for (int i =a;i>=1;i--)
             {   
                     if(a%i==0&&b%i==0)
                     {
                         h=i; 
                         break;
                     }
             }
             System.out.println("HCF = "+h+"\nLCM = "+((a*b)/h));
             do
             {
                 System.out.println("ENTER 1 TO RETRY\n      2 TO GO BACK\n      3 TO EXIT.");
                 c=sc.nextInt();
                 if(c==2)
                 {

                    break;
                 }
                 else if(c==3)
                 {
                     System.out.println("\fTHANK U");
                     System.exit(0);
                 }    
                 else if(c!=1)
                    System.err.println("INVALID INPUT.\nPLEASE TRY AGAIN.");
             }while(c!=1&&c!=2);
        }
    }
}