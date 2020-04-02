import java.io.*;
import virus.*;
class numbers
{
    public static void main()throws Exception
    {
        long num = 0; int c = 0,ch=1,sum = 0;
        BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
      while(ch==1)
      {
        try {
             System.out.print("\f");
            System.out.println("ENTER THE NUMBER.");
             num = Long.parseLong(br.readLine());
        sum=0;
        for(long no = 1; no<=num;no++)
        {
        if (num%no == 0)
        {
            c++;
            sum+=no;
         System.out.println(c+".THE NUMBER IS DIVIDED BY " + no+ " (" + no + " X " + (num/no)+ ")." );
        }
        }
        System.out.println(sum);
        if(Bo.isPrimeNumber(num))System.out.println(num+" IS A PRIME NUMBER.");
        if(Bo.isPalindromeNumber(num))System.out.println(num+" IS A PALINDROME NUMBER.");
        if(Bo.isPerfectNumber(num))System.out.println(num+" IS A PERFECT NUMBER.");
        if(Bo.isArmstrongNumber(num))System.out.println(num+" IS A ARMSTRONG NUMBER.");
        if(Bo.isMagicNumber(num))System.out.println(num+" IS A MAGIC NUMBER.");
        if(Bo.isNeonNumber(num))System.out.println(num+" IS A NEON NUMBER.");
        if( Bo.isTriangularNumber(num))System.out.println(num+" IS A TRIANGULAR NUMBER.");
        if( Bo.isKaprekarNumber(num))System.out.println(num+" IS A KAPREKAR NUMBER.");
        if( Bo.isSmithNumber(num))System.out.println(num+" IS A SMITH NUMBER.");
        } catch (Exception e) {err.notnum();}
        do
            {
                 System.out.println("ENTER 1 TO RETRY\n      2 TO GO BACK\n      3 TO EXIT.");
                 ch= Integer.parseInt(br.readLine());
                 if(ch==3)
                 {
                     System.out.println("\fTHANK U");
                     System.exit(0);
                 }    
                 else if(ch!=1&&ch!=2)
                    System.err.println("INVALID INPUT.\nPLEASE TRY AGAIN.");
            }while(ch!=1&&ch!=2);
      }
    }
}