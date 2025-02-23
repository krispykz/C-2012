#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxLength 5

int main()
{
char myString1[254] = "This is a string";
char myString2[254] = "This is also a string"; 

int lengthOfmyString1;
printf("Enter string 1:");
gets(myString1);
fgets(myString1, 254, stdin);
lengthOfmyString1 = strlen(myString1);
myString1[lengthOfmyString1 - 1] = '\0';

strcat(myString1);

printf("myString2[%s] is \n ", myString1);
printf("myString2[%s] is \n ", myString1 + 3);

system("pause");
}
