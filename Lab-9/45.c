//45. Write a program to copy a linked list.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

void insert(struct Node **first, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->info = data;
    newNode->link = NULL;

    if (*first == NULL)
    {
        *first = newNode;
    }
    else
    {
        struct Node *temp = *first;

        while (temp->link != NULL)
        {
            temp = temp->link;
        }

        temp->link = newNode;
    }
}

void deleteNode(struct Node **first, int data)
{
    struct Node *temp = *first;
    struct Node *prev = NULL;

    while (temp != NULL)
    {
        if (temp->info == data)
        {
            if (prev == NULL)
            {
                *first = temp->link;
            }
            else
            {
                prev->link = temp->link;
            }

            free(temp);
            printf("Node deleted\n");
            return;
        }

        prev = temp;
        temp = temp->link;
    }

    printf("Data not found\n");
}

void display(struct Node *first)
{
    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = first;

    while (temp != NULL)
    {
        printf("%d -> ", temp->info);
        temp = temp->link;
    }

    printf("NULL\n");
}

void copy_list(struct Node *first, struct Node **second)
{
    struct Node *current = first;

    *second = NULL;

    while (current != NULL)
    {
        insert(second, current->info);
        current = current->link;
    }

    printf("List copied successfully\n");
}

void main()
{
    int choice, data;
    struct Node *first = NULL;
    struct Node *second = NULL;

    while (1)
    {
        printf("\n1.Insert\n2.Delete\n3.Copy List\n4.Display List 1\n5.Display List 2\n6.Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            insert(&first, data);
            break;

        case 2:
            printf("Enter data to delete: ");
            scanf("%d", &data);
            deleteNode(&first, data);
            break;

        case 3:
            copy_list(first, &second);
            break;

        case 4:
            display(first);
            break;

        case 5:
            display(second);
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }
}