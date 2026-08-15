/*54. Write a menu driven program to implement following operations on the doubly 
      linked list. 
      - Insert a node at the front of the linked list. 
      - Delete a node from specified position. 
      - Insert a node at the end of the linked list.
      - Display all nodes. 
*/

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

void deleteNode(struct Node **first , int position){
    struct Node *temp = *first;
    int count = 1;
    if(*first == NULL){
        printf("List is empty\n");
        return;
    }
    if(position == 1){
        *first = temp->right;
        if(*first != NULL){
            (*first)->left = NULL;
        }
        free(temp);
        return;
    }
    while(temp != NULL && count < position){
        temp = temp->right;
        count++;
    }
    if(temp == NULL){
        printf("Position out of bounds\n");
        return;
    }
    temp->left->right = temp->right;
    if(temp->right != NULL){
        temp->right->left = temp->left;
    }
    free(temp);
    printf("Node deleted successfully\n");
}

void display(struct Node *first){
    struct Node *temp = first;
    while(temp != NULL){
        printf("%d ", temp->info);
        temp = temp->right;
    }
    printf("\n");
}

void main(){
    int choice , data , position;
    struct Node *first = NULL;
    
    while(1){
        printf("1. Insert at front\n2. Insert at end\n3. Delete node\n4. Display\n5. Exit\n");
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
                printf("Enter position to delete: ");
                scanf("%d" , &position);
                deleteNode(&first , position);
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