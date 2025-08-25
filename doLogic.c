#include "translate.c"
#include <stdio.h>
#include <string.h>

void translateAndPrint(char*);
char* iterate(char*);

// Because I had the enormous forsight to make this app in C, I need to make all state names a single character so they can be represented on the tape
enum State {
    a = 'a', //a
    b = 'b', //Q0 this is the starting state
    c = 'c', //dig
    d = 'd', //zle
    e = 'e', //ole
    f = 'f', //zad
    g = 'g', //oad
    h = 'h', //car
    i = 'i', //new 
    j = 'j', //rig
    k = 'k', //lef
    l = 'l', //fin
    m = 'm' //halt ends the binary addition program
};

enum State state = b;
int headPos = 2;

/*
 * The plan is to make a function which calls itself recursivly and prints out the current row each time. Params: Starting string
 */
char* iterate(char* currString){
    // Base case
    if (state == m){return currString;}
    char* nextString = currString; // nextString starts as a copy of currString, then gets modified based on current state and headPos
    //
    // change state
    // print out nextString string
    translateAndPrint(nextString);
    // iterate(nextString)
}
