#include <stdio.h>
#define SIZE 5
int main() {
        float myFloat;
        char myChar;
        char myChar2;
        int myInt;

//printf("Enter an int value :");
//scanf("%d", &myInt);
//printf("The value user entered is %d\n", myInt);

//printf("Enter an float value :");
//scanf("%f", &myFloat);
//printf("The value user entered is %.2f\n", myFloat);
printf("Enter char int char float:");
scanf("%d %f %c", &myInt, &myFloat);
printf("You entered: %d, %.2f, and %c\n", myInt, myFloat);


    system("PAUSE");
    return 0;
}
