#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

 char x, y, z;

 int a = 0, b = 0,c = 0, d = 0;

char Category1[] = "<>";
char Category2[] = "+-*%/";
char Category3[] = "|&";

char resultAns[10];
int whichCategory = 0; 

int result1 = 0, result2 = 0, result3 = 0;

printf("Enter an expression: ");
scanf("(%d %c %d) %c (%d %c %d)", &a, &x, &b, &y, &c, &z, &d);

if ((strchr(Category1, x) != NULL) && \
    (strchr(Category1, y) != NULL) && \
    (strchr(Category1, z) != NULL)) {
        whichCategory = 1;
        puts("\nValid input. These are all relational  operators...");
}
else if ((strchr(Category2, x) != NULL) && \
         (strchr(Category2, y) != NULL) && \
         (strchr(Category2, z) != NULL)) {
             whichCategory = 2;
             puts("\nValid input. These are all arithmetic operators...");
}
else if ((strchr(Category3, x) != NULL) && \
         (strchr(Category3, y) != NULL) && \
         (strchr(Category3, z) != NULL)) {
             whichCategory = 3;
             puts("\nValid input. These are all logical operators...");
}

if(whichCategory == 0)  
{
    printf("Result: (%d %c %d) %c (%d %c %d) is not a valid expression for this program\n", a, x, b, y, c, z, d);
    return; 
}

switch(x) 
{
case '<':
     result1 = a < b;
     break;
case '>':
     result1 = a > b;
     break;
case '+':
     result1 = a + b;
     break;
case '-':
     result1 = a - b;
     break;
case '*':
     result1 = a * b;
     break;
case '%':
     result1 = a % b;
     break;
case '/':
     result1 = a / b;
     break;
case '|':
     result1 = a || b;
     break;
case '&':
     result1 = a && b;
}
switch(z)
{
case '<':
     result2 = c < d;
     break;
case '>':
     result2 = c > d;
     break;
case '+':
     result2 = c + d;
     break;
case '-':
     result2 = c - d;
     break;
case '*':
     result2 = c * d;
     break;
case '%':
     result2 = c % d;
     break;
case '/':
     result2 = c / d;
     break;
case '|':
     result2 = c || d;
     break;
case '&':
     result2 = c && d;
}
switch(y)
{
case '<':
     result3 = result1 < result2;
     break;
case '>':
     result3 = result1 > result2;
     break;
case '+':
     result3 = result1 + result2;
     break;
case '-':
     result3 = result1 - result2;
     break;
case '*':
     result3 = result1 * result2;
     break;
case '%':
     result3 = result1 % result2;
     break;
case '/':
     result3 = result1 / result2;
     break;
case '|':
     result3 = result1 || result2;
     break;
case '&':
     result3 = result1 && result2;
}



if(whichCategory == 2)  
{
    printf("Result: (%d %c %d) %c (%d %c %d) = %d\n", a, x, b, y, c, z, d, result3);
}
else
if(whichCategory == 1 || whichCategory == 3)  
{
    if(result3 != 0)
    {
    resultAns[0] = 't';
    resultAns[1] = 'r';
    resultAns[2] = 'u';
    resultAns[3] = 'e';
    resultAns[4] = '\0';
    }
        
    else
    {
    resultAns[0] = 'f';
    resultAns[1] = 'a';
    resultAns[2] = 'l';
    resultAns[3] = 's';
    resultAns[4] = 'e';
    resultAns[5] = '\0';
    
    }
    printf("Result: (%d %c %d) %c (%d %c %d) = %s\n", a, x, b, y, c, z, d);
}

    system("pause");
    return 0;  
}
