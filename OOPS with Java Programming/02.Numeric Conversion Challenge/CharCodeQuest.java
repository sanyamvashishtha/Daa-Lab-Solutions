
import java.util.Scanner;

public class CharCodeQuest {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		char magicalChar = scanner.next().charAt(0);

       // write your code here..
		int c=(int)magicalChar;
		System.out.println(c);
        scanner.close();
    }
}