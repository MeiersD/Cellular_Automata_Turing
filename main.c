#include "doIntro.c"
#include <stdio.h>
#include <string.h>

intPair doIntro();
binPair int2bin();
void translateAndPrint(char*);
char* formStartingString(char*, char*);

int main(int argc, char *argv[]) {
    intPair startingMaterial = doIntro();
    binPair startingBinary = int2bin(startingMaterial.first, startingMaterial.second);
    char* startingString = formStartingString(startingBinary.first, startingBinary.second);
    printf("here is the translation:\n");
    translateAndPrint(startingString);
    return 0;
}
