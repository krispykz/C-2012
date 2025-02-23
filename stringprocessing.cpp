#include <stdio.h>    
#include <string.h>   

int main()
{
    char myString1[254];
    char myString2[254];
    char myString3[508]; 
    

    printf( "Enter string 1: " );
    fgets( myString1, 254, stdin );

    printf( "This is a string\n", strlen ( myString1 ) );
    printf( "Enter string 2: " );
    fgets( myString2, 254, stdin );
    printf("This is also a string\n");
    
    printf("String 1 is %d bytes long , and string 2 is %d bytes long\n", strlen(myString1), strlen(myString2)); 
    
    
    
    myString3[508] = '\0';           
    
    strcat( myString3, myString1 );     
    strcat( myString3, myString2 ); 
    printf( "String 3 is: %s",myString3);

    getchar();

    return 0;
}
