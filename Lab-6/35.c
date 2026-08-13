//35. WAP to get and print the array elements using Pointer.

#include<stdio.h>
#include<stdlib.h>

void insert_array_elements(int *ptr, int n) {
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ptr[i]);
    }
}

void print_array_elements(int *ptr, int n) {
    printf("Array elements are:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");
}

void main(){
    int total_elements;

    printf("Enter the total number of elements: ");
    scanf("%d", &total_elements);

    //int *ptr_array = (int *)malloc(total_elements * sizeof(int));
    int arr[total_elements];
    int *ptr_array = arr;

    int choice ;
    while (1)
    {
        printf("Enter your choice: \n1. insert array elements\n2. Print array elements\n3. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                insert_array_elements(ptr_array, total_elements);
                break;
            case 2:
                print_array_elements(ptr_array, total_elements);
                break;
            case 3:
                free(ptr_array);
                exit(0);
                break;// Not necessary, but added for clarity
            default:
                printf("Invalid choice\n");
        }
    }
    
}