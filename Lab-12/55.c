//55. WAP to delete alternate nodes of a doubly linked list.

#include <stdio.h>
#include <stdlib.h>
struct Node{
    int info;
    struct Node *right;
    struct Node *left;
};

void insert_front(struct Node **first,int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->info = data;
    newNode->left = NULL;
    newNode->right = *first;

    if(*first != NULL){
        (*first)->left = newNode;
    }
    *first = newNode;
}

void insert_end(struct Node **first,int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->info = data;
    newNode->right = NULL;

    if(*first == NULL){
        newNode->left = NULL;
        *first = newNode;
        return;
    }

    struct Node *temp = *first;
    while(temp->right != NULL){
        temp = temp->right;
    }
    temp->right = newNode;
    newNode->left = temp;
}

void display(struct Node *first){
    struct Node *temp = first;
    while(temp != NULL){
        printf("%d ", temp->info);
        temp = temp->right;
    }
    printf("\n");
}

void deleteAlternate(struct Node **first){
    if(*first == NULL){
        printf("List is empty\n");
        return;
    }
    struct Node *temp = *first;
    while(temp != NULL && temp->right != NULL){
        struct Node *toDelete = temp->right;
        temp->right = toDelete->right;
        if(toDelete->right != NULL){
            toDelete->right->left = temp;
        }
        free(toDelete);
        temp = temp->right;
    }

    display(*first);
}

void main(){
    int choice , data , position;
    struct Node *first = NULL;
    
    while(1){
        printf("1. Insert at front\n2. Insert at end\n3. Delete alternate node\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d" , &choice);

        switch(choice){
            case 1:
                printf("Enter data: ");
                scanf("%d" , &data);
                insert_front(&first , data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d" , &data);
                insert_end(&first , data);
                break;
            case 3:
                deleteAlternate(&first);
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