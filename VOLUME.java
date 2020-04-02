import java.io.*;import java.util.*;
class VOLUME
{
    public static void main() throws IOException         
    {
      
        int ch=0,a,b,c;
       Scanner sc = new Scanner(System.in);
       System.out.print("\f");
       while (ch!=6)
       {
           System.out.println("**************MENU**************");
           System.out.println("1. VOLUME AND SURFACE AREA OF CUBE.");
           System.out.println("2. VOLUME AND SURFACE AREA OF CUBOIDE.");
           System.out.println("3. VOLUME AND SURFACE AREA OF CONE.");
           System.out.println("4. VOLUME AND SURFACE AREA OF CYLINDER.");
           System.out.println("5. VOLUME AND SURFACE AREA OF SPHERE.\n6. GO TO MAIN MENU.\n7. EXIT.\nENTER YOUR CHOICE");
           ch = sc.nextInt();               //Input
           if (ch==1)
           {
               System.out.print("\fENTER THE SIDE OF THE CUBE : ");
               a= sc.nextInt();
               System.out.println("THE VOLUME OF THE CUBE IS = " + (a*a*a));
               System.out.println("THE SURFACE AREA OF THE CUBE IS = " + (6*a*a));
           }
           else if(ch==2)
           {
                System.out.print("\fENTER THE LENGTH OF THE CUBOIDE : ");
                a =sc.nextInt();
                System.out.print("ENTER THE BREADTH OF THE CUBOIDE : ");
                b = sc.nextInt();
                System.out.print("ENTER THE HEIGHT OF THE CUBOIDE : ");
                c = sc.nextInt();
                System.out.println("THE VOLUME OF THE CUBOIDE IS = " + (a*b*c));
                System.out.println("THE SURFACE AREA OF THE CUBOIDE IS = " + (2*(a*b + b*c + c*a)));
           }
           else if(ch==3)
           {
               System.out.print("\fENTER THE RADIUS OF CONE : ");
               a = sc.nextInt();
               System.out.print("ENTER THE HEIGHT OF CONE : ");
               b= sc.nextInt();
               System.out.println("THE VOLUME OF THE TRIANGLE IS = " + (3.14*a*a*b/3.0));
               System.out.println("THE SURFACE AREA OF THE TRIANGLE IS = " + (3.14*a*(a+Math.sqrt(a*a + b*b))));
           }
           else if (ch == 4)
           {
               System.out.print("\fENTER THE HEIGHT OF THE CYLINDER : ");
               a= sc.nextInt();
               System.out.print("ENTER THE RADIUS OF CYLINDER : ");
               b = sc.nextInt();
               System.out.println("THE VOLUME OF THE CYLINDER IS = " + (3.14*b*b*a));
               System.out.println("THE SURFACE AREA OF THE CYLINDER IS = " + (2*3.14*b*(a+b)));
           }
           else if (ch==5)
           {
                System.out.print("\fENTER THE RADIUS OF THE SPHERE : ");
                a = sc.nextInt();
                System.out.println("THE VOLUME OF THE SPHERE IS = " + (4*3.14*a*a*a/3.0));
                System.out.println("THE SURFACE AREA OF THE sPHERE IS = " + (4*3.14*a*a));
           }
           else if (ch==6){}
           else if(ch==7)
           { 
               System.out.println("\fTHANK U");
               System.exit(0);
           }
           else
               System.err.println("INVALID INPUT.\nPLEASE TRY AGAIN");
        }
    }
}