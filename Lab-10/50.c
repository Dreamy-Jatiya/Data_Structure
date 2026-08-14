//50. Write a program to swap two consecutive nodes in the linked list. Don’t change 
//    the values of nodes, implement by changing the link of the nodes. 
//     Input: 1 → 2 → 3 → 4 → 5 → 6 → 7 → 8 
//     Output: 2 → 1 → 4 → 3 → 6 → 5 → 8 → 7

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int info;
    struct Node *link;
};

void insert(struct Node **first , int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
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

void swap(struct Node **first)
{
    if (*first == NULL || (*first)->link == NULL)
    {
        printf("List is empty or has only one node\n");
        return;
    }

    struct Node *prev = NULL;
    struct Node *curr = *first;

    *first = curr->link;   // second node becomes first

    while (curr != NULL && curr->link != NULL)
    {
        struct Node *next = curr->link;

        curr->link = next->link;
        next->link = curr;

        if (prev != NULL)
        {
            prev->link = next;
        }

        prev = curr;
        curr = curr->link;
    }

    printf("Nodes swapped\n");
}

void main()
{
    int choice;
    struct Node *first = NULL;
    int data;

    while (1)
    {
        printf("1. Insert \n2.delete \n3.swap \n4.display \n5.exit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data to be inserted : ");
            scanf("%d", &data);
            insert(&first, data);
            break;
        case 2:
            printf("Enter the data to be deleted : ");
            scanf("%d", &data);
            deleteNode(&first, data);
            break;
        case 3:
            swap(&first);
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