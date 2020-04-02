import java.util.*;
class CALENDER
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int m=0,y=0,x=0,i,j=1, l = 1,c=1,ch=1;
        
        while(ch==1)
        {
	System.out.println("\fENTER MONTH AND YEAR.");
	j=1;
        m= sc.nextInt();
        y = sc.nextInt();
        x = getday(1,m,y);
        c=(m==1||m==3||m==5||m==7||m==8||m==10||m==12)?31:((m==4|| m == 6 || m==9 || m ==11)?30:(y%4==0)?29:28);
        System.out.println("SU\tMO\tTU\tWE\tTH\tFR\tSA");
        for (i = 1;i<=x;i++)
        {
            System.out.print("\t");
        }
        for (i = 1 ; i<7; i++)
        {
            l=j;
            for (;((j<=((i==1)?(7*i-x):l+6))&&j<=c);j++)                                
              System.out.print(j+"\t");
            System.out.println();  
        }
        do
            {
                 System.out.println("ENTER 1 TO RETRY\n      2 TO GO BACK\n      3 TO EXIT.");
                 ch= sc.nextInt();
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
    public static int getday(int d,int m,int y)
    {
      int l=0,f=0 , x=0 , i;
      y=y-1900;
      
      for (i= 1 ; i<=m-1;i++)
      {
          if (i==1||i==3||i==5||i==7||i==8||i==10||i==12)
            x+=31;
          else if( i==4|| i == 6 || i==9 || i ==11)
            x+=30;
          else
          {
              if (y%4==0)
                x+=29;
              else
                x+=28;
          }
      }
      f=365*y+ x + d;
      f=(y%4==0)?f+(y/4) -1 : f + (y/4);
      return f%7;
    }
}
        