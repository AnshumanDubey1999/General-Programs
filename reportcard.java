import java.util.*;    //12^N +25^(N-1) IS DIVISIBLE BY 13. ST 12^(N+1) + 25^N IS ALSO DIVIDIBLE BY 13
class reportcard
{
    public static void main()
    {
        String st[] = new String[6] ;String sb[] = {"ENGLISH LANGUAGE ","ENGLISH LITRATURE","HISTORY          ","GEOGRAPHY        ","PHYSICS          ","CHEMISTRY        ","BIOLOGY          ","MATHS            ","2nd LANGUAGE     ","6th SUBJECT      "};
        int m[] = new int[10] ,i,fm=0,ch;
        Scanner sc = new Scanner(System.in);
        try {
            System.out.println("\fENTER YOUR NAME :");
            st[0] = sc.nextLine();
            System.out.println("ENTER YOUR CLASS :");
            st[1]= sc.nextLine();
            System.out.println("ENTER YOUR SECTION :");
            st[2] = sc.nextLine();
            System.out.println("ENTER YOUR ROLL NO.");
            st[3] = sc.nextLine();
            for(i=0;i<10;i++)
            {
                 System.out.print("ENTER THE MARKS OBTAINED IN "+sb[i]+":-");
                 m[i]= sc.nextInt();
                 fm+= m[i];
            }
        } catch (Exception e) {err.notnum();}
        double pm = fm/10.0;
        if (pm<20)
        {
           st[4]= "D-";
           st[5]= "YOU NEED TO WORK VERY HARD AND FOCUS ON YOUR STUDIES.YOU WILL BE REMAINING IN YOUR PRESENT CLASS FOR 1 MORE YEAR.";
        }
        if (pm>=20 && pm<35)
        {
           st[4]= "D";
           st[5]= "YOU NEED TO WORK VERY HARD AND FOCUS ON YOUR STUDIES.THE SCHOOL IS GIVING YOU THE LAST CHANCE TO BE PROMOTED. ON THE 2nd OF THE NEXT MONTH YOU NEED TO COME TO SCHOOL FOR ORAL EXAMINATION OF ALL SUBJECTS.IT WILL DECIDE YOUR PROMOTION.";
        }
        if (pm>=35 && pm<45)
        {   
           st[4]= "C-";
           st[5]= "YOU NEED TO WORK VERY HARD AND FOCUS ON YOUR STUDIES.THIS TIME THE SCHOOL IS PROMOTING YOU BUT BE CAREFULL ABOUT YOUR NEXT EXAMINATION.";
        }
         if (pm>=45 && pm<55)
        {
           st[4]= "C";
           st[5]= "YOU NEED TO WORK VERY HARD AND FOCUS ON YOUR STUDIES.THIS TIME THE SCHOOL IS PROMOTING YOU BUT BE CAREFULL ABOUT YOUR NEXT EXAMINATION.";
        }
         if (pm>=55 && pm<65)
        {
           st[4]= "-B";
           st[5]= "THOUGH YOU HAVE DONE WELL BUT TRY TO IMPROVE.";
        }
         if (pm>=65 && pm<75)
        {
           st[4]= "B";
           st[5]= "YOU HAVE SHOWN IMPROVEMENT. KEEP IT UP.";
        }
         if (pm>=75 && pm<85)
        {
           st[4]= "A";
           st[5]= "GOOD. KEEP IT UP.";
        }
         if (pm>=85 && pm<90)
        {
           st[4]= "A+";
           st[5]= "VERY GOOD. KEEP IT UP.";
        }
         if (pm>=90 && pm<95)
        {
           st[4]= "A++";
           st[5]= "VERY VERY GOOD. KEEP IT UP.";
        }
         if (pm>=95)
        {
           st[4]= "A++*";
           st[5]= "OUTSTANDING. KEEP IT UP.";
        }
        System.out.print("\f");
        repeat('_',200);
        System.out.println("STUDENT'S NAME: " + st[0]);
        System.out.println("STUDENT'S CLASS: " + st[1]);
        System.out.println("STUDENT'S SECTION: " + st[2]);
        System.out.println("STUDENT'S ROLL NO.: " + st[3]);
        repeat('_',200);
        System.out.println("     SUBJECT     \t|\tMARKS");
        repeat('_',200);
        for(i=0;i<10;i++)
            System.out.println(sb[i]+"\t|\t"+m[i]);
        repeat('_',200);
        System.out.println("TOTAL MARKS : "+fm);
        System.out.println("PERCENTAGE : " + pm+"%");
        System.out.println("GRADE : " +st[4]);
        System.out.println("REMARK : " +st[5]);
        repeat('_',200);
        do
        {
           System.out.println("ENTER 1 TO GO BACK OR 2 TO EXIT.");
           ch = sc.nextInt();
           if(ch==2)
           {
              System.out.println("\fTHANK U.");
              System.exit(0);
            }
           else if(ch!=1)
              System.err.println("INVALID INPUT.\nPLEASE TRY AGAIN.");
        }while(ch!=1);
    }
    public static void repeat(char c,int n)
    {
        for(int i=0;i<n;i++)
           System.out.print(c);
        System.out.println();   
    }
}