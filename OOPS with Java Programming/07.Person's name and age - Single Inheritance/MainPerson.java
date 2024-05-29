import java.util.Scanner;

	// write your code here..
class Person{
	String name;
	Scanner input =new Scanner(System.in);
	void inputName(){
		System.out.print("Enter name: ");
		name=input.nextLine();
	}
	void displayName(){
		
		System.out.println("Name: "+name);
	}
}
class Citizen extends Person{
	int age;
	void inputAge(){
		System.out.print("Enter age: ");
		age=input.nextInt();
	}
	void displayAge(){
		System.out.println("Age: "+age);
	}
}
public class MainPerson {
    public static void main(String[] args) {
        Citizen citizen = new Citizen();
        citizen.inputName();
        citizen.displayName();
        citizen.inputAge();
        citizen.displayAge();
    }
}