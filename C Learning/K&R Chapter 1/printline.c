// Author: Orlando Cerralta
// Date: 08/13/2020
// Description: This program reads character strings from the user
//              then finally outputs the longest string entered
#include <stdio.h>

#define MAXLINE 1000    // maximum input line size

int lineget(char str[], int limit);
void copy(char current[], char newLongest[]);

// print longest input line
int main() {
    int     len;            // current line length
    int     maxLen;            // maximum length so far
    char    line[MAXLINE];      // current input line
    char    longest[MAXLINE];   // longest line saved here

    printf("This program records the longest string entered from the keyboard.\n");
    printf("Enter as many lines as you like!\n");
    printf("When done, enter the EOF command to quit. (This may be CTRL+D in Linux)\n");
    // reads line from user
    maxLen = 0;
    while ((len = lineget(line, MAXLINE)) > 0) {
        // if current line is longer, copy into variable 'longest'
        if  (len > maxLen) {
            maxLen = len;
            copy(longest, line);
        }
    }

    // if there was a line entered, print longest line
    if (maxLen > 0) {   
        putchar('\n');
        printf("Longest line entered: %s\n", longest);
    }
    return 0;
}

// lineget: reads line into s, and returns length
int lineget(char str[], int limit) {
    int c, i;

    // read chars and stops recording line once it detects EOF or newline
    for (i = 0; i < (limit - 1) && (c = getchar()) != EOF && c != '\n'; ++i)
        str[i] = c;

    // places newline character where the loop exited, if entered
    if (c == '\n') {
        str[i] = c;
        ++i;
    }
    // place null at the end of line
    str[i] = '\0';
    
    return i;
}

// copy: copies each index value from 'newLongest' into 'current'
void copy(char current[], char newLongest[]) {
    for (int i = 0; (current[i] = newLongest[i]) != '\0'; ++i)
        ;
}
