# Building a Turing Machine using Cellular Automata
Peter, take a look at the pdf. My idea was to try to emulate the results they got, by making an adder of some sort.

# Current Code:
I am making the product in C. It will be on the command line. If you see the output of colored squares, it is supposed to represent a pattern you'd see on page 5 of the pdf. None of the logic is coded yet, but thats the fun part I guess

The actuall Cell values are not colors, they are stored in a char array which is then interpreted by a switch statement that translates them into colors for easier visualization on the CL. I'm a bit unsure how the actual Turing Machine is supposed to be made but the black cell (which represents the head) should move to the left and right based on the previous state. Each iteration will then print out and you should get the same figure as in the pdf... In theory... I couldnt understand the pdf's complex math words, but hopefully thats not relevant.
