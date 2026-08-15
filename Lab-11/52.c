//52. WAP to split a circular linked list into two halves. 

// WAP to split a circular linked list into two halves.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

void insert(struct Node **front, struct Node **rear, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->info = data;

    if (*front == NULL)
    {
        newNode->link = newNode;
        *front = newNode;
        *rear = newNode;
    }
    else
    {
        (*rear)->link = newNode;
        newNode->link = *front;
        *rear = newNode;
    }
}

void deleteNode(struct Node **front, struct Node **rear, int data)
{
    if (*front == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = *front;
    struct Node *prev = *rear;

    do
    {
        if (temp->info == data)
        {
            break;
        }

        prev = temp;
        temp = temp->link;

    } while (temp != *front);

    // Node not found
    if (temp->info != data)
    {
        printf("Node not found\n");
        return;
    }

    // Only one node
    if (*front == *rear && temp == *front)
    {
        *front = NULL;
        *rear = NULL;
    }

    // Delete front node
    else if (temp == *front)
    {
        *front = (*front)->link;
        (*rear)->link = *front;
    }

    // Delete rear node
    else if (temp == *rear)
    {
        prev->link = *front;
        *rear = prev;
    }

    // Delete middle node
    else
    {
        prev->link = temp->link;
    }

    free(temp);

    printf("Node deleted successfully\n");
}

void splitLists(struct Node **front1, struct Node **rear1,struct Node **front2, struct Node **rear2)
{
    if (*front1 == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *slow = *front1;
    struct Node *fast = *front1;

    // Find middle using slow and fast pointer
    while (fast->link != *front1 && fast->link->link != *front1)
    {
        slow = slow->link;
        fast = fast->link->link;
    }
    // For even number of nodes
    if (fast->link->link == *front1)
    {
        fast = fast->link;
    }

    // Second list
    *front2 = slow->link;
    *rear2 = fast;

    // Make second list circular
    (*rear2)->link = *front2;

    // First list
    *rear1 = slow;
    (*rear1)->link = *front1;

    printf("List split successfully\n");
}

void display(struct Node **front)
{
    if (*front == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = *front;

    do
    {
        printf("%d ", temp->info);
        temp = temp->link;

    } while (temp != *front);

    printf("\n");
}

void main()
{
    struct Node *front1 = NULL;
    struct Node *rear1 = NULL;

    struct Node *front2 = NULL;
    struct Node *rear2 = NULL;

    int choice, data;

    while (1)
    {
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Split into 2 lists");
        printf("\n4. Display");
        printf("\n5. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);

            insert(&front1, &rear1, data);
            break;

        case 2:
            printf("Enter data to delete: ");
            scanf("%d", &data);

            deleteNode(&front1, &rear1, data);
            break;

        case 3:
            splitLists(&front1, &rear1, &front2, &rear2);
            break;

        case 4:
            printf("First List: ");
            display(&front1);

            printf("Second List: ");
            display(&front2);
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }
}
