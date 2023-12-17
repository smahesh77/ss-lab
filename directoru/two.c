#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to represent a directory
struct Directory
{
    char name[20];
    char files[10][20];
    int fileCount;
};

int main()
{
    int choice, i;
    char filename[30], dirname[30];
    struct Directory dir[10];
    int dirCount = 0;

    while (1)
    {
        // Display menu options
        printf("\nOptions:\n");
        printf("1. Create Directory\n");
        printf("2. Create File\n");
        printf("3. Delete File\n");
        printf("4. Search File\n");
        printf("5. Display Directories and Files\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // Create Directory
            printf("Enter the name of the directory: ");
            scanf("%s", dir[dirCount].name);
            dir[dirCount].fileCount = 0;
            printf("Directory `%s` has been created.\n", dir[dirCount].name);
            dirCount++;
            break;

        case 2:
            // Create File in a Directory
            printf("Enter the name of the directory: ");
            scanf("%s", dirname);
            for (i = 0; i < dirCount; i++)
            {
                if (strcmp(dirname, dir[i].name) == 0)
                {
                    printf("Enter the name of the file: ");
                    scanf("%s", dir[i].files[dir[i].fileCount]);
                    printf("File `%s` has been created in directory `%s`.\n", dir[i].files[dir[i].fileCount], dir[i].name);
                    dir[i].fileCount++;
                    break;
                }
            }
            if (i == dirCount)
                printf("Directory `%s` not found.\n", dirname);
            break;

        case 3:
            // Delete File from a Directory
            printf("Enter the name of the directory: ");
            scanf("%s", dirname);
            for (i = 0; i < dirCount; i++)
            {
                if (strcmp(dirname, dir[i].name) == 0)
                {
                    printf("Enter the name of the file to delete: ");
                    scanf("%s", filename);
                    int fileFound = 0;
                    for (int k = 0; k < dir[i].fileCount; k++)
                    {
                        if (strcmp(filename, dir[i].files[k]) == 0)
                        {
                            printf("File `%s` has been deleted from directory `%s`.\n", filename, dir[i].name);
                            dir[i].fileCount--;
                            strcpy(dir[i].files[k], dir[i].files[dir[i].fileCount]);
                            fileFound = 1;
                            break;
                        }
                    }
                    if (!fileFound)
                        printf("File `%s` not found in directory `%s`.\n", filename, dir[i].name);
                    break;
                }
            }
            if (i == dirCount)
                printf("Directory `%s` not found.\n", dirname);
            break;

        case 4:
            // Search for a File in a Directory
            printf("Enter the name of the directory: ");
            scanf("%s", dirname);
            for (i = 0; i < dirCount; i++)
            {
                if (strcmp(dirname, dir[i].name) == 0)
                {
                    printf("Enter the name of the file to search for: ");
                    scanf("%s", filename);
                    int fileFound = 0;
                    for (int k = 0; k < dir[i].fileCount; k++)
                    {
                        if (strcmp(filename, dir[i].files[k]) == 0)
                        {
                            printf("File `%s` is present in directory `%s`.\n", filename, dir[i].name);
                            fileFound = 1;
                            break;
                        }
                    }
                    if (!fileFound)
                        printf("File `%s` not found in directory `%s`.\n", filename, dir[i].name);
                    break;
                }
            }
            if (i == dirCount)
                printf("Directory `%s` not found.\n", dirname);
            break;

        case 5:
            // Display Directories and Files
            if (dirCount == 0)
                printf("\nNo directories created yet.\n");
            else
            {
                printf("\nDirectory\tFiles");
                for (i = 0; i < dirCount; i++)
                {
                    printf("\n%s\t\t", dir[i].name);
                    for (int k = 0; k < dir[i].fileCount; k++)
                        printf("%s\t", dir[i].files[k]);
                    printf("\n");
                }  	
            }
            break;

        case 6:
            // Exit
            printf("Exiting the program...\n");
            exit(0);
            break;

        default:
            printf("Invalid choice. Please enter a valid option (1-6).\n");
        }
    }

    return 0;
}
