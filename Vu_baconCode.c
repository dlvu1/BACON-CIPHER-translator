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

const char* englishToBaconCode(const char *english) {
    const char* baconAlphabet[26] = {
        "xxxxx", "xxxxo", "xxxox", "xxxoo", "xxoxx", "xxoxo",
        "xxoox", "xxooo", "xoxxx", "xoxxo", "xoxox", "xoxoo",
        "xooxx", "xooxo", "xooox", "xoooo", "oxxxx", "oxxxo",
        "oxxox", "oxxoo", "oxoxx", "oxoxo", "oxoox", "oxooo",
        "ooxxx", "ooxxo"
    };
    
    char *token;
    static char baconCode[255 * 6]; // 5 characters with a | in between
    baconCode[0] = '\0';

    char *copy = strdup(english); // Make a copy of the input

    token = strtok(copy, " \n"); // Tokenize the string copy

    while (token != NULL) {
        int tokenLength = strlen(token);
        
        for (int i = 0; i < tokenLength; i++) {
            char c = token[i];
            
            switch (c) {
                case 'a': case 'A':
                    strcat(baconCode, baconAlphabet[0]);
                    break;
                case 'b': case 'B':
                    strcat(baconCode, baconAlphabet[1]);
                    break;
                case 'c': case 'C':
                    strcat(baconCode, baconAlphabet[2]);
                    break;
                case 'd': case 'D':
                    strcat(baconCode, baconAlphabet[3]);
                    break;
                case 'e': case'E':
                    strcat(baconCode, baconAlphabet[4]);
                    break;
                case 'f': case 'F':
                    strcat(baconCode, baconAlphabet[5]);
                    break;
                case 'g': case 'G':
                    strcat(baconCode, baconAlphabet[6]);
                    break;
                case 'h': case 'H':
                    strcat(baconCode, baconAlphabet[7]);
                    break;
                case 'i': case 'I':
                    strcat(baconCode, baconAlphabet[8]);
                    break;
                case 'j': case 'J':
                    strcat(baconCode, baconAlphabet[9]);
                    break;
                case 'k': case 'K':
                    strcat(baconCode, baconAlphabet[10]);
                    break;
                case 'l': case 'L':
                    strcat(baconCode, baconAlphabet[11]);
                    break;
                case 'm': case 'M':
                    strcat(baconCode, baconAlphabet[12]);
                    break;
                case 'n': case 'N':
                    strcat(baconCode, baconAlphabet[13]);
                    break;
                case 'o': case 'O':
                    strcat(baconCode, baconAlphabet[14]);
                    break;
                case 'p': case 'P':
                    strcat(baconCode, baconAlphabet[15]);
                    break;
                case 'q': case 'Q':
                    strcat(baconCode, baconAlphabet[16]);
                    break;
                case 'r': case 'R':
                    strcat(baconCode, baconAlphabet[17]);
                    break;
                case 's': case 'S':
                    strcat(baconCode, baconAlphabet[18]);
                    break;
                case 't': case 'T':
                    strcat(baconCode, baconAlphabet[19]);
                    break;
                case 'u': case 'U':
                    strcat(baconCode, baconAlphabet[20]);
                    break;
                case 'v': case 'V':
                    strcat(baconCode, baconAlphabet[21]);
                    break;
                case 'w': case 'W':
                    strcat(baconCode, baconAlphabet[22]);
                    break;
                case 'x': case 'X':
                    strcat(baconCode, baconAlphabet[23]);
                    break;
                case 'y': case 'Y':
                    strcat(baconCode, baconAlphabet[24]);
                    break;
                case 'z': case 'Z':
                    strcat(baconCode, baconAlphabet[25]);
                    break;
                default:
                    strcat(baconCode, "!!!!!"); // Return !!!!! when a character is not passed any cases above
                    break;
            }
            
             strcat(baconCode, "|");
        }

        strcat(baconCode, "/|");
        token = strtok(NULL, " "); // Move to the next token
        
    } 
    
    // Remove the extra separators
    if (strlen(baconCode) > 0) {
        baconCode[strlen(baconCode) - 3] = '\0'; 
    }
    
    free(copy); // Free the allocated memory to prevent segmentation fault
    
    return baconCode;
}

char* baconCodeToEnglish(const char *baconCode) {
    const char* baconAlphabet[26] = {
        "xxxxx", "xxxxo", "xxxox", "xxxoo", "xxoxx", "xxoxo",
        "xxoox", "xxooo", "xoxxx", "xoxxo", "xoxox", "xoxoo",
        "xooxx", "xooxo", "xooox", "xoooo", "oxxxx", "oxxxo",
        "oxxox", "oxxoo", "oxoxx", "oxoxo", "oxoox", "oxooo",
        "ooxxx", "ooxxo"
    };
    
    char *token;
    static char english[255];
    english[0] ='\0';
    
    char *copy = strdup(baconCode); // Make a copy of the input
    
    token = strtok(copy, "|");
    
     while (token != NULL) {
         
        if (strcmp(token, "!!!!!") == 0) { // Check if token is "!!!!!"
            strcat(english, "#");
            
        } else if (strcmp(token, "/")  == 0) { // Check if token is "/"
            strcat(english, " ");
            
        } else if (strlen(token) == 5) { // Check if the length of each bacon character equals 5
            int count = 0;
            
            for (int j = 0; j < 26; j++) {
                if (strcmp(token, baconAlphabet[j]) == 0) { // Compare 2 strings, token and baconAlphabet
                    char c = 'A' + j; // From A-Z upper case
                    strncat(english, &c, 1);
                    count = 1;
                    break;
                }
            }
            
            if (count == 0) { // Anything other than x and o, print %
                strcat(english, "%");
            }
            
        } else {
            strcat(english, " ");
        }

        token = strtok(NULL, "|");
    }

    free(copy); // Free the allocated memory to prevent segmentation fault

    return english;
}