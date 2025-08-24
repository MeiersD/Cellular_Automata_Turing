#include "doIntro.c"
#include "doLogic.c"
#include <stdio.h>
#include <string.h>

intPair doIntro();
binPair int2bin();
void translateAndPrint(char*);
char* formStartingString(char*, char*);
char* iterate(char*);

int main(int argc, char *argv[]) {
    intPair startingMaterial = doIntro(); //Ask what integers to add
    binPair startingBinary = int2bin(startingMaterial.first, startingMaterial.second); //Convert the two ints to binary
    char* startingString = formStartingString(startingBinary.first, startingBinary.second); //Convert the binary into a syntax-correct string ready for the CA logic loop
    translateAndPrint(startingString); //Print the starting string
    // iterate(startingString) // call recursive function from doLogic.c
    return 0;
}
