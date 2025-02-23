#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int main(int argc, char *argv[])
{
/* All the variables we're going to use */
char str[80] = "Hello World! I am a string ";
char ch = 'a';
short int si = SHRT_MAX;
double inf;
short int* sip;

/* Print a string constant */
printf("%s\n" , str);

/* Print a character constant */
printf("%c\n" , ch);

/* Print the decimal value of a character constant */
printf("%d\n", (int)ch);

/* Print a maximum value short integer */
printf("%d\n", (int)si);

/* Obtain the value of infinity and print it */
inf = infinity(); /* Calling a function in math.h */
printf("%f\n", inf);

/* Get the address of the short int above and print it */
sip = &si;
printf("%d\n", (int)sip); /* This may generate a compiler truncation warning */

/* Get the value of the short int using the pointer and print it */
printf("%d\n", (int)*sip);

system("PAUSE");
return 0;
}
