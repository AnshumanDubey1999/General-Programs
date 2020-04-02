public class List
{
    int i,j,k;
    List next;
    public List(int a, int b, int c, List n)
    {
        i=a;
        j=b;
        k=c;
        next = n;
    }
    public List()
    {
        i=j=k=0;
        next = null;
    }
    public List(int a, int b, int c)
    {
        i=a;
        j=b;
        k=c;
    }
    public int[] get()
    {
        int a[] = {i,j,k};
        return a;
    }
}