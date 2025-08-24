#include <stdio.h>
#include <string.h>
#include <limits.h>

#define ANSI_COLOR_BLUE    "\x1b[38;5;19m"
#define ANSI_COLOR_TAN       "\x1b[38;5;180m"  // Tan (Light Brown)
#define ANSI_COLOR_BLACK     "\x1b[38;5;16m"    // Black
#define ANSI_COLOR_GREEN   "\x1b[38;5;82m"
#define ANSI_COLOR_PURPLE    "\x1b[38;5;93m"   // Purple (Lavenderish)
#define ANSI_COLOR_ROYALBLUE "\x1b[38;5;69m"  // Royal Blue
#define ANSI_COLOR_LIGHTGREY "\x1b[38;5;7m"    // Light Grey
#define ANSI_COLOR_DARKTEAL  "\x1b[38;5;23m"   // Dark Teal (Greenish-Blue)
#define ANSI_COLOR_CYAN    "\x1b[38;5;86m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void translateAndPrint(char*);

void translateAndPrint(char* currLine){
    if (currLine == NULL) {
        printf("translateAndPrint: currLine is NULL!\n");
        return;
    }
    printf("translateAndPrint: received string = '%s'\n", currLine);
    for (int i = 0; i < strlen(currLine); i++) {
        switch (currLine[i]){
            case 'B': printf(ANSI_COLOR_BLUE "█"); break;
            case '=': printf(ANSI_COLOR_TAN "█"); break;
            case 'h': printf(ANSI_COLOR_BLACK "█"); break;
            case '0': printf(ANSI_COLOR_GREEN "█"); break;
            case '1': printf(ANSI_COLOR_PURPLE "█"); break;
            case '+': printf(ANSI_COLOR_ROYALBLUE "█"); break;
            case 'l': printf(ANSI_COLOR_LIGHTGREY "█"); break;
            case 'b': printf(ANSI_COLOR_DARKTEAL "█"); break;
            case 'y': printf(ANSI_COLOR_CYAN "█"); break;
            default: break;
        }
    }
    printf("\n" ANSI_COLOR_RESET);
    return;
}
//char arr[18] = {'B','B','H','E','0','0','1','0','1','+','0','0','1','0','1',,,4,'B','B'};
