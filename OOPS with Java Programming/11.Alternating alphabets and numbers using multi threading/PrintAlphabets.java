import java.util.Scanner;
class AlphabetNumberPrinter extends Thread {
	private static final Object monitor = new Object();
	private static int currentNumber=1;
	private static char currentAlphabet= 'A';
	private int count;
	private boolean isAlphabetThread;

	public AlphabetNumberPrinter(int count , boolean isAlphabetThread){
	this.count = count;
	this.isAlphabetThread = isAlphabetThread;
	}
	@Override
	public void run(){
		synchronized(monitor){
			for(int i= 0; i< count ; i++){
				if(isAlphabetThread){
					System.out.println(Thread.currentThread().getName()+ ": "+currentAlphabet++);
					
				}
				else{
					System.out.println(Thread.currentThread().getName()+ ": "+currentNumber++);
				}
				monitor.notify();//notify waiting thread
				try{
					if(i < count -1){
						monitor.wait();//release monitor and wait
					}
				}
				catch(InterruptedException e){
					e.printStackTrace();
				}
			}
		}
		
	}
}

public class PrintAlphabets{
	public static void main(String[] args){
		int count;
		Scanner scanner = new Scanner(System.in);
		do{
			System.out.println("Enter the number of characters to print:");
			count =scanner.nextInt();
			if(count < 1){
				System.out.println("Please enter a number greater than 0.");
			}
		}while(count<1);
		//Creating and starting Threads
		AlphabetNumberPrinter alphabetThread = new AlphabetNumberPrinter(count,true);
        alphabetThread.setName("Thread-0");
		AlphabetNumberPrinter numberThread = new AlphabetNumberPrinter(count,false);
		numberThread.setName("Thread-1");
		alphabetThread.start();
		numberThread.start();
		scanner.close();
	}
}