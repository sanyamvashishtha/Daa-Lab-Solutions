import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class ReverseFileContent {

	// write your code here..
	public static void main(String[] args) throws IOException{
		Scanner scanner = new Scanner(System.in);
		String fileName = scanner.nextLine();
		try{
			FileReader file = new FileReader(fileName);
			BufferedReader fileInput = new BufferedReader(file);
			String line;
			String[] fileText = new String[100];
			int count =0;
			while((line = fileInput.readLine()) != null){
				fileText[count]=line;
				count++;
			}
			for(int i=count-1 ; i>= 0; i--){
				System.out.println(fileText[i]);
			}
            fileInput.close();
		}
		catch(IOException e){
		System.out.println("Error: Unable to read the file");
			}
        scanner.close();    
        
	}
}