#include <stdio.h>
#include <string.h>

struct Rule {
    char operand; // the symbol on the tape pointed to by the head
    char nextState; // the state to transition to
    char newSymbol; // the symbol to write to the tape
    char direction; // 'L' for left, 'R' for right
};

struct State { //there is one rule per element in the tape's alphabet
               //the alphabet is "=", "1", "0", "+", "B", "x", "y"
   char stateName; // the name of the state
   struct Rule rule1;
   struct Rule rule2;
   struct Rule rule3;
   struct Rule rule4;
   struct Rule rule5;
   struct Rule rule6;
   struct Rule rule7;
};

struct State transitionTable[13] = {
    // State a (a)
    { 'a',
      {'=', 'a', '=', 'R'},
      {'1', 'a', '1', 'R'},
      {'0', 'a', '0', 'R'},
      {'+', 'a', '+', 'R'},
      {'B', 'b', 'B', 'L'},
    },
    // State b (Q0)
    { 'b',
      {'=', 'c', 'B', 'L'},
    },
    // State c (dig)
    { 'c',
      {'1', 'e', '=', 'L'},
      {'0', 'd', '=', 'L'},
      {'+', 'k', '+', 'L'},
    },
    // State d (zle)
    { 'd',
      {'1', 'd', '1', 'L'},
      {'0', 'd', '0', 'L'},
      {'+', 'f', '+','L'},
    },
    // State e (ole)
    { 'e', 
      {'1','e','1','L'},
      {'0','e','0','L'},
      {'+','g','+','L'},
    },
    // State f (zad)
    { 'f',
      {'=','i','y','L'},
      {'1','j','x','R'},
      {'0','j','y','R'},
      {'y','f','y','L'},
      {'x','f','x','L'},
    },
    // State g (oad)
    { 'g',
      {'=','i','x','L'},
      {'1','h','y','L'},
      {'0','j','B','R'},
      {'y','g','y','L'},
      {'x','g','x','L'},
    },
    // State h (car)
    { 'h',
      {'=','i','1','L'},
      {'1','h','0','L'},
      {'0','j','1','R'},
    },
    // State i (new)
    { 'i',
      {'B','j','=','R'},
    },
    // State j (rig)
    { 'j',
      {'=','c','B','L'},
      {'1','j','1','R'},
      {'0','j','0','R'},
      {'+','j','+','R'},
      {'y','j','y','R'},
      {'x','j','x','R'},
    },
    // State k (lef)
    { 'k',
      {'=','l','B','R'},
      {'1','k','1','L'},
      {'0','k','0','L'},
      {'y','k','y','L'},
      {'x','k','x','L'},
    },
    // State l (fin)
    { 'l',
      {'1','l','1','R'},
      {'0','l','0','R'},
      {'+','m','B','R'},
      {'y','l','0','R'},
      {'x','l','1','R'},
    },
    // State m (halt)
    { 'm',
    }
};
