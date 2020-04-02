import java.util.*;
public class Test
{
    private int m;
    private List hd;
    Scanner sc = new Scanner(System.in);
    public static void main(String args[])
    {
        Test ob = new Test();
        int a,b;
        System.out.println("\fEntre the Starting & Ending Numbers :");
        a = ob.sc.nextInt();
        b = ob.sc.nextInt();
        ob.enter(a,b);
        ob.display(a,b);
    }
    public void enter(int a, int b)
    {
        List list = null;
        int n = 0;
        System.out.println("\fThe Test Starts Now :");
        for(int i = a; i<=b ; i++)
        {
            for(int j = 1; j<11; j++)
            {
                while(true)
                {
                    System.out.print(i + " x " + j + " = ");
                    try
                    {
                        n = sc.nextInt();
                        break;
                    }catch(Exception E)
                    {
                        System.out.println("ENTER NUMBERS ONLY!");
                        sc.next();
                        continue;
                    }
                }
                if(n == 24860)
                   return;
                if(n == (i*j))
                    m++;
                else
                {
                    if(list == null)
                    {
                        list = new List(i,j,n);
                        hd = list;
                    }
                    else
                    {
                        list.next = new List(i,j,n);
                        list = list.next;
                    }
                }
            }
        }
    }
    public void display(int a, int b)
    {
        int rgc = 0, x[],c=1;
        System.out.println("Test completed.\nEnter Result Generation Code :");
        while(rgc!=2580)
            rgc = sc.nextInt();
        System.out.println("\fMarks Obtained : " +m+" ("+(m*10.0/(b-a+1))+"%).");
        if(hd!=null)
            System.out.println("Mistakes Made :");
        while(hd!=null)
        {
            x = hd.get();
            hd = hd.next;
            System.out.println(c++ + ". " +x[0] + " x " + x[1] + " = " + x[2] +" (Correct Answer = " + (x[0]*x[1]) + ").");
        }
    }
}