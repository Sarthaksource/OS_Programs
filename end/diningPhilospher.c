#include <stdio.h>

int p[5];  // Array to keep track of philosophers' states (0 for thinking, 1 for eating)
int ch[5];  // Array to keep track of chopsticks' availability (0 for available, 1 for in use)

// Function to release chopsticks after eating
void signal(int y) {
    int j = (y + 1) % 5;  // Calculate the index of the right chopstick
    p[y] = 0;  // Set philosopher y as thinking (0)
    ch[y] = 0;  // Set left chopstick of philosopher y as available (0)
    ch[j] = 0;  // Set right chopstick of philosopher y as available (0)
}

// Function to acquire chopsticks before eating
void wait(int y) {
    int right = (y + 1) % 5;  // Calculate the index of the right chopstick

    // If both left and right chopsticks are available
    if ((ch[y] == 0) && (ch[right] == 0)) {
        p[y] = 1;  // Philosopher y starts eating
        ch[y] = 1;  // Left chopstick of philosopher y is now in use
        ch[right] = 1;  // Right chopstick of philosopher y is now in use
    }
    // If philosopher y is already eating, ask if they want to stop
    else if (p[y] == 1) {
        int w;
        printf("Do you want philosopher %d to stop eating? (1 for yes): ", y);
        scanf("%d", &w);
        if (w == 1) {
            signal(y);  // Stop philosopher y from eating and release chopsticks
        }
    }
    // If chopsticks are not available, philosopher y has to wait
    else {
        printf("Chopsticks %d and %d are busy\n", y, right);  // Indicate which chopsticks are in use
        printf("Philosopher %d has to wait\n", y);  // Inform philosopher y that they need to wait
    }
}

int main() {
    printf("--------------------------------------------------------------------\n");
    printf("Name: Sarthak\tSection: A2\tRoll No: 58\n");
    printf("--------------------------------------------------------------------\n");

    int u;  // Variable to check if the program should continue
    // Initialize philosophers' states (all thinking) and chopsticks (all available)
    for (int i = 0; i < 5; i++) {
        p[i] = 0;  // All philosophers start thinking
        ch[i] = 0;  // All chopsticks are initially available
    }

    // Main loop to run the simulation until the user chooses to exit
    do {
        // Display the current state of all philosophers
        for (int i = 0; i < 5; i++) {
            if (p[i] == 0) {
                printf("Philosopher %d is Thinking\n", i);  // Philosopher is thinking
            } else {
                printf("Philosopher %d is Eating\n", i);  // Philosopher is eating
            }
        }

        int s;  // Variable to store which philosopher wants to eat
        printf("Which philosopher wants to eat (0-4)? ");
        scanf("%d", &s);  // Take input for the philosopher that wants to eat
        wait(s);  // Try to acquire chopsticks for the selected philosopher

        // Ask the user if they want to continue or stop the simulation
        printf("\nPress 1 to continue: ");
        scanf("%d", &u);  // If u == 1, continue, otherwise exit
    } while (u == 1);  // Keep running the simulation until the user decides to exit

    return 0;  // End of the program
}
