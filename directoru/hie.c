#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CHILDREN 100
#define MAX_NAME_LENGTH 128

struct node
{
    char name[MAX_NAME_LENGTH];
    bool isDir;
    struct node *p;
    struct node *c[MAX_CHILDREN];
    int i;
};

struct node *createNode(const char *name, bool isDir, struct node *parent)
{
    struct node *newNode = malloc(sizeof(struct node));
    if (!newNode) exit(EXIT_FAILURE);

    strcpy(newNode->name, name);
    newNode->isDir = isDir;
    newNode->p = parent;
    newNode->i = 0;

    return newNode;
}

void ls(struct node *current)
{
    printf("%s", current->i ? "" : "\nEmpty directory!");
    for (int i = 0; i < current->i; i++)
        printf("\n%s %s", current->c[i]->isDir ? "*" : "", current->c[i]->name);
}

void touch(bool isDir, struct node *current)
{
    printf("\nEnter Name:");
    char fname[MAX_NAME_LENGTH];
    scanf("%s", fname);

    current->c[current->i++] = createNode(fname, isDir, current);
    printf("\n%s %s created successfully.", isDir ? "Directory" : "File", fname);
}

void cd(struct node **current)
{
    printf("\nEnter Directory Name:");
    char dname[MAX_NAME_LENGTH];
    scanf("%s", dname);

    for (int i = 0; i < (*current)->i; i++)
        if (!strcmp((*current)->c[i]->name, dname) && (*current)->c[i]->isDir)
        {
            *current = (*current)->c[i];
            return;
        }

    printf("\nDirectory Not Found!");
}

void cdup(struct node **current)
{
    if ((*current)->p)
        *current = (*current)->p;
    else
        printf("\nYou are at the Root Directory");
}

void rm(bool isDir, struct node *current)
{
    printf("\nEnter Name of %s to Delete:", isDir ? "Directory" : "File");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);

    for (int i = 0; i < current->i; i++)
        if (!strcmp(current->c[i]->name, name) && (isDir == current->c[i]->isDir))
        {
            free(current->c[i]);
            for (int t = i; t < current->i - 1; t++)
                current->c[t] = current->c[t + 1];

            current->i--;
            printf("\nSuccessfully Deleted.");
            return;
        }

    printf("\nNot found");
}

int main()
{
    int choice;
    struct node *head = createNode("root", true, NULL);
    struct node *current = head;

    while (true)
    {
        printf("\nYou are in %s directory.\n*****************************************\n"
               "1. Show everything in this Directory\n"
               "2. Change Directory\n"
               "3. Go to Parent Directory\n"
               "4. Create New File\n"
               "5. Delete File\n"
               "6. Create New Directory\n"
               "7. Delete Directory\n"
               "8. Exit\n"
               "Enter your choice:", current->name);

        scanf("%d", &choice);

        switch (choice)
        {
        case 1: ls(current); break;
        case 2: cd(&current); break;
        case 3: cdup(&current); break;
        case 4: touch(false, current); break;
        case 5: rm(false, current); break;
        case 6: touch(true, current); break;
        case 7: rm(true, current); break;
        default: exit(EXIT_SUCCESS);
        }
    }

    return 0;
}
