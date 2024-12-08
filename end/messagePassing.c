#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MSG_KEY 1234  // Unique key for the message queue

// Define the message structure
// `msg_type` must be `long` as required by the message queue system
struct message {
    long msg_type;       // Message type to categorize messages
    char msg_text[100];  // Text of the message
};

int main() {
    printf("--------------------------------------------------------------------\n");
    printf("Name: Sarthak\tSection: A2\tRoll No: 58\n");
    printf("--------------------------------------------------------------------\n");

    int msgid;         // Message queue ID
    struct message msg; // Message structure instance
    pid_t pid;         // Process ID for fork

    // Create or connect to a message queue
    msgid = msgget(MSG_KEY, 0666 | IPC_CREAT); // Permissions 0666 allow read/write for everyone
    if (msgid == -1) { // Check for errors during queue creation
        perror("Message queue creation failed");
        return 1; // Exit the program if queue creation fails
    }

    // Create a child process
    pid = fork();

    if (pid > 0) { // Parent process
        msg.msg_type = 1; // Set message type to 1
        strcpy(msg.msg_text, "Hello from parent!"); // Copy the message text into msg_text
        msgsnd(msgid, &msg, sizeof(msg.msg_text), 0); // Send the message to the queue
        // Fourth parameter (0) means default blocking behavior if the queue is full
    } else if (pid == 0) { // Child process
        msgrcv(msgid, &msg, sizeof(msg.msg_text), 1, 0); 
        // Receive a message of type 1 from the queue
        // Fourth parameter (1) specifies the type to match
        // Fifth parameter (0) means default blocking behavior if no message is available
        
        printf("Child received message: %s\n", msg.msg_text); // Print the received message

        // Remove the message queue after receiving the message
        msgctl(msgid, IPC_RMID, NULL); 
        // IPC_RMID removes the queue
        // NULL means no additional structure information is required for this operation
    } else { // Fork error
        perror("Fork failed");
        return 1; // Exit if fork fails
    }

    return 0; // Exit the program
}
