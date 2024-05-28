#include<stdio.h>  // Include standard input/output library
#include<unistd.h> // Include POSIX operating system API
#include<string.h> // Include string handling library
#include<fcntl.h>  // Include file control library

int main( )
{
    int fd[2];  // File descriptors for the two files
    char buf1[25]= "just a test\n";  // Buffer to hold initial string
    char buf2[50];  // Buffer to hold read string

    fd[0]=open("file1",O_RDWR);  // Open file1 in read/write mode
    fd[1]=open("file2",O_RDWR);  // Open file2 in read/write mode

    write(fd[0], buf1, strlen(buf1));  // Write initial string to file1

    printf("Enter the text: ");  // Prompt user for input
    scanf("\n %s",buf1);  // Read user input into buf1

    printf("Cat file1 is %s",buf1);  // Print the content of buf1

    write(fd[0], buf1, strlen(buf1));  // Write user input to file1

    lseek(fd[0], SEEK_SET, 0);  // Reset the file pointer to the start of file1

    read(fd[0], buf2, sizeof(buf1));  // Read from file1 into buf2
    // Note: The read operation here will read the number of bytes equivalent to the size of buf1, not the actual size of the content written to file1.

	write(fd[1], buf2, sizeof(buf2));// Write the content of buf2 to file2
	close(fd[0]);// Close file1
	close(fd[1]);// Close file2
	printf("\n");
	return 0;
}