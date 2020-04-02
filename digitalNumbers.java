import java.util.*;
public class digitalNumbers{
	public static void main(String args[]){
		String[][] data = new String[10][3];
		getPattern(data);
		System.out.print("Enter the number to be printed: ");
		String num;
		Scanner sc = new Scanner(System.in);
		num = sc.nextLine();
		System.out.println("Required pattern is:");
		for (int j = 0;j<3;j++) {
			for(int i = 0; i < num.length(); i++){
				char c = num.charAt(i);
				if(c-48 >9){
					System.out.println("ERROR!!!");
					System.exit(0);
				}
				System.out.print(data[c-48][j] + " ");
			}
			System.out.println();
		}
	}
	public static void getPattern(String[][] data){
		data[0][0] = " _ ";
		data[0][1] = "| |";
		data[0][2] = "|_|";

		data[1][0] = "   ";
		data[1][1] = "  |";
		data[1][2] = "  |";

		data[2][0] = " _ ";
		data[2][1] = " _|";
		data[2][2] = "|_ ";

		data[3][0] = " _ ";
		data[3][1] = " _|";
		data[3][2] = " _|";

		data[4][0] = "   ";
		data[4][1] = "|_|";
		data[4][2] = "  |";

		data[5][0] = " _ ";
		data[5][1] = "|_ ";
		data[5][2] = " _|";

		data[6][0] = " _ ";
		data[6][1] = "|_ ";
		data[6][2] = "|_|";

		data[7][0] = " _ ";
		data[7][1] = "  |";
		data[7][2] = "  |";

		data[8][0] = " _ ";
		data[8][1] = "|_|";
		data[8][2] = "|_|";

		data[9][0] = " _ ";
		data[9][1] = "|_|";
		data[9][2] = " _|";

	}
}
