#include <stdio.h>
void main()
{
    int tracks[20], currentPosition, numTracks, i, totalHeadMovements = 0;

    // Input the number of tracks
    printf("ENTER THE NUMBER OF TRACKS: ");
    scanf("%d", &numTracks);

    // Input the initial head pointer position
    printf("ENTER THE HEAD POINTER POSITION: ");
    scanf("%d", &currentPosition);

    // Input the tracks to be traversed
    printf("ENTER THE TRACKS TO BE TRAVERSED: ");
    for (i = 0; i < numTracks; i++)
    {
        scanf("%d", &tracks[i]);

        // Calculate head movement for the current track
        totalHeadMovements += abs(currentPosition - tracks[i]);

        // Update the current position to the new track
        currentPosition = tracks[i];
    }

    // Display the traversed order
    printf("TRAVERSED ORDER: ");
    for (i = 0; i < numTracks; i++)
        printf("%d => ", tracks[i]);

    // Remove the last arrow and display total head movements
    printf("\b\b\b.   \nTOTAL HEAD MOVEMENTS: %d\n", totalHeadMovements);
}
