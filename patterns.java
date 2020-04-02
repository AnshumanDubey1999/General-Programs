import java.io.*;//REDO FUCKED UP PROG
import virus.*;
class patterns
{
    public static void main() throws Exception
    {
        int ch =0,n=0,e=1;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String a = "fg",x;
        while (e==1)
        {
        e = 0;
        System.out.println("\n1.");
        pt.lrat("*",3);
        System.out.println("\n2.");
        pt.rrat("*",3);
        System.out.println("\n3.");
        pt.igt("*",3);
        System.out.println("\n4.");
        pt.it("*",3);
        System.out.println("\n5.");
        pt.hd("*",3);
        System.out.println("\n6.");
        pt.h2sd("*",5);
        System.out.println("\n7.");
        pt.gd("*",3);
        System.out.print("\nENTER THE PATTERN U WANT : ");
        ch = Integer.parseInt(br.readLine());
        System.out.print("\fENTER THE SIZE OF PATTERN : ");
        n = Integer.parseInt(br.readLine());
        System.out.print("ENTER WHAT U WANT TO PRINT : ");
        a = br.readLine();
        if (ch==1) pt.lrat(a,n);
        else if (ch==2) pt.rrat(a,n);
        else if (ch==3) pt.igt(a,n);
        else if (ch==4) pt.it(a,n);
        else if (ch==5) pt.hd(a,n);
        else if (ch==6) pt.h2sd(a,n);
        else if (ch==7) pt.gd(a,n);
        else
        {
            System.err.println("INVALID INPUT.\nPLEASE TRY AGAIN!");
            e=1;
        }
       }
       do
        {
           System.out.println("ENTER 1 TO GO BACK OR 2 TO EXIT.");
           ch = Integer.parseInt(br.readLine());
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
        