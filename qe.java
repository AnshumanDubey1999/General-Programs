import java.util.*;
class qe
{
    public static void main()
    {
        int a = 0 , b = 0 , c = 0,ch=1;
        double d,a1,a2;
        Scanner sc = new Scanner(System.in);
        while(ch==1)
        {
            System.out.println("\fENTER THE VALUE OF A");
            a = sc.nextInt();
            System.out.println("ENTER THE VALUE OF B");
            b = sc.nextInt();
            System.out.println("ENTER THE VALUE OF C");
            c = sc.nextInt();
            if (a!=0)
            {
                d = Math.sqrt(b*b-(4*a*c));
                a1 = (-b +d)/2*a ;
                a2 = (-b -d)/2*a;
            }
            else 
                a1=a2=c/b;
            if (a1==a2)
                System.out.println("THE ONLY VALUE OF x IS "+a1+'.');
            else if (a1/1==a1&&a2/1==a2)
                System.out.println("THE VALUE OF x IS EITHER "+a1+" OR "+a2+'.');
            else 
                System.out.println("x HAS NO REAL VALUES.");
            do
            {
                 System.out.println("ENTER 1 TO RETRY\n      2 TO GO BACK\n      3 TO EXIT.");
                 ch=sc.nextInt();
                 if(ch==2)
                 {

                    break;
                 }
                 else if(ch==3)
                 {
                     System.out.println("\fTHANK U");
                     System.exit(0);
                 }    
                 else if(ch!=1)
                    System.err.println("INVALID INPUT.\nPLEASE TRY AGAIN.");
            }while(ch!=1&&ch!=2);
        }
    } 
}
