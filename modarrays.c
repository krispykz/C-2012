//headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

//constants
#define fileNameLength 256

//function prototypes
FILE * getFile(void);
void freqEntOut(FILE * inputFile, unsigned short int cipher);
char myEncrypt(char myChar, unsigned short int shift);

int main()
{
    //Local variables
    FILE * readFile;                                 //Input file stream
    unsigned short int cipher;

    readFile = getFile();    

    freqEntOut( readFile, cipher );

    fclose(readFile);      //Close the input file handle
    
    system("pause");
    return 0;
}

FILE * getFile()
{
     FILE * inputFile;
     char inputFileName[fileNameLength] = {0};            //Empty input file name
     do {
        printf("Enter input file name: ");                //Prompt
        fgets(inputFileName,fileNameLength,stdin);        //Read the file name
        
        inputFileName[strlen(inputFileName) - 1] = '\0';  //Kill the \n
       
        if((inputFile = fopen(inputFileName,"r")) == NULL) {
            fclose(inputFile);
            printf("Unable to open \"%s\": %s\n",
                inputFileName,strerror(errno));
        }

    } while(inputFile == NULL);
    
    return inputFile;
}

void freqEntOut(FILE * inputFile, unsigned short int cipher)
{
    FILE * outputFile;                                 //Output file stream
    char outputFileName[7] = "out.txt";         //Output filename "out.txt"
    char inByte;                                      //Byte from input file
    int freqTable[fileNameLength] = {0};                         //Frequency table, all initialized to 0
    int idx;                                         //Loop variable
    int totalChars = 0;                                 //Loop variable
    double relFrequency;        // double float for the relative
    double subEntropy = 0;
    double perCharEntropy = 0;
    
    // Prepare the output file
    if((outputFile = fopen(outputFileName,"w")) == NULL) {
            fclose(outputFile);
            printf("Unable to create output file \"%s\": %s\n",
                outputFileName,strerror(errno));
    }

    printf("Enter an unsigned short integer for cipher: ");
    scanf("%u", &cipher);

/*
    Read from the file char by char -> fgetc(inputFile)
    store current read character in inByte -> (inByte = fgetc(inputFile))
    Compare inByte to check whether it is EOF(End of File) -> (inByte = fgetc(inputFile)) != EOF
    if not enter the loop body and execute the statement in the body
*/
    // prep for outputting each char
    printf("The input string is \"");
    while((inByte = fgetc(inputFile)) != EOF) {
        ++freqTable[inByte];                   //Count the byte
        ++totalChars;                          // total characters read so far
        /*
        So if the M is the current character in inByte, ascii code 77
        freqTable[inByte] which is freqTable[77] is incremented
        */
        
        putchar( inByte ); // print each char to the screen
        
        fputc( myEncrypt( inByte, cipher ),  outputFile );
        
    }
    printf("\"\n");

    fclose(outputFile);     // close the output file handle

    /* Printing the frequencies */
    printf("\nThe character frequencies for are:\n");

    for(idx = 0; idx < 256; idx++) {

        if(freqTable[idx] > 0) /* need only the chars found in the file, hence the ones with count > 0*/
        {
            printf("Char code %03d ",idx); /* no new line, printing the ascii value of the character */
            switch((char)idx) { /*convert idx to char, which'll give me the literal value of the character*/
                    case '\r':
                        printf("(\\r"); /*special*/
                        break;
                    case '\n':
                        printf("(\\n");
                        break;
                    case '\t':
                        printf("(\\t");
                        break;
                    case '\v':
                        printf("(\\v");
                        break;
                    default:
                        printf(" (%c",idx);
                        break;
            }
            printf(") occurs %d times ",freqTable[idx]);

            // calculate the relative frequency and entropy
            relFrequency = (double)freqTable[idx] / totalChars;
            subEntropy = relFrequency * log(relFrequency) / log(2.0);
            perCharEntropy += subEntropy;
            
            printf("for a relative frequency of %.3f\n", relFrequency );
        }
    }
    
    perCharEntropy *= -1.0;

    printf("\nThe per-character entropy is %.3f\n", perCharEntropy);
    printf("The total entropy is %.3f\n", perCharEntropy * totalChars);
    
    printf("\nThe file \"%s\" has been written using a Caesar shift of %u\n", outputFileName, cipher );
}

char myEncrypt(char myChar, unsigned short int shift)
{
    char start;
    // Encrypt each char and put it in the output file
    if(myChar >= 'A' && myChar <= 'Z')
    {
        start = myChar - 'A';
        // write encrypted char to file and keep it within A-Z
        return ((start + shift) % 26 + 'A');
    }
    else if(myChar >= 'a' && myChar <= 'z')
    {
        start = myChar - 'a';
        // write encrypted char to file and keep it  within a-z
        return ((start + shift) % 26 + 'a');
    }
    else
    {
        // it's not an A-Z or a-z char, just put it in the file
        return myChar;
    }
}
