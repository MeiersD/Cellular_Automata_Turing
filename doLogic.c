#include "translate.c"
#include <stdio.h>

char* iterate(char*);

//Do not ask what any of these mean, I got this from Table3 in the paper
enum State {
    a,
    Q0,
    dig,
    zle,
    ole,
    zad,
    oad,
    car,
    new,
    rig,
    lef,
    fin,
    halt
};

/*
 * The plan is to make a function which calls itself recursivly and prints out the current row each time. Params: Starting string
 */
char* iterate(char* currString){
    // Base case
    // if (state = "halt"){return;}
    //
    //
    // change state
    // print out nextString string
    // iterate(nextString)
}
