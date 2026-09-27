/*42. Write a menu driven program to implement following operations on the singly linked list.
        --- Insert a node at the front of the linked list.
        --- Display all nodes.
        --- Delete a first node of the linked list.
        --- Insert a node at the end of the linked list.
        --- Delete a last node of the linked list.
        --- Delete a node from specified position.
        --- Count the no. of nodes in the linked list.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node* link;
};

struct Node* insert_front(struct Node* first, int info)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->info = info;
    newNode->link = first;

    first = newNode;

    return first;
}

struct Node* insert_end(struct Node* first, int info)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->info = info;
    newNode->link = NULL;

    if (first == NULL)
    {
        first = newNode;
    }
    else
    {
        struct Node* temp = first;

        while (temp->link != NULL)
        {
            temp = temp->link;
        }

        temp->link = newNode;
    }

    return first;
}

struct Node* delete_first(struct Node* first)
{
    if (first == NULL)
    {
        printf("Linked list is empty\n");
        return first;
    }

    struct Node* temp = first;

    first = first->link;

    free(temp);

    return first;
}

struct Node* delete_last(struct Node* first)
{
    if (first == NULL)
    {
        printf("Linked list is empty\n");
        return first;
    }

    if (first->link == NULL)
    {
        free(first);
        first = NULL;
        return first;
    }

    struct Node* temp = first;

    while (temp->link->link != NULL)
    {
        temp = temp->link;
    }

    free(temp->link);
    temp->link = NULL;

    return first;
}

struct Node* delete_from_position(struct Node* first, int position)
{
    if (first == NULL)
    {
        printf("Linked list is empty\n");
        return first;
    }

    if (position == 1)
    {
        return delete_first(first);
    }

    if (position <= 0)
    {
        printf("Invalid position\n");
        return first;
    }

    struct Node* temp = first;

    for (int i = 1; temp != NULL && i < position - 1; i++)
    {
        temp = temp->link;
    }

    if (temp == NULL || temp->link == NULL)
    {
        printf("Position out of bounds\n");
        return first;
    }

    struct Node* nodeToDelete = temp->link;

    temp->link = nodeToDelete->link;

    free(nodeToDelete);

    return first;
}

void display_Nodes(struct Node* first)
{
    if (first == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }

    struct Node* temp = first;

    while (temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->link;
    }

    printf("\n");
}

int count_nodes(struct Node* first)
{
    int count = 0;

    struct Node* temp = first;

    while (temp != NULL)
    {
        count++;
        temp = temp->link;
    }

    return count;
}

void main()
{
    struct Node* first = NULL;

    int choice, info, position, count;

    while (1)
    {
        printf("\n1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Delete first\n");
        printf("4. Delete last\n");
        printf("5. Delete from position\n");
        printf("6. Count nodes\n");
        printf("7. Display\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter info: ");
            scanf("%d", &info);

            first = insert_front(first, info);
            break;

        case 2:
            printf("Enter info: ");
            scanf("%d", &info);

            first = insert_end(first, info);
            break;

        case 3:
            first = delete_first(first);
            break;

        case 4:
            first = delete_last(first);
            break;

        case 5:
            printf("Enter position: ");
            scanf("%d", &position);

            first = delete_from_position(first, position);
            break;

        case 6:
            count = count_nodes(first);

            printf("Number of nodes: %d\n", count);
            break;

        case 7:
            display_Nodes(first);
            break;

        case 8:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }
}
