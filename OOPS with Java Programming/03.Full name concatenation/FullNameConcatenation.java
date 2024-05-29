public class FullNameConcatenation{
	/**
	 * @param args
	 */
	public static void main(String[] args){
		if (args.length < 3) {
			System.out.println("Please provide first name, middle name, and last name as command line arguments.");
			return;
		}
	String first = args[0];
	String middle=args[1];
	String last=args[2];
	String name=first+" "+middle+" "+last;
	System.out.println(name);
	
	}
	
}