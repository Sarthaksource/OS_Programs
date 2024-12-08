#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("--------------------------------------------------------------------\n");
    printf("Name: Sarthak\tSection: A2\tRoll No: 58\n");
    printf("--------------------------------------------------------------------\n");
    
    int n, totalSeekMovement = 0;
    printf("Enter number of disk requests: ");
    scanf("%d", &n);
    int tracks[n];
    printf("Enter the disk requests: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &tracks[i]);
    }
    int initialTrack;
    printf("Enter initial head position: ");
    scanf("%d", &initialTrack);
    totalSeekMovement = abs(initialTrack - tracks[0]);
    for (int i = 1; i < n; i++) {
        totalSeekMovement += abs(tracks[i] - tracks[i - 1]);
    }
    printf("Total seek movement: %d\n", totalSeekMovement);
    return 0;
}
