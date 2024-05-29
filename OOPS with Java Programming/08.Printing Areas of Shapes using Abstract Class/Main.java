import java.util.Scanner;
abstract class Shape {

	// write your code here
	double length,radius,width,area;
	double calculateArea(){
		return area;
	}
}

class Rectangle extends Shape {
	// write your code here
	void displayDetails(){
		double rectangleArea = calculateArea();
		System.out.println("Shape details:");
		System.out.println("Area: "+rectangleArea);
	}
    @Override
    double calculateArea() {

    	// write your code here
    	area= length * width;
    	return area;
    }

    void inputDetails(Scanner scanner) {
        System.out.print("Enter the length of the rectangle: ");
        length = scanner.nextDouble();
        System.out.print("Enter the width of the rectangle: ");
        width = scanner.nextDouble();
    }
}

class Circle extends Shape {
	// write your code here
	void displayDetails(){
		double circleArea=calculateArea();
		System.out.println("Shape details:");
		System.out.println("Area: "+circleArea);
	}
    @Override
    double calculateArea() {

    	// write your code here
    	area= Math.PI * radius * radius;
		return area;
    }

    void inputDetails(Scanner scanner) {
        System.out.print("Enter the radius of the circle: ");
        radius = scanner.nextDouble();
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Rectangle rectangle = new Rectangle();
        rectangle.inputDetails(scanner);
        rectangle.displayDetails();
        Circle circle = new Circle();
        circle.inputDetails(scanner);
        circle.displayDetails();
        scanner.close();
    }
}