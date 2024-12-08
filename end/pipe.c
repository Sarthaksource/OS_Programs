#include <stdio.h>
#include <unistd.h>  // For pipe(), fork(), read(), and write()
#include <string.h>  // For strlen()

int main() {
    // Display program details
    printf("--------------------------------------------------------------------\n");
    printf("Name: Sarthak\tSection: A2\tRoll No: 58\n");
    printf("--------------------------------------------------------------------\n");

    int pipe_fd[2];      // Array to store file descriptors for the pipe: [0] = read, [1] = write
    pid_t pid;           // Process ID for fork
    char buffer[100];    // Buffer to hold the message received by the child process

    // Create the pipe
    if (pipe(pipe_fd) == -1) { // If pipe() fails, return an error
        perror("Pipe failed"); // Print error message
        return 1;              // Exit the program
    }

    // Create a child process
    pid = fork();

    if (pid < 0) { // Check for fork failure
        perror("Fork failed"); // Print error message
        return 1;              // Exit the program
    }

    if (pid > 0) { // Parent process
        close(pipe_fd[0]); // Close unused read end of the pipe (parent only writes)

        const char *msg = "Hello from parent!"; // Message to be sent by the parent process

        // Write the message to the pipe
        write(pipe_fd[1], msg, strlen(msg) + 1); 
        // `strlen(msg) + 1` ensures the null terminator (`\0`) is also written

        close(pipe_fd[1]); // Close the write end after sending the message
    } else { // Child process
        close(pipe_fd[1]); // Close unused write end of the pipe (child only reads)

        // Read the message from the pipe into the buffer
        read(pipe_fd[0], buffer, sizeof(buffer)); 
        // Reads up to `sizeof(buffer)` bytes. Here, the buffer size is 100.

        // Print the message received from the parent
        printf("Child received message: %s\n", buffer);

        close(pipe_fd[0]); // Close the read end after reading the message
    }

    return 0; // Exit the program
}
