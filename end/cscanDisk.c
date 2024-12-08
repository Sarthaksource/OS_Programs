#include <stdio.h>
#include <stdlib.h>

// Function to sort the array in ascending order using Bubble Sort
void sortArray(int arr[], int size) {
    // Using Bubble Sort to sort the array
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to calculate the total seek movement for C-SCAN
int calculateCScanMovement(int sortedTracks[], int size, int headIndex, int head, int diskSize) {
    int totalMovement = 0;        // Track total movement
    int currentTrack = head;      // Start from the initial head position

    // Move right (towards higher track numbers)
    for (int i = headIndex + 1; i < size; i++) {
        totalMovement += abs(currentTrack - sortedTracks[i]);
        currentTrack = sortedTracks[i];
    }

    // Move to the disk boundary (to the highest track)
    totalMovement += abs(currentTrack - (diskSize - 1));
    currentTrack = diskSize - 1;

    // Move to the lowest track (0) and continue from there
    totalMovement += currentTrack; // Move from current position to 0 (boundary)
    currentTrack = 0;

    // Move left (towards lower track numbers)
    for (int i = 0; i < headIndex; i++) {
        totalMovement += abs(currentTrack - sortedTracks[i]);
        currentTrack = sortedTracks[i];
    }

    return totalMovement;
}

int main() {
    int n, diskSize = 200, head;

    // Step 1: Input the number of disk requests
    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    int tracks[n + 1]; // Allocate space for n disk requests plus the head position

    // Step 2: Input the disk requests
    printf("Enter the disk requests: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &tracks[i]);
    }

    // Step 3: Input the initial head position
    printf("Enter initial head position: ");
    scanf("%d", &head);

    // Step 4: Add the head position to the track array
    tracks[n++] = head; // Add head and increment size to account for it

    // Step 5: Sort the array to simulate C-SCAN traversal
    sortArray(tracks, n);

    // Step 6: Find the index of the head in the sorted array
    int headIndex = 0;
    while (tracks[headIndex] != head) {
        headIndex++;
    }

    // Step 7: Calculate the total seek movement based on C-SCAN algorithm
    int totalMovement = calculateCScanMovement(tracks, n, headIndex, head, diskSize);

    // Step 8: Output the total seek movement
    printf("Total seek movement: %d\n", totalMovement);

    return 0;
}
