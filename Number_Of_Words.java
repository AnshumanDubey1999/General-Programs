import java.io.*;
class Number_Of_Words
{
    public static void main() throws Exception
  {
      String a = "abcdefghijklmnopqrstuvwxyz1234567890,./?><;'\":[]\\|}{`-=+_)(*&^%$#@!~",p = null;
      String A = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
      int c[] = new int[68],d=0, sp=1,ch=1,i,j;
      char s;
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      while(ch==1)
      {  
            for(i=0;i<68;i++)c[i]=0;
            System.out.println("\fENTER A WORD, SENTENCE OR A PARAGRAPH");
            p = br.readLine();
            p = p.trim();
            for (i = 0;i<(p.length());i++)
            {
               s = p.charAt(i);
                for (j = 0;j<68;j++)
               {
                   if (s==(a.charAt(j)) || (j<26 && s ==(A.charAt(j))))
                   {
                    c[j]++;
                    break;
                   }
                   else if (s==' '&& p.charAt(i+1)!=' ')
                   {
                       sp++;
                       break;
                    }
               }
            }
            for (i = 0;i<68;i++)
            {
                if(c[i]!=0)
                {
                    d++;
                    System.out.println(d+". "+a.charAt(i)+" = "+c[i]);
                }
            }
            System.out.println("NO. OF WORDS = " + sp+'.');
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