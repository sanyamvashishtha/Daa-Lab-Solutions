import java.util.Scanner;

public class Book {
  
	// write your code here..
	String bookTitle;
	int bookpublicationYear;
	void setTitle(String title){
		bookTitle=title;
	}
	void setPublicationYear(int publicationYear){
		bookpublicationYear=publicationYear;
	}
	String getTitle(){
		return bookTitle;
	}
	int getPublicationYear(){
		return bookpublicationYear;
	}
	public static void main(String[] args){
		Book libraryBook =new Book();
		Scanner scanner= new Scanner(System.in);
        System.out.print("Title of the book: ");
        String userEnteredTitle = scanner.nextLine();
        libraryBook.setTitle(userEnteredTitle);

        System.out.print("Publication year of the book: ");
        int userEnteredYear = scanner.nextInt();
        libraryBook.setPublicationYear(userEnteredYear);

        // Display details
        System.out.println("Details of the Library Book:");
        System.out.println("Title: " + libraryBook.getTitle());
        System.out.println("Publication Year: " + libraryBook.getPublicationYear());
		scanner.close();
    }
}