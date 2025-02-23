#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    unsigned short int myInt1;
    unsigned short int myInt2;
    float myFloat1;
    
    printf("Enter unsigned short int: ");
    scanf("%u", &myInt1);
    printf("The value of 2 raised to the power of %u is: %.0f\n", myInt1, pow(2,myInt1));

    printf("Enter unsigned short int: ");
    scanf("%u", &myInt2);
    printf("A circle with radius %u has circumference of %.3f and an area of %.3f\n", myInt2, 2 * M_PI * myInt2, M_PI * myInt2 * myInt2);
   

    printf("Enter a float value: ");
    scanf("%f", &myFloat1);
    printf("The value of 2(%.3f)**3 + 3(%.3f)**2 + 4(%.3f) + 5 = ", myFloat1, myFloat1, myFloat1);
    printf("%.3f\n", (2 * pow(myFloat1,3)) + (3 * pow(myFloat1,2)) + (4 * myFloat1) + 5);
    
    //put in two lines to make it easier to read

    system("pause");
}
