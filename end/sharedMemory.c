#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>   // For shared memory functions
#include <unistd.h>    // For fork(), wait(), and sleep()
#include <string.h>    // For string functions like strcpy()

#define SHM_SIZE 1024  // Define the size of the shared memory (1 KB in this case)

int main() {
    printf("--------------------------------------------------------------------\n");
    printf("Name: Sarthak\tSection: A2\tRoll No: 58\n");
    printf("--------------------------------------------------------------------\n");

    int shmid;
    char *shm;
    pid_t pid;

    // Step 1: Create a shared memory segment with a specified size.
    // `IPC_PRIVATE` means the shared memory segment is private to this process.
    // `0666` gives read/write permission to all users.
    shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("Shared memory allocation failed"); // Error if shared memory creation fails
        return 1;
    }

    // Step 2: Attach the shared memory segment to this process's address space.
    // `NULL` lets the system choose the address where the shared memory will be mapped.
    // If `shmat()` fails, it will return `(char *)-1`, so we check for that error.
    shm = shmat(shmid, NULL, 0);  // NULL lets the system pick the address
    // `shmat()` returns `(char *)-1` on failure, and we need to compare it to this value.
    // The return value is a pointer, but if there's an error, it will return -1 (as an integer).
    // We need to typecast `-1` to `(char *)` to match the type of `shm` (a pointer to char).
    if (shm == (char *)-1) {
        perror("Shared memory attach failed"); // Error if attaching shared memory fails
        return 1;
    }

    // Step 3: Create a child process using `fork()`
    pid = fork();  // Fork creates a child process

    // Step 4: Parent process behavior (pid > 0)
    if (pid > 0) {
        const char *msg = "Hello from parent!";
        // Write the message to the shared memory segment using strcpy
        // `strcpy()` copies the string to the memory segment, `shm`
        strcpy(shm, msg);

        // The parent waits for the child process to finish before continuing.
        // `wait(NULL)` ensures the child has completed its work before the parent proceeds.
        wait(NULL);  // Wait for the child process to finish
    } else {
        // Step 5: Child process behavior (pid == 0)
        // Sleep for a moment to ensure the parent has time to write to shared memory
        // This avoids the child reading from memory before the parent writes to it.
        sleep(1);  // Give the parent time to write to shared memory

        // Read the message from shared memory and print it
        // The child can access the shared memory and display the message
        printf("Child received message: %s\n", shm);

        // Detach the shared memory from the child process's address space after usage.
        // `shmdt()` detaches the shared memory segment from the process.
        shmdt(shm);  // Detach shared memory

        // Step 6: Clean up the shared memory segment by marking it for removal
        // `shmctl()` with `IPC_RMID` tells the system to remove the shared memory.
        // The shared memory is removed when no process is using it anymore.
        shmctl(shmid, IPC_RMID, NULL);  // Mark shared memory for removal
    }

    return 0;
}
