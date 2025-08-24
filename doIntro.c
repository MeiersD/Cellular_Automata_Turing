#include "translate.c"
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

/*
 * The purpose of this function is to collect two ints from the user, returns an intPair struct
 * */
intPair doIntro(){    
    printf(ANSI_COLOR_TAN "what 2 integers would you like to add?\n" ANSI_COLOR_RESET);
    int int1;
    int int2;
    scanf("%d", &int1);
    scanf("%d", &int2);
    intPair result = {int1, int2};
    return  result;
}

/*
 * The purpose of this function is to turn the user's inputs to binary. This is mostly done with the helper function int2binHelper, but then some leading 0s are added to whichever number is smaller so that they have an equal number of digits. For example, 7 and 90 become "0111" and "01011010" which then become "00000111" and "01011010". 
 */
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

/*
 * This logic was mostly done with AI
 */
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

/*
 * Okay, so if you see the paper, each cell is a color which corresponds to a symbol. Those are Blank (B), Equals (=), 0 (0),1 (1), locked-in 0 (b), locked-in 1 (y), and Addition (+). I also added the Turing head (h) because that is it's own cell too. Also apparently there is a requirement to use an additional color when moving left? Unsure why but That will be its own cell too: Left (l)
 */
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
