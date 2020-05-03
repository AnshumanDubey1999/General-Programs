import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class puzzle15 {
    static PriorityQueue<Node> queue;
    static final int N = 4;
   // static int counter = 0;
    static Node finalState;
    public static void main(String[] args) {
        int i, j;
        //int start[] = {5,1,2,4,9,6,3,8,13,10,7,11,0,14,15,12};
        //int hard[] = {11, 5, 12, 14, 15, 2, 0, 9, 13, 7, 6, 1, 3, 10, 4, 8};
        //int hard[] = {6, 1, 3, 4, 2, 7, 15, 8, 5, 10, 9, 11, 13, 14, 12, 0};
        int end[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0};
        Compare compare = new Compare();
        queue = new PriorityQueue<>(compare);
        Node initialState = new Node();
        Scanner scanner = new Scanner(System.in);
        finalState = new Node();
        System.out.println("Enter Initial State(0 for empty):");
        for(i = 0; i < N; i++){
            for(j = 0; j < N; j++){
                initialState.state[i][j] = scanner.nextInt();
                //initialState.state[i][j] = hard[i*4+j];
                if(initialState.state[i][j]==0){
                    initialState.xCord = i;
                    initialState.yCord = j;
                }
            }
        }
        for(i = 0; i < N; i++){
            for(j = 0; j < N; j++){
                finalState.state[i][j] = end[i*4+j];
            }
        }
        //PRINT.ArrayMatrix(initialState.state);
        //PRINT.ArrayMatrix(finalState.state);
        initialState.level = 0;
        initialState.setCost(finalState);

        queue.add(initialState);
        System.out.println("And the search begins: ");
        findSolution();
    }

    // private static void display(Node parent){
    //     Scanner scanner = new Scanner(System.in);
    //     counter++;
    //     System.out.println(counter+".\nLevel: "+ parent.level);
    //     PRINT.ArrayMatrix(parent.state);
    //     System.out.println("Cost: "+parent.cost);
    //     System.out.println("Path Taken: "+ parent.pastDirections.toString());
    //     //scanner.next();
    // }

    private static void findSolution() {
        int bonusPoints = 0;
        while (!queue.isEmpty()){
            Node parent = queue.remove();
            Node[] temp = new Node[4];
            char lastDirection;
            if(parent.pastDirections.length()>0)
                lastDirection = parent.pastDirections.charAt(parent.pastDirections.length()-1);
            else
                lastDirection = ' ';
            //display(parent);
            if(parent.xCord>0 && lastDirection!='D'){                 //UP
                temp[0] = new Node(parent, 'U');
                temp[0].setCost(finalState);
                if(temp[0].cost == temp[0].level-bonusPoints)
                    solved(temp[0]);
                queue.add(temp[0]);
            }
            if(parent.xCord<(N-1) && lastDirection!='U'){                 //DOWN
                temp[1] = new Node(parent, 'D');
                temp[1].setCost(finalState);
                if(temp[1].cost == temp[1].level-bonusPoints)
                    solved(temp[1]);
                queue.add(temp[1]);
            }
            if(parent.yCord>0 && lastDirection!='R'){                 //LEFT
                temp[2] = new Node(parent, 'L');
                temp[2].setCost(finalState);
                if(temp[2].cost == temp[2].level-bonusPoints)
                    solved(temp[2]);
                queue.add(temp[2]);
            }
            if(parent.yCord<(N-1) && lastDirection!='L'){                 //RIGHT
                temp[3] = new Node(parent, 'R');
                temp[3].setCost(finalState);
                if(temp[3].cost == temp[3].level-bonusPoints)
                    solved(temp[3]);
                queue.add(temp[3]);
            }
        }
        System.out.println("No possible combination found!");
    }

    private static void solved(Node temp) {
        System.out.println("Puzzle solved in "+temp.level+ " steps.\nMoves made: "+temp.pastDirections.toString());
        System.exit(0);
    }
}
class Node{
    int state[][], cost, level, xCord, yCord;
    StringBuffer pastDirections;
    Node(){
        state = new int[4][4];
        cost = level = 0;
        pastDirections = new StringBuffer(100);
    }
    Node(Node parent, char direction){
        state = new int[4][4];
        copyState(parent);
        level = parent.level+1;
        cost = 0;
        pastDirections = new StringBuffer(100);
        pastDirections.append(parent.pastDirections);
        pastDirections.append(direction);
        if(direction=='U'){
            xCord = parent.xCord-1;
            yCord = parent.yCord;
        }
        else if(direction=='D'){
            xCord = parent.xCord+1;
            yCord = parent.yCord;
        }
        else if(direction=='L'){
            xCord = parent.xCord;
            yCord = parent.yCord-1;
        }
        else{
            xCord = parent.xCord;
            yCord = parent.yCord+1;
        }
        state[parent.xCord][parent.yCord] = state[xCord][yCord];
        state[xCord][yCord] = 0;
    }
    void copyState(Node from){
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                state[i][j] = from.state[i][j];
            }
        }
    }
    void setCost(Node finalState){
        cost = level;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if(state[i][j] != finalState.state[i][j])
                    cost++;
            }
        }
        //Extra
/*
        if(state[0][0]==1){           //ROW 1
            cost-=100;
            if (state[0][1]==2){
                cost-=90;
                if(state[0][2]==3 && state[0][3]==4){         //Ist Row correct
                    cost-=100;
                    if(state[1][0]==5){
                        cost-=100;
                        if(state[1][1]==6){
                            cost-=90;
                            if(state[1][2]==7 && state[1][3]==8) {               //2nd Row Correct
                                cost-=100;
                                if(state[2][0]==9 && state[3][0]==13){          //1st Column Correct
                                    cost-=100;
                                    if(state[2][1]==10 && state[3][1]==14)          //2nd Column Correct
                                        cost-=100;
                                }
                            }
                        }
                    }
                }
            }
        }*/
    }
}

class Compare implements Comparator<Node>{
    @Override
    public int compare(Node o1, Node o2) {
        return o1.cost-o2.cost;
    }
}