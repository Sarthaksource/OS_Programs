#include <stdio.h>
#include <stdlib.h>

// Function to sort the array in ascending order
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

// Function to calculate the total seek movement for SCAN
int calculateScanMovement(int sortedTracks[], int size, int headIndex, int head, int diskSize) {
    int totalMovement = 0;        // Tracks total movement
    int currentTrack = head;      // Start from the initial head position

    // Move right (towards higher track numbers)
    for (int i = headIndex + 1; i < size; i++) {
        totalMovement += abs(currentTrack - sortedTracks[i]);
        currentTrack = sortedTracks[i];
    }

    // Move to the highest track (disk boundary)
    totalMovement += abs(currentTrack - (diskSize - 1));
    currentTrack = diskSize - 1;

    // Move left (towards lower track numbers)
    for (int i = headIndex - 1; i >= 0; i--) {
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

    // Step 5: Sort the array to simulate SCAN traversal
    sortArray(tracks, n);

    // Step 6: Find the index of the head in the sorted array
    int headIndex = 0;
    while (tracks[headIndex] != head) {
        headIndex++;
    }

    // Step 7: Calculate the total seek movement based on SCAN algorithm
    int totalMovement = calculateScanMovement(tracks, n, headIndex, head, diskSize);

    // Step 8: Output the total seek movement
    printf("Total seek movement: %d\n", totalMovement);

    return 0;
}
