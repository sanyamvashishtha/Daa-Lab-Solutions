import java.util.Scanner;

public class ArrayIndexHandler {
    public static void main(String[] args) {

	// write the code...
	//initialise and declare array
	Scanner scanner = new Scanner(System.in);
	int size= scanner.nextInt();
	int[] arr =new int[size];
	for(int i=0;i<size;i++){
		arr[i]=scanner.nextInt();
	}
	int index=scanner.nextInt();
     try {
		 int element=arr[index];
		System.out.println("Element at index " + index + " is: " + element );
	    } catch ( ArrayIndexOutOfBoundsException e ) {
            System.out.println("Error: Index out of bounds");
        }
        scanner.close();
    }
}