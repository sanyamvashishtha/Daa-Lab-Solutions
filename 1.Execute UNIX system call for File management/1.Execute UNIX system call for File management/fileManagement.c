#include <fcntl.h> // for open
#include <unistd.h> // for close
#include <stdio.h> // for printf and scanf and fgets

int main() {
    char buffer[256];
    int fileDescriptor;

    // Open a file
    fileDescriptor = open("example.txt", O_CREAT | O_RDWR, 0777);
    // Write to the file
    printf("Enter text to write in the file:\n");
    //scanf("%[^\n]%*c", buffer); 
    // Read input from the user until a newline is encounterd using scanf
    //or
    fgets(buffer, sizeof(buffer), stdin);
     // Read input from the user until a newline is encounterd using fgets
    write(fileDescriptor, buffer, sizeof(buffer));

    // Reset the file pointer to the start of the file
    lseek(fileDescriptor, 0, SEEK_SET);

    // Read from the file
    read(fileDescriptor, buffer, sizeof(buffer));
    printf("%s\n", buffer);

    // Close the file
    close(fileDescriptor);

    return 0;
}