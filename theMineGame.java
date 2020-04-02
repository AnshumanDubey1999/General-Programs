import java.util.*;
class theMineGame
{
    int lev, mine, life, chance;                
    String gb[][], ab[][];                      //The gameboard
    int x,y;                                 //Pointers
    public theMineGame(int l)
    {
        lev = l;
        mine = life = chance = 0;
        gb = new String[10][90];
        ab = new String[10][90];
        x = y = -1;
    }
    private void set()
    {
        if(lev == 1)
        {
            mine = 135;
            chance= 25;
        }
        else if(lev == 2)
        {
            mine = 225;
            chance= 20;
        }
        if(lev == 3)
        {
            mine = 305;
            chance= 20;
        }
        life = 3;
    }
    private void createGameBoard()
    {
       int i,j,c=0;                         //c is the mine counter
       for(i=0;i<10;i++)
       {
           for (j=0;j<90;j++)
           {
               if(Math.random()*900 < mine && c < (mine + 1))
               {
                   ab[i][j] = "X";
                   c++;
               }
               else
                   ab[i][j] = "0";
               gb[i][j] = "0";    
            }
        }
    }
    public static void main(String args[])
    {
        theMineGame ob = new theMineGame(1);
        ob.set();
        ob.createGameBoard();
        int i,j;
        for(i=0;i<10;i++)
       {
           for (j=0;j<90;j++)
           {
              System.out.print(ob.ab[i][j]+ " ");
            }
            System.out.println();
        }
    }
}