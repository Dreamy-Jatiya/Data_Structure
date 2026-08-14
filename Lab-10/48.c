//48. WAP to swap Kth node from beginning with Kth node from end in a singly linked list.

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

int count(struct Node *first)
{
    int count = 0;
    struct Node *temp = first;

    while (temp != NULL)
    {
        count++;
        temp = temp->link;
    }

    return count;
}

void swap(struct Node **first , int k){
    if(*first == NULL){
        printf("List is empty\n");
        return;
    }
    struct Node *temp1 = *first;
    struct Node *temp2 = *first;
    int n = count(*first);
    if(k > n || k <= 0){
        printf("Invalid value of k\n");
        return;
    }
    for(int i = 1 ; i < k ; i++){
        temp1 = temp1->link;
    }
    for(int i = 1 ; i < n-k+1 ; i++){
        temp2 = temp2->link;
    }
    int temp = temp1->info;
    temp1->info = temp2->info;
    temp2->info = temp;

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
            int k ;
            printf("Enter the value of k from beginning to swap : ");
            scanf("%d", &k);
            swap(&first , k);
            break;
        case 4:
            display(first);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice \n");
        }
    }
}