import java.util.*;
class ci
{
    public static void main()
    {
        int p = 0 , r = 0 , t = 0,c =1;
        Scanner sc = new Scanner(System.in);
        while(c==1)
        {
        
            System.out.println("\fENTER THE PRINCIPAL");
            p = sc.nextInt();
            System.out.println("ENTER THE RATE");
            r = sc.nextInt();
            System.out.println("ENTER THE TIME");
            t = sc.nextInt();
        
            double ra = (100+r)/100.0 , a = p* Math.pow(ra,t);
            System.out.println("THE COMPOUND INTREST IS = Rs" + (a-p));
            System.out.println("THE AMOUNT IS = Rs" + a);
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