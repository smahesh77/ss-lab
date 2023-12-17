#include <stdio.h>

struct File
{
    char name[30];
    int start;
    int length;
};

int main()
{
    // Declare an array of File structures to store file information
    struct File files[10];
    int num;

    // Input the number of files to be allocated
    printf("Enter the number of files to be allocated: ");
    scanf("%d", &num);

    // Input file information for each file
    for (int i = 0; i < num; i++)
    {
        printf("Enter the name of the file %d: ", i + 1);
        scanf("%s", files[i].name);
        printf("Enter the start block of the file %d: ", i + 1);
        scanf("%d", &files[i].start);
        printf("Enter the length of the file %d: ", i + 1);
        scanf("%d", &files[i].length);
    }

    // Output the File Allocation Table
    printf("\nFile Allocation Table\n");
    printf("%-30s%-20s%-20s\n", "File Name", "Start Block", "Length");

    for (int i = 0; i < num; i++)
    {
        // Output file information in a formatted manner
        printf("%-30s%-20d%-20d\n", files[i].name, files[i].start, files[i].length);
    }

    return 0;
}
