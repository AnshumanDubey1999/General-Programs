import java.util.Scanner;
class Number_In_Words
{
    public static void main(String args[])         
    {
         int ch=1,fl=0,dot;
         String num,dc;
         Scanner sc = new Scanner(System.in);
         while(ch==1)
         {
              System.out.print("\fENTER A NUMBER : ");
              num ="";
              num = sc.nextLine();
              
              if(num.charAt(0)=='-')
              {
                  fl=1;
                  num= num.substring(1);
              }
              dot= num.indexOf('.');
              System.out.print("THE GIVE NUMBER IN WORDS : ");
              if (fl==1)
                  System.out.print("Minus ");
              if(dot!=-1)
                  System.out.print(numInWords(Long.parseLong(num.substring(0,dot)))+"Point "+decInWords(Long.parseLong(num.substring(dot+1))) +".");
              else
                  System.out.println(numInWords(Long.parseLong(num))+".");
              do
              {
                 System.out.println("\nENTER 1 TO RETRY\n      2 TO GO BACK\n      3 TO EXIT.");
                 ch= sc.nextInt();
                 dc = sc.nextLine();
                 if(ch==3)
                 {
                     System.out.println("\fTHANK U");
                     System.exit(0);
                 }
                 else if(ch==2)
                     return;
                 else if(ch!=1&&ch!=2)
                    System.err.println("INVALID INPUT.\nPLEASE TRY AGAIN.");
              }while(ch!=1&&ch!=2);
         }
    }
    public static int nod(long n)
    {
        if(n<10)return 1;
        return (int)1+nod(n/10);
    }
    public static String decInWords(long n)
    {
        int i,c=0;
        String a09[] = {"Zero ","One ","Two ","Three ","Four ","Five ","Six ","Seven ","Eight ","Nine "};
        String w ="";
        c = nod(n);
        while(n!=0)
        {
            for(i = 0; i<10;i++)
            {
                if(n%10==i)
                    w = a09[i] + w;
            }
            n/=10;
        }
        return w;
    }
    public static String numInWords(long n)
    {
        int i,c=0;
        String a09[] = {"One ","Two ","Three ","Four ","Five ","Six ","Seven ","Eight ","Nine "};
        String a1090[] = {"Ten ","Twenty ","Thirty ","Fourty ","Fifty ","Sixty ","Seventy ","Eighty ","Ninety "};
        String a1119[] = {"Eleven ","Twelve ","Thirteen ","Fourteen ","Fifteen ","Sixteen ","Seventeen ","Eighteen ","Nineteen "};
        String tmbt[] = {"Thousand ","Million ","Billion ","Trillion "},w="";
        c = nod(n);
        if(n==0)
            return "Zero ";
        else
        {
            for(i = 1; i<= c;i+=3,n/=1000)
            { 
                if(i!=1)
                    w = tmbt[i/3 -1] + w;
                if (n%10!=0)
                {
                    if((n%100 - n%10 )!=10)
                        w = a09[(int)n%10 -1] + w;
                    else
                        w = a1119[(int)n%10 - 1]  + w;
                }
                if((n%100 - n%10)!=0&&(n%100 - n%10 )!=10)
                    w = a1090[(int)(n%100 - n%10)/10 -1] + w;
                if((n%1000- n%100)!=0)
                {
                    w = "Hundred " + w;
                    w = a09[(int)(n%1000 - n%100)/100 - 1] + w;
                }
            }
        }
        return w;
    }
}