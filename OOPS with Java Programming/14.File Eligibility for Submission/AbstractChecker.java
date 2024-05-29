import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class AbstractChecker {

	// write the code..
	public static void main(String[] args) throws IOException{
		Scanner scanner = new Scanner(System.in);
		String fileName = scanner.nextLine();
		try{
			FileReader file = new FileReader(fileName);
			BufferedReader fileInput = new BufferedReader(file);
			String line;
			StringBuilder text = new StringBuilder(); 
			while((line = fileInput.readLine()) != null){
				text.append(line) ;
			}
			if(text.length() < 250){
				System.out.println("Eligible");
			}
			else{
				System.out.println("Not eligible");
			}
			System.out.println("Character count: "+ text.length());
			fileInput.close();
		}
		catch(FileNotFoundException e){
			System.out.println("File does not exist");
		}
		
	
		scanner.close();
	}

}