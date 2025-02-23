#include <stdio.h>
main()
{  char s[81];
printf("Enter string: ");
scanf("%s", s);
printf("length = %d\n", len(s));
}
int len(char s[])
{  if(*s)
        return 1+len(++s);
return 0;
}
