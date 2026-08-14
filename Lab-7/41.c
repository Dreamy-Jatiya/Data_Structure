//41. Write a program to implement a node structure for singly linked list. Read the 
//    data in a node, print the node.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node* link;
};

void insert_Node(struct Node** first, int info)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->info = info;
    newNode->link = NULL;

    if (*first == NULL)
    {
        *first = newNode;
    }
    else
    {
        struct Node* temp = *first;

        while (temp->link != NULL)
        {
            temp = temp->link;
        }

        temp->link = newNode;
    }
}

void display(struct Node** first)
{
    struct Node* temp = *first;

    if (*first == NULL)
    {
        printf("linked list is empty\n");
        return;
    }

    while (temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->link;
    }

    printf("\n");
}

void main()
{
    struct Node* first = NULL;   // Declare once

    int choice, info;

    while (1)
    {
        printf("\n1. Insert Node\n2. Display\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter info: ");
            scanf("%d", &info);

            insert_Node(&first, info);
            break;

        case 2:
            display(&first);
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }
}