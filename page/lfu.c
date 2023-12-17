#include <stdio.h>

#define MAX_FRAMES 100

struct Frame
{
    int content;
    int frequency;
    int referenceCount;
};

void main()
{
    int pageReferences[MAX_FRAMES], numFrames, numPageReferences, pageFaults = 0, frameIndex = 0;
    struct Frame frames[MAX_FRAMES];

    // Input the number of page references
    printf("ENTER THE NUMBER OF PAGE REFERENCES: ");
    scanf("%d", &numPageReferences);

    // Input the page reference string
    printf("ENTER THE PAGE REFERENCE STRING: ");
    for (int i = 0; i < numPageReferences; i++)
    {
        scanf("%d", &pageReferences[i]);
    }

    // Input the number of frames
    printf("ENTER THE NUMBER OF FRAMES: ");
    scanf("%d", &numFrames);

    // Initialize frames
    for (int i = 0; i < numFrames; i++)
    {
        frames[i].content = -1;
        frames[i].frequency = 0;
        frames[i].referenceCount = 0;
    }

    // Display header
    printf("\nPAGE REFERENCE\t\tSTATUS\t\tFRAME CONTENT\n\n");

    // Page replacement algorithm
    for (int i = 0; i < numPageReferences; i++)
    {
        printf("\t%d\t\t", pageReferences[i]);

        // Check if the page is in frames
        int j;
        for (j = 0; j < numFrames; j++)
        {
            if (frames[j].content == pageReferences[i])
            {
                printf("HIT\t\t");
                frames[j].frequency++;
                break;
            }
        }

        // If page is not in frames
        if (j == numFrames)
        {
            printf("MISS\t\t");

            // If there's still space in frames
            if (frameIndex < numFrames)
            {
                frames[frameIndex].content = pageReferences[i];
                frames[frameIndex].frequency++;
                frames[frameIndex].referenceCount = i + 1;
                frameIndex++;
            }
            else
            {
                // Find the frame with the minimum frequency (and minimum count in case of tie)
                int min = 0;
                for (j = 1; j < numFrames; j++)
                {
                    if (frames[min].frequency > frames[j].frequency || (frames[min].frequency == frames[j].frequency && frames[min].referenceCount > frames[j].referenceCount))
                    {
                        min = j;
                    }
                }

                // Replace the frame
                frames[min].content = pageReferences[i];
                frames[min].frequency = 1;
                frames[min].referenceCount = i + 1;
            }
            pageFaults++;
        }

        // Display frame content
        for (j = 0; j < numFrames; j++)
        {
            if (frames[j].content != -1)
                printf("%d\t", frames[j].content);
        }
        printf("\n");
    }

    printf("\nTOTAL PAGE FAULTS: %d\n", pageFaults);
}
