import java.util.Scanner;

public class FloatToInt {
	
    public static void main(String[] args) {
    	
        Scanner scanner = new Scanner(System.in);

        float floatValue = scanner.nextFloat();

		// write your code here..
       int c=(int)floatValue;
		System.out.println(c);
        //close the scanner
        scanner.close();
    }
}