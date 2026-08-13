//6. WAP to convert seconds into hours, minutes & seconds and print in HH:MM:SS 
//   [e.g. 10000 seconds mean 2:46:40 (2 Hours, 46 Minutes, 40 Seconds)]. 

#include<stdio.h>
void main(){
    int total_seconds, hours, minutes, seconds;
    printf("Enter total seconds: ");
    scanf("%d", &total_seconds);

    hours = total_seconds / 3600;
    minutes = (total_seconds % 3600) / 60;
    seconds = total_seconds % 60;

    printf("Time in HH:MM:SS format is: %02d:%02d:%02d\n", hours, minutes, seconds);
}