//8. WAP to find factorial of a number. (Using recursion)

#include<stdio.h>
int factorial(int n){
    if(n == 0 || n == 1){
        return 1 ;
    }
    return n * factorial(n-1) ;
}

void main(){
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    printf("Factorial of %d is %d\n", number, factorial(number));
}