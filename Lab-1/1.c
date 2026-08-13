//1. WAP to calculate area of a Circle (A = πr2).

#include <stdio.h>
void main() {
    float radius, area;
    const float PI = 3.14159;

    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);

    area = PI * radius * radius;

    printf("Area of the circle with radius %.2f is: %.2f\n", radius, area);
}