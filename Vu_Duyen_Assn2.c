/*
Author: Duyen Vu
Date: 06/16/2023
Description: BACON CIPHER translator
Usage: 
gcc Vu_Duyen_Assn2.c Vu_baconCode.c -o assn2exe
./assn2exe -b test.txt testBC.bc
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Vu_baconCode.h"

int main(int argc, char** argv) {
    
    char english[255];
    char baconCode[255 * 6];
    
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    
    FILE* inputFile;
    FILE* outputFile;
    
    if (argc != 4) { // Check the number of arguments
        printf("Error -- usage: %s <-b|-e> <input file> <output file>\n", argv[0]);
        return -1;
    }
    
    inputFile = fopen(argv[2], "r");   // Second command line argument (the file contains the text we want to translate)
    outputFile = fopen(argv[3], "w");  // Third command line argument (output file for writing only)

    if (inputFile == NULL || outputFile == NULL) {  // If no files given, print error
        printf("Error! can not open file!\n");
        return -1;
    }

    // Check the operation option
    if (strcmp(argv[1], "-b") == 0) {  // Translate English to Bacon code if argument 1 is -b
        printf("Translating %s to BACON code\n", argv[2]);
            
            // Read the input from the file
            while ((read = getline(&line, &len, inputFile)) != -1) {
                line[strcspn(line, "\n")] = '\0';
                
                strcpy(baconCode, englishToBaconCode(line)); // Making a copy from englishToBaconCode to baconCode
                
                fprintf(outputFile, "%s\n", baconCode);
                
                if (read > 0 && line[read - 1] == '\n') { // Check if the input line has any \n 
                    fprintf(outputFile, "\n");
                }
            }
                
        printf("%s file completed.\n", argv[3]); 
            
    } else if (strcmp(argv[1], "-e") == 0) {  // Translate BACON code to English if argument 1 is -e
        printf("Translating %s to English\n", argv[2]);
            
            // Read the input from the file
            while ((read = getline(&line, &len, inputFile)) != -1) {
                line[strcspn(line, "\n")] = '\0';
                
                strcpy(english, baconCodeToEnglish(line)); // Making a copy from baconCodeToEnglish to english
                
                fprintf(outputFile, "%s\n", english);
                
                if (read > 0 && line[read - 1] == '\n') {
                    fprintf(outputFile, "\n"); // Check if the input line has any new line, print \n if there is one
                }
            } 
            
        printf("%s file completed.\n", argv[3]); 
        
    } else {
        printf("Error -- usage: ./assn2exe <-b|-e> <input file> <output file>\n"); // If the first argument is not -b or -e, print error
        fclose(inputFile);
        fclose(outputFile);
        return -1;
    }
    
    free(line); // Free the memory
    
    // Close the files
    fclose(outputFile);
    fclose(inputFile);

    return 0;
}
