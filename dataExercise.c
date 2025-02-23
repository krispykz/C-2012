#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
int main() {
    char myWord[50] = "Hello World! I am a string";
    char ch = 'a';
    short int myInt2 = SHRT_MAX;
    double infinity = HUGE_VAL;
    short int* myInt2Ptr = &myInt2;
    
    printf("%s \n", myWord); 
    printf("%c\n", ch);
    printf("%d\n", ch);
    printf("%d\n", myInt2);
    printf("%1f\n", infinity);
    printf("%d\n", myInt2Ptr);
    printf("%d\n", *myInt2Ptr);
    
    system("PAUSE");                             
    return 0;
}
