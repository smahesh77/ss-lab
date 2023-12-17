#include <stdio.h>
#include <stdlib.h>

#define MAX_TRACKS 100

void main() {
    int tracks[MAX_TRACKS], traversedOrder[MAX_TRACKS];
    int numTracks, headPosition, totalHeadMovements = 0;

    // Input the number of tracks
    printf("ENTER THE NUMBER OF TRACKS: ");
    scanf("%d", &numTracks);

    // Input the head pointer position
    printf("ENTER THE HEAD POINTER POSITION: ");
    scanf("%d", &headPosition);

    // Input the tracks to be traversed
    printf("ENTER THE TRACKS TO BE TRAVERSED: ");
    for (int i = 0; i < numTracks; i++) {
        scanf("%d", &tracks[i]);
    }

    // Add the head position and 0 for sorting
    tracks[numTracks++] = headPosition;
    tracks[numTracks++] = 0;

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

    // Traverse the tracks based on head position
    int traversedIndex = 0;
    for (int i = headIndex; i >= 0; i--) {
        traversedOrder[traversedIndex++] = tracks[i];
    }

    for (int i = headIndex + 1; i < numTracks; i++) {
        traversedOrder[traversedIndex++] = tracks[i];
    }

    // Display the traversed order
    printf("TRAVERSED ORDER: ");
    for (int i = 0; i < traversedIndex; i++) {
        printf("%d => ", traversedOrder[i]);
    }

    // Calculate total head movements
    for (int i = 0; i < traversedIndex - 1; i++) {
        totalHeadMovements += abs(traversedOrder[i] - traversedOrder[i + 1]);
    }

    // Display total head movements
    printf("\b\b\b.  \nTOTAL HEAD MOVEMENTS: %d\n", totalHeadMovements);
}
