#include "doIntro.c"
#include "doLogic.c"
#include <stdio.h>
#include <string.h>

intPair doIntro();
binPair int2bin();
void translateAndPrint(char*);
char* formStartingString(char*, char*);
void pprintf(char*);
char* iterate(char*);
void convertForNormies(char*);

int main(int argc, char *argv[]) {
    intPair startingMaterial = doIntro(); //Ask what integers to add
    binPair startingBinary = int2bin(startingMaterial.first, startingMaterial.second); //Convert the two ints to binary
    char* startingString = formStartingString(startingBinary.first, startingBinary.second); //Convert the binary into a syntax-correct string ready for the CA logic loop
    //adding printfs for UI benefit
    pprintf(startingString);
    printf("state: a "); //Print the starting state
    translateAndPrint(startingString); //Print the starting string
    startingString = iterate(startingString); //call the recursive function from doLogic.c
    pprintf(startingString); // call recursive function from doLogic.c
    convertForNormies(startingString); //Convert the binary result to base 10 for the user
    return 0;
}
