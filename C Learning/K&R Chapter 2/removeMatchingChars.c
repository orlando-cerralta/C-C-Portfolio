// Author:  Orlando Cerralta
// Date:    9/20/2020
// Program: Compares two strings and deletes matching characters 
//          from string 2 inside of string 1
#include <stdio.h>
#include <stdbool.h>

// global constant
const int LIMIT = 100;

// prototypes
void lineget(char str[]);
void ignore(); // clears remaining input in stream
void squeeze(char str1[], char str2[]); // deletes matching chars from
                        // str2 within str1

int main() {
    char    line1[LIMIT], line2[LIMIT];
    
    printf("This program compares two strings and removes matching characters "
            "from the second string inside the first!\n");
    
    printf("Line 1: ");
    lineget(line1);
    printf("Line 2: ");
    lineget(line2);

    squeeze(line1, line2);

    printf("First line without matching characters: \"%s\"\n", line1);

    return 0;
}

// lineget: recieves char string
void lineget(char str[]) {
    char    c;
    int     i;

    for (i = 0; i < (LIMIT - 1) && (c = getchar()) != EOF && c != '\n'; i++) {
        str[i] = c;
    }
    // if there are any chars left in stream, ignore them
    if (c != EOF && c != '\n')
        ignore();
    // null terminator
    str[i] = '\0';

    return;
}

// ignore: clears any remaining input left in stream
void ignore() {
    char c;

    while((c = getchar()) != EOF && c != '\n')
        /*clears stream*/;

    return;
}

// squeeze: deletes matching chars from str2 within str1
void squeeze(char str1[], char str2[]) {
    int     i, j;       // original and newly assigned position for str1, respectively
    int     x;          // position for str2
    bool    foundMatch; // LCV, checks if matching chars are found

    // run through each character in str1
    for (i = 0, j = 0; str1[i] != '\0'; i++) {
        // run through each char in str2 until null or match has been found
        for (x = 0, foundMatch = false; str2[x] != '\0' && foundMatch != true; x++) {
            // if chars in both strings are the same, update flag
            if (str1[i] == str2[x])
                foundMatch = true;
        }
        // if no match is found, assign character to where position j left off
        if(!foundMatch)
            str1[j++] = str1[i];
    }
    str1[j] = '\0';

    return;
}
