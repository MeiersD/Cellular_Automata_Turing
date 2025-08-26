#include "translate.c"
#include "transitionTable.c"
#include <stdio.h>
#include <string.h>

void translateAndPrint(char*);
char* iterate(char*);

// Because I had the enormous forsight to make this app in C, I need to make all state names a single character so they can be represented on the tape
enum CurrState {
    a = 0, //a this is the starting state
    b = 1, //Q0 
    c = 2, //dig
    d = 3, //zle
    e = 4, //ole
    f = 5, //zad
    g = 6, //oad
    h = 7, //car
    i = 8, //new 
    j = 9, //rig
    k = 10, //lef
    l = 11, //fin
    m = 12 //halt ends the binary addition program
};

enum CurrState currState = a;
int headPos = 2;

/*
 * The plan is to make a function which calls itself recursivly and prints out the current row each time. Params: Starting string
 */
char* iterate(char* currString){
    // Base case
    if (currState == m){return currString;}
    
    // get the current character under the head
    char currChar = currString[headPos+1];
    int charHash;
    switch (currChar){
        case '=': charHash = 0; break;
        case '1': charHash = 1; break;
        case '0': charHash = 2; break;
        case '+': charHash = 3; break;
        case 'B': charHash = 4; break;
        case 'y': charHash = 5; break;
        case 'x': charHash = 6; break;
    }
    char* currRules = transitionTable[currState][charHash];

    // modify state for the next iteration
    int nextState = currRules[0] - 'a'; // convert char to int
    currState = nextState;

    // write the new character
    currString[headPos+1] = currRules[1]; // write the new character

    
    // move the head
    char temp;
    if (currRules[2] == 'R'){
        temp = currString[headPos+1];
        currString[headPos+1] = nextState + 'a';
        currString[headPos] = temp;
        headPos += 1;
    } else if (currRules[2] == 'L'){
        temp = currString[headPos-1];
        currString[headPos-1] = nextState + 'a';
        currString[headPos] = temp;
        headPos -= 1;
    }

    // print out currString string
    printf("state: %c ", currState + 'a');
    translateAndPrint(currString);
    iterate(currString);
}
