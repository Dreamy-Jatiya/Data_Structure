//2. WAP to find whether a number is odd or even.

#include<stdio.h>
void main(){
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    if(number % 2 == 0){
        printf("%d is an even number.\n", number);
    } else {
        printf("%d is an odd number.\n", number);
    }
}