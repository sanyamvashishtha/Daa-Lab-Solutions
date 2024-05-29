import java.util.Scanner;
class PalindromeChecker{
	public static void main(String[] args)throws Exception{
		Scanner scanner = new Scanner(System.in);
		String input = scanner.nextLine();
		String new_input=input.toLowerCase();
		StringBuilder reversed = new StringBuilder(new_input).reverse();
		boolean result = new_input.equals(reversed.toString());
		if(result){
			System.out.println(input+" is a palindrome");
		}
		else{
			System.out.println(input+" is not a palindrome");
		}
        scanner.close();
	}
	
}
