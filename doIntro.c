#include "doLogic.c"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

typedef struct {
    int first;
    int second;
} intPair;

typedef struct {
    char* first;
    char* second;
} binPair;

intPair doIntro();
binPair int2bin(int,int);
char* int2binHelper(int);
char* formStartingString(char*,char*);

intPair doIntro(){    
    printf(ANSI_COLOR_TAN "what 2 integers would you like to add?\n" ANSI_COLOR_RESET);
    int int1;
    int int2;
    scanf("%d", &int1);
    scanf("%d", &int2);
    intPair result = {int1, int2};
    return  result;
}

binPair int2bin(int int1, int int2){
    binPair result = {int2binHelper(int1),int2binHelper(int2)};
    int firstLen = strlen(result.first);
    int secondLen = strlen(result.second);
    int zerosToAdd = abs(firstLen - secondLen);
    if (firstLen > secondLen){
        char zeroString[firstLen];
        for (int i = 0; i < zerosToAdd; i++){
            zeroString[i] = '0';
        }
        strcat(zeroString, result.second);
        result.second = zeroString;
    } else if (firstLen < secondLen) {
        char zeroString[secondLen];
        for (int i = 0; i < zerosToAdd; i++){
            zeroString[i] = '0';
        }
        strcat(zeroString, result.first);
        result.first = zeroString;
    }
    return result;
}


char* int2binHelper(int start) {
    int bits = sizeof(int) * CHAR_BIT;
    char* binary = malloc(bits + 1);
    if (!binary) return NULL;

    unsigned int mask = 1U << (bits - 1);
    int i = 0;
    int firstOneLoc = 0;

    while (mask) {
        binary[i++] = (start & mask) ? '1' : '0';
        if (firstOneLoc == 0 && (start & mask)) {
            firstOneLoc = i - 1;   // mark first '1'
        }
        mask >>= 1;
    }
    binary[i] = '\0';

    // Slice from first '1'
    int sliceLen = bits - (firstOneLoc - 1);
    char* slice = malloc(sliceLen + 1);
    if (!slice) { free(binary); return NULL; }

    strcpy(slice, binary + firstOneLoc - 1);

    free(binary);
    return slice;
}

char* formStartingString(char* first, char* second){
    int productLen = 8 + strlen(first) + strlen(second); 
    char* startingString = malloc(productLen * sizeof(char));
    strcpy(startingString, "BBh=");
    strcat(startingString, first);
    strcat(startingString, "+");
    strcat(startingString, second);
    strcat(startingString, "=BB");
    return startingString;
}
