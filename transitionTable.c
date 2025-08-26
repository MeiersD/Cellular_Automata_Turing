#include <stdio.h>
#include <string.h>

 struct Rule {
     char nextState; // the state to transition to
     char newSymbol; // the symbol to write to the tape
     char direction; // 'L' for left, 'R' for right
 };

struct State { //there is one rule per element in the tape's alphabet
               //the alphabet is "=", "1", "0", "+", "B", "x", "y"
   char stateName; // the name of the state
   char* rule1;
   char* rule2;
   char* rule3;
   char* rule4;
   char* rule5;
   char* rule6;
   char* rule7;
};

char transitionTable[13][7][3]=  //13 states, 7 tape symbols, 3 directions per rule
                                 //states: a, b, c, d, e, f, g, h, i, j, k, l, m
                                 //"=", "1", "0", "+", "B", "y", "x"
                                 //R = right, L = left
{
    // State a (a)
    {
      {'a', '=', 'R'},
      {'a', '1', 'R'},
      {'a', '0', 'R'},
      {'a', '+', 'R'},
      {'b', 'B', 'L'},
      {},
      {},
    },
    // State b (Q0)
    {
      {'c', 'B', 'L'},
      {},
      {},
      {},
      {},
      {},
      {},
    },
    // State c (dig)
    {
      {},
      {'e', '=', 'L'},
      {'d', '=', 'L'},
      {'k', '+', 'L'},
      {},
      {},
      {},
    },
    // State d (zle)
    {
      {},
      {'d', '1', 'L'},
      {'d', '0', 'L'},
      {'f', '+','L'},
      {},
      {},
      {},
    },
    // State e (ole)
    {
      {},
      {'e','1','L'},
      {'e','0','L'},
      {'g','+','L'},
      {},
      {},
      {},
    },
    // State f (zad)
    {
      {'i','y','L'},
      {'j','x','R'},
      {'j','y','R'},
      {},
      {},
      {'f','y','L'},
      {'f','x','L'},
    },
    // State g (oad)
    {
      {'i','x','L'},
      {'h','y','L'},
      {'j','1','R'},
      {},
      {},
      {'g','y','L'},
      {'g','x','L'},
    },
    // State h (car)
    {
      {'i','1','L'},
      {'h','0','L'},
      {'j','1','R'},
      {},
      {},
      {},
      {},
      
    },
    // State i (new)
    {
      {},
      {},
      {},
      {},
      {'j','=','R'},
      {},
      {},
    },
    // State j (rig)
    {
      {'c','B','L'},
      {'j','1','R'},
      {'j','0','R'},
      {'j','+','R'},
      {},
      {'j','y','R'},
      {'j','x','R'},
    },
    // State k (lef)
    { 
      {'l','B','R'},
      {'k','1','L'},
      {'k','0','L'},
      {},
      {},
      {'k','y','L'},
      {'k','x','L'},
    },
    // State l (fin)
    {
      {},
      {'l','1','R'},
      {'l','0','R'},
      {'m','B','R'},
      {},
      {'l','0','R'},
      {'l','1','R'},
    },
    // State m (halt)
    {
      {},
      {},
      {},
      {},
      {},
      {},
      {},
    }
};
