import java.util.Scanner;
import currency.CurrencyConverter;
import distance.DistanceConverter;
import time.TimeConverter;

public class ConverterApp {
	public static void main(String[] args){
		int amount,choice,distance,time;
		Scanner scanner = new Scanner(System.in);
		System.out.println("Choose the conversion type:");
		System.out.println("1. Currency");
		System.out.println("2. Distance");
		System.out.println("3. Time");
		int input = scanner.nextInt();
		if (input == 1){
			CurrencyConverter object1 = new CurrencyConverter();
			System.out.println("Choose the currency conversion:");
			System.out.println("1. Dollar to INR");
			System.out.println("2. Euro to INR");
			System.out.println("3. Yen to INR");
			System.out.println("4. INR to Dollar");
			System.out.println("5. INR to Euro");
			System.out.println("6. INR to Yen");
			choice = scanner.nextInt();
			switch(choice){
				case 1:
					System.out.println("Enter the amount in Dollar:");
					amount = scanner.nextInt();
					System.out.println("INR: "+object1.DollartoINR(amount));
					break;
				case 2:
					System.out.println("Enter the amount in Euro:");
					amount = scanner.nextInt();
					System.out.println("INR: "+object1.EurotoINR(amount));
					break;
				case 3:
					System.out.println("Enter the amount in Yen:");
					amount = scanner.nextInt();
					System.out.println("INR: "+object1.YentoINR(amount));
					break;
				case 4:
					System.out.println("Enter the amount in INR:");
					amount = scanner.nextInt();
					System.out.println("Dollar: "+object1.INRtoDollar(amount));
					break;
				case 5:
					System.out.println("Enter the amount in INR:");
					amount = scanner.nextInt();
					System.out.println("Euro: "+object1.INRtoEuro(amount));
					break;
				case 6:
					System.out.println("Enter the amount in INR:");
					amount = scanner.nextInt();
					System.out.println("Yen: "+object1.INRtoYen(amount));
					break;
				default:
					System.out.println("Invalid choice");
			}
		}
		else if (input == 2){
			DistanceConverter object2 = new DistanceConverter();
			System.out.println("Choose the distance conversion:");
			System.out.println("1. Meter to KM");
			System.out.println("2. KM to Meter");
			System.out.println("3. Miles to KM");
			System.out.println("4. KM to Miles");
			choice = scanner.nextInt();
			switch(choice){
				case 1:
					System.out.println("Enter the distance in meters:");
					distance = scanner.nextInt();
					System.out.println("KM: "+object2.MetertoKM(distance));
					break;
				case 2:
					System.out.println("Enter the distance in KM:");
					distance = scanner.nextInt();
					System.out.println("Meters: "+object2.KMtoMeter(distance));
					break;
				case 3:
					System.out.println("Enter the distance in miles:");
					distance = scanner.nextInt();
					System.out.println("KM: "+object2.MilestoKM(distance));
					break;
				case 4:
					System.out.println("Enter the distance in KM:");
					distance = scanner.nextInt();
					System.out.println("Miles: "+object2.KMtoMiles(distance));
					break;
				default:
					System.out.println("Invalid choice");
			}
			
			
		}
		else if (input == 3){
			TimeConverter object3 = new TimeConverter();
			System.out.println("Choose the time conversion:");
			System.out.println("1. Hours to Minutes");
			System.out.println("2. Minutes to Hours");
			System.out.println("3. Hours to Seconds");
			System.out.println("4. Seconds to Hours");
			choice = scanner.nextInt();
			switch(choice){
				case 1:
					System.out.println("Enter the time in hours:");
					time=scanner.nextInt();
					System.out.println("Minutes: "+object3.HourstoMinutes(time));
					break;
				case 2:
					System.out.println("Enter the time in minutes:");
					time=scanner.nextInt();
					System.out.println("Hours: "+object3.MinutestoHours(time));
					break;
				case 3:
					System.out.println("Enter the time in hours:");
					time=scanner.nextInt();
					System.out.println("Seconds: "+object3.HourstoSeconds(time));
					break;
				case 4:
					System.out.println("Enter the time in seconds:");
					time=scanner.nextInt();
					System.out.println("Hours: "+object3.SecondstoHours(time));
					break;
				default:
					System.out.println("Invalid choice");
			}
		}
		else {
			System.out.println("Invalid choice");
		}
        scanner.close();
	}


}