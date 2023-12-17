#include <stdio.h>
#include <stdlib.h>
int main() {
    int numTracks, headPosition;

    // Input the number of tracks
    printf("ENTER THE NUMBER OF TRACKS: ");
    scanf("%d", &numTracks);

    // Input the head pointer position
    printf("ENTER THE HEAD POINTER POSITION: ");
    scanf("%d", &headPosition);

    // Array to store the tracks
    int tracks[100];

    // Input the tracks to be traversed
    printf("ENTER THE TRACKS TO BE TRAVERSED: ");
    for (int i = 0; i < numTracks; i++) {
        scanf("%d", &tracks[i]);
    }

    // Perform C-SCAN
    int totalHeadMovements = 0;

    // Add boundary tracks for sorting
    tracks[numTracks++] = headPosition;
    tracks[numTracks++] = 0;
    tracks[numTracks++] = 199;

    // Sort the tracks
    for (int i = 0; i < numTracks; i++) {
        for (int j = 0; j < numTracks - i - 1; j++) {
            if (tracks[j] > tracks[j + 1]) {
                int temp = tracks[j];
                tracks[j] = tracks[j + 1];
                tracks[j + 1] = temp;
            }
        }
    }

    // Find the index of head position
    int headIndex;
    for (headIndex = 0; headIndex < numTracks; headIndex++) {
        if (tracks[headIndex] == headPosition) {
            break;
        }
    }

    // Traverse the tracks based on head position (C-SCAN)
    int traversedOrder[100];
    int traversedIndex = 0;

    // Traverse to the right
    for (int i = headIndex; i < numTracks; i++, traversedIndex++) {
        traversedOrder[traversedIndex] = tracks[i];
    }

    // Traverse to the left (wrap around to the beginning)
    for (int i = 0; i < headIndex; i++, traversedIndex++) {
        traversedOrder[traversedIndex] = tracks[i];
    }

    // Display the traversed order
    printf("TRAVERSED ORDER: ");
    for (int i = 0; i < traversedIndex; i++) {
        printf("%d => ", traversedOrder[i]);
    }

    // Calculate total head movements
    for (int j = 0; j < traversedIndex - 1; j++) {
        
        totalHeadMovements += abs(traversedOrder[j] - traversedOrder[j + 1]);
    }

    totalHeadMovements -= 199;

    // Display total head movements
    printf("\b\b\b.  \nTOTAL HEAD MOVEMENTS: %d\n", totalHeadMovements);

    return 0;
}
