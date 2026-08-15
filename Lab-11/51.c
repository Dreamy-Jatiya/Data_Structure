/*51. Write a menu driven program to implement following operations on the circular 
      linked list. 
      - Insert a node at the front of the linked list. 
      - Delete a node from specified position. 
      - Insert a node at the end of the linked list. 
      - Display all nodes.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

// Insert at front
void insertFront(struct Node **first, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->info = value;

    if (*first == NULL)
    {
        newNode->link = newNode;
        *first = newNode;
    }
    else
    {
        struct Node *temp = *first;

        while (temp->link != *first)
        {
            temp = temp->link;
        }

        newNode->link = *first;
        temp->link = newNode;
        *first = newNode;
    }

    printf("Node inserted at front\n");
}

// Insert at end
void insertEnd(struct Node **first, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->info = value;

    if (*first == NULL)
    {
        newNode->link = newNode;
        *first = newNode;
    }
    else
    {
        struct Node *temp = *first;

        while (temp->link != *first)
        {
            temp = temp->link;
        }

        temp->link = newNode;
        newNode->link = *first;
    }

    printf("Node inserted at end\n");
}

// Delete from position
void deletePosition(struct Node **first, int pos)
{
    if (*first == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = *first;

    // Delete first node
    if (pos == 1)
    {
        if (temp->link == *first)
        {
            free(temp);
            *first = NULL;
        }
        else
        {
            struct Node *last = *first;

            while (last->link != *first)
            {
                last = last->link;
            }

            *first = temp->link;
            last->link = *first;

            free(temp);
        }

        printf("Node deleted\n");
        return;
    }

    struct Node *prev = NULL;
    int count = 1;

    while (count < pos && temp->link != *first)
    {
        prev = temp;
        temp = temp->link;
        count++;
    }

    if (count != pos)
    {
        printf("Invalid position\n");
        return;
    }

    prev->link = temp->link;
    free(temp);

    printf("Node deleted\n");
}

// Display
void display(struct Node *first)
{
    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = first;

    printf("Circular Linked List: ");

    do
    {
        printf("%d -> ", temp->info);
        temp = temp->link;
    }
    while (temp != first);

    printf("(Back to First)\n");
}

void main()
{
    struct Node *first = NULL;
    int choice, value, pos;

    while (1)
    {
        printf("\n1. Insert at Front\n2. Delete from Position\n3. Insert at End\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insertFront(&first, value);
            break;

        case 2:
            printf("Enter position: ");
            scanf("%d", &pos);
            deletePosition(&first, pos);
            break;

        case 3:
            printf("Enter value: ");
            scanf("%d", &value);
            insertEnd(&first, value);
            break;

        case 4:
            display(first);
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }
}