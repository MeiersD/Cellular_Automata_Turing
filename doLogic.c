#include "translate.c"
#include "transitionTable.c"
#include <stdio.h>
#include <string.h>

void translateAndPrint(char*);
char* iterate(char*);

// Because I had the enormous forsight to make this app in C, I need to make all state names a single character so they can be represented on the tape
enum CurrState {
    a = 0, //a
    b = 1, //Q0 this is the starting state
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

enum CurrState currState = b;
int headPos = 2;

/*
 * The plan is to make a function which calls itself recursivly and prints out the current row each time. Params: Starting string
 */
char* iterate(char* currString){
    // Base case
    if (currState == m){return currString;}
    char* nextString = currString; // nextString starts as a copy of currString, then gets modified based on current state and headPos
    char currChar = currString[headPos+1];

    ;
    //
    // change state
    // print out nextString string
    translateAndPrint(nextString);
    // iterate(nextString)
}
