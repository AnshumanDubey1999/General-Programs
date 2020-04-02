class pat1
{
    public static void main()
    {
        int i,j;
        for(i=0;i<6;i++)
        {
            for(j=1;j<(6-i);j++)
               System.out.print(" ");
            for(j=i;j>=0;j--)
               System.out.print(j);
            for(j=1;j<=i;j++)
               System.out.print(j);
            System.out.println();
        }
    }
}