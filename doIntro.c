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
binPair int2bin(int int1, int int2){ //I just used AI for this. I am not about to spend several hours relearning memory allocataion
    // Convert both to binary strings (with one leading '0' for n>0)
    char* first  = int2binHelper(int1);
    char* second = int2binHelper(int2);

    if (!first || !second){
        // Clean up and return NULLs on allocation failure
        if (first) free(first);
        if (second) free(second);
        binPair err = {NULL, NULL};
        return err;
    }

    int firstLen = (int)strlen(first);
    int secondLen = (int)strlen(second);

    if (firstLen == secondLen){
        binPair ok = {first, second};
        return ok;
    }

    // Pad the shorter one on the left with '0's to match lengths
    if (firstLen < secondLen){
        int diff = secondLen - firstLen;
        char* padded = (char*)malloc((size_t)secondLen + 1);
        if (!padded){
            free(first); free(second);
            binPair err = {NULL, NULL};
            return err;
        }
        memset(padded, '0', (size_t)diff);
        memcpy(padded + diff, first, (size_t)firstLen + 1); // include NUL
        free(first);
        first = padded;
    } else { // firstLen > secondLen
        int diff = firstLen - secondLen;
        char* padded = (char*)malloc((size_t)firstLen + 1);
        if (!padded){
            free(first); free(second);
            binPair err = {NULL, NULL};
            return err;
        }
        memset(padded, '0', (size_t)diff);
        memcpy(padded + diff, second, (size_t)secondLen + 1);
        free(second);
        second = padded;
    }

    binPair result = {first, second};
    return result;
}

/*
 * This logic was mostly done with AI
 */
char* int2binHelper(int start) {
    if (start == 0) {
        char* s = (char*)malloc(3); // Allocate space for "00" + '\0'
        if (!s) return NULL;
        s[0] = '0';
        s[1] = '0';
        s[2] = '\0';
        return s;
    }

    unsigned int n = (unsigned int)start; // Treat as unsigned magnitude
    // Count significant bits
    int bits = 0;
    unsigned int t = n;
    while (t) { bits++; t >>= 1; }

    // Include two leading '0's
    int outLen = bits + 2; // 2 leading '0's + bits
    char* out = (char*)malloc((size_t)outLen + 1); // +1 for '\0'
    if (!out) return NULL;

    int idx = 0;
    out[idx++] = '0';
    out[idx++] = '0';
    for (int i = bits - 1; i >= 0; --i) {
        out[idx++] = (n & (1U << i)) ? '1' : '0';
    }
    out[idx] = '\0';
    return out;
}

/*
 * Okay, so if you see the paper, each cell is a color which corresponds to a symbol. Those are Blank (B), Equals (=), 0 (0),1 (1), locked-in 0 (b), locked-in 1 (y), and Addition (+). To get more info on β, please check out doLogic.c, but in brief, it represents a State of the Turing Machine */
char* formStartingString(char* first, char* second){
    int productLen = 8 + (int)strlen(first) + (int)strlen(second);
    char* startingString = (char*)malloc((size_t)productLen + 1);
    if (!startingString) return NULL;
    // Build: BBb= + first + + + second + =BB
    startingString[0] = '\0';
    strcat(startingString, "BBa=");
    strcat(startingString, first);
    strcat(startingString, "+");
    strcat(startingString, second);
    strcat(startingString, "=BB");
    return startingString;
}
