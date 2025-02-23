/* Owen McClure */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define fileNameLength 256

typedef struct {
    char word[256];
    int lineNumber;
} wordLines;

int main()
{
    FILE *inputFile;
    char inputFileName[256] = {0};
    int fileLine = 0;
    int wordsCountedSoFar = 0;      /* wordsCountedSoFar == 0 to begin with */
    int i;
    char bufferString[256];
    char bufferChar;
    char *result = NULL;
    char delims[] = " ";
    int foundWord = 0;
    wordLines Dictionary[1000];

    printf("Program: Structs\n");

    do
    {
        // open file, be sure not null
        printf("Enter an input file name: ");
        fgets(inputFileName, fileNameLength, stdin);
        inputFileName[strlen(inputFileName) - 1] = '\0';
        if ((inputFile = fopen(inputFileName, "r")) == NULL)
        {
            printf("Unable to open \"%s\": %s\n", inputFileName,
                strerror(errno));
        }
    } while (inputFile == NULL);

    for(i = 0; i < 1000; ++i)
    {
        /* 
		 * initialize the line numbers for each word to be 0
		 * that way later on when I've collected all the words
		 * I will filter the ones with line number not equal to 0
		*/
        Dictionary[i].lineNumber = 0;
    }

    while ( fgets(bufferString, 256, inputFile) )          /* read one line at a time from the file */
    {
        ++fileLine;                                     /* increase the file number */
        
        printf("\nWords found in line %d, \"%s\"",fileLine, bufferString);
        
        bufferString[strlen(bufferString) -1] = '\0';       /* remove the linefeed char at the end */

        result = strtok( bufferString, delims );          /* read until the first space (end of word) from line*/

        while( result != NULL )                         /* keep reading till no more words in the line*/
        {
            printf( "\"%s\"\n", result );

            /* store the distinct words */
            for(i = 0; i < wordsCountedSoFar; ++i)      /* wordsCountedSoFar == 0 to begin with */
            {
                if(strcmp(Dictionary[i].word, result) == 0)
                    /* if the word found in the dictionary, exit from this 
					   particular word loop.
					   Because this word is not distinct, I do not need to
					   store it */
                {                               
                    break;
                }
            }
            
            if( i == wordsCountedSoFar )  /* if i is equal to wordsCountedSoFar, means word was not found in the dictionary */
            {
                /* store the distinct words */
                strcpy(Dictionary[i].word, result);
                // store the line number
                Dictionary[i].lineNumber = fileLine;
                wordsCountedSoFar++;
            }
            
            /* else if i < wordsCountedSoFar, word already exists so don't increase the word count */
            
            // move to the next word
            result = strtok( NULL, delims );
        }
    }
    fclose(inputFile);                               /* VERY IMPORTANT TO CLOSE THE FILE PTR*/

/* PRINT the words and the line they occured first */
   printf("\nThe input file contains %d distinct words.\n\n", wordsCountedSoFar );
    for(i = 0; i < 1000; ++i)
    {
        if(Dictionary[i].lineNumber > 0)
            printf("Word \"%s\" found at line: %d\n", Dictionary[i].word, Dictionary[i].lineNumber);
    }
    system ("pause");
    return 0;
    

}
