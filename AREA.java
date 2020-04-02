import java.util.Scanner;
class AREA
{
    public static void main(String args[])         
    {
        int ch=0,a,b,c;
        System.out.print("\f");
        Scanner sc= new Scanner(System.in); 
        while(ch!=8)
        {
           System.out.println("**************MENU**************");
           System.out.println("1. AREA AND PEREMETER OF SQUARE.");
           System.out.println("2. AREA AND PEREMETER OF RECTANGLE.");
           System.out.println("3. AREA AND PEREMETER OF TRIANGLE.");
           System.out.println("4. AREA AND PEREMETER OF PARALELOGRAM.");
           System.out.println("5. AREA AND PEREMETER OF RHOMBUS.");
           System.out.println("6. AREA OF TRAPEZIUM.");
           System.out.println("7. AREA AND PEREMETER OF CIRCLE.\n8. GO TO MAIN MENU.\n9. EXIT.\nENTER YOUR CHOICE");
           ch= sc.nextInt();
           if (ch==1)
           {
               System.out.print("\fENTER THE SIDE OF THE SQUARE : ");
               a= sc.nextInt();
               System.out.println("THE AREA OF THE SQUARE IS = " + (a*a));
               System.out.println("THE PEREMETER OF THE SQUARE IS = " + (4*a));
           }
           else if(ch==2)
           {
                System.out.print("\fENTER THE LENGTH OF THE RECTANGLE : ");
                a =sc.nextInt();
                System.out.print("ENTER THE BREADTH OF THE RECTANGLE : ");
                b = sc.nextInt();
                System.out.println("THE AREA OF THE RECTANGLE IS = " + (a*b));
                System.out.println("THE PEREMETER OF THE RECTANGLE IS = " + (2*(a+b)));
           }
           else if(ch==3)
           {
               System.out.print("\fENTER THE 1st SIDE OF THE TRIANGLE : ");
               a = sc.nextInt();
               System.out.print("ENTER THE 2nd SIDE OF THE TRIANGLE : ");
               b= sc.nextInt();
               System.out.print("ENTER THE 3rd SIDE OF THE TRIANGLE : ");
               c = sc.nextInt();
               double s =(a+b+c)/2.0;
               System.out.println("THE AREA OF THE TRIANGLE IS = " + Math.sqrt(s*(s-a)*(s-b)*(s-c)));
               System.out.println("THE PEREMETER OF THE TRIANGLE IS = " + (2*s));
           }
           else if (ch == 4)
           {
               System.out.print("\fENTER THE HEIGHT OF THE PARALELOGRAM : ");
               a= sc.nextInt();
               System.out.print("ENTER THE BASE OF THE PARALELOGRAM : ");
               b = sc.nextInt();
               System.out.println("THE AREA OF THE PARALELOGRAM IS = " + (a*b));
               System.out.println("THE PEREMETER OF THE PARALELOGRAM IS = " + (2*(a+b)));
           }
           else if (ch==5)
           {
               System.out.print("\fENTER THE HEIGHT OF THE RHOMBAS : ");
               a = sc.nextInt();
               System.out.print("ENTER THE BASE OF THE RHOMBAS : ");
               b = sc.nextInt();
               System.out.println("THE AREA OF THE RHOMBAS IS = " + (a*b));
               System.out.println("THE PEREMETER OF THE RHOMBAS IS = " + (4*b));
           }
           else if (ch==6)
           {
               System.out.print("\fENTER THE DISTANCE BETWEENTHE 2 PARALLEL SIDES : ");
               a= sc.nextInt();
               System.out.print("ENTER THE 1st PARRALEL SIDE OF THE TRAPEZIUM : ");
               b = sc.nextInt();
               System.out.print("ENTER THE 2nd PARRALEL SIDE OF THE TRAPEZIUM : ");
               c = sc.nextInt();
               System.out.println("THE AREA OF THE TRAPEZIUM IS = " + ((1.0*(b+c)/2)*a));
           }
           else if (ch==7)
           {
                System.out.print("\fENTER THE RADIUS OF THE CIRCLE : ");
                a = sc.nextInt();
                System.out.println("THE AREA OF THE CIRCLE IS = " + (3.14*a*a));
                System.out.println("THE PEREMETER OF THE CIRCLE IS = " + (2*3.14*a));
           }
           else if (ch==8){}
           else if(ch==9)
           { 
               System.out.println("\fTHANK U");
               System.exit(0);
           }
           else
               System.err.println("INVALID INPUT.\nPLEASE TRY AGAIN");
        }
    }
}