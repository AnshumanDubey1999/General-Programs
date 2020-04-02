import java.io.*;
class MENU
{
    public static void main() throws Exception         
    {
      
        int sw = 0;
       String con = "n";
       BufferedReader y = new BufferedReader (new InputStreamReader(System.in));
       System.out.print("\f");
         while(sw!=13)
         {
            
            System.out.println("\f**************MENU**************");
            System.out.println("1. HCF AND LCM OF 2 NO.s");
            System.out.println("2. AREA AND PEREMETER OF GEOMETRIC FIGURES.");
            System.out.println("3. VOLUME AND SURFACE AREA OF GEOMETRIC FIGURES.");
            System.out.println("4. SI ON PRINCIPLE.");
            System.out.println("5. CI ON PRINCIPLE.");
            System.out.println("6. VALUE OF X IN A QUADRETIC Eq.");
            System.out.println("7. BUILDING A REPORTCARD");
            System.out.println("8. NO. OF WORDS IN A SENTENCE");
            System.out.println("9. NO. OF PITHAGORAS TRIPLETS");
            System.out.println("10. PATTERN PRINTING");
            System.out.println("11. NUMBERS");
            System.out.println("12. CALENDER");
            System.out.println("13. NUMBER IN WORDS.");            
            System.out.print("14. EXIT\nENTER YOUR CHOICE : ");
            sw = Integer.parseInt(y.readLine());
            switch (sw)
            {
                case 1: HCF_and_LCM.main();break;
                case 2: AREA.main();break;
                case 3: VOLUME.main();break;
                case 4: si.main();break;
                case 5: ci.main();break;
                case 6: qe.main();break;
                case 7: reportcard.main();break;
                case 8: Number_Of_Words.main();break;
                case 9: p3.main();break;
                case 10: patterns.main();break;
                case 11: numbers.main();break;
                case 12: CALENDER.main();break;
                case 13: Number_In_Words.main();break;
                case 14: System.out.println("\fTHANK U.");System.exit(0);
                default: System.err.println("INVALID CHOICE.\nPLEASE TRY AGAIN!");break;
            }
       }
    }
}