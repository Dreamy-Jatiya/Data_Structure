//7. WAP to convert number of days into year, week & days [e.g. 375 days mean 1 
//   year, 1 week and 3 days]. 

#include<stdio.h>
void main(){
    int totalDays, years, months, days;
    printf("Enter total days: ");
    scanf("%d", &totalDays);
    years = totalDays / 365;
    months = (totalDays % 365) / 30;
    days = totalDays % 30;
    printf("Time in YY:MM:DD format: %02d:%02d:%02d\n", years, months, days);
}