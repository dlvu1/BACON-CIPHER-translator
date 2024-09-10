/*
Author: Duyen Vu
Date: 06/16/2023
Description: BACON CIPHER translator
Usage: 
gcc Vu_Duyen_Assn2.c Vu_baconCode.c -o assn2exe
./assn2exe -b test.txt testBC.bc
*/

#ifndef BACON_CODE_H
#define BACON_CODE_H

const char* englishToBaconCode(const char *character);
char* baconCodeToEnglish(const char *baconCode);

#endif // BACON_CODE_H 