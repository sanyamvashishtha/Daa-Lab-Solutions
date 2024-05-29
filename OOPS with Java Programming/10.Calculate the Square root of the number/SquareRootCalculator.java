import java.util.Scanner;
public class SquareRootCalculator {
    public static void main(String[] args) {

		// write the code..
		double squareRoot;
		Scanner scanner =new Scanner(System.in);
        try {
			String input=scanner.nextLine();
			int number =Integer.parseInt(input);
			if(number < 0){
				throw new IllegalArgumentException();
			}
			squareRoot=Math.sqrt(number);
			System.out.printf("%.2f\n",squareRoot);
		        } 
        
        catch ( NumberFormatException e  ) {
        	System.out.println("Error: Invalid input");
        } 
        
        catch (IllegalArgumentException e   ) {
        	
            System.out.println("Error: Square root of a negative number is not possible");
        }
		finally {
			scanner.close();
		}
        
    }
}