// Author: Orlando Cerralta
// Date: 08/02/2020
// Description: This program prints a horizontal histogram of
//              the length of words entered by the user
#include <stdio.h>

#define IN      1
#define OUT     0
#define LIMIT   10

int main() {
    int c; // Stores a character.
    int hold; // Holds and finds out the length of a word
            // before storing it into length[]
    int state; // Finds out if it is IN or OUT of a word.
    int length[LIMIT]; // Stores the word length;
                    // length[0] for 1 letter words, length[1] for 2, etc.
                    // length[9] for words longer than 9 letters
    
    // intitialize the array of 'length'
    for (int i = 0; i < LIMIT; i++)
        length[i] = 0;

    // introduction
    printf("Welcome, enter as many words as you like, when finished enter '!' to stop.\n");
    printf("I will then display a histogram of the length of words entered.\n");
    printf("Enter '!' when done: ");
    
    // user enters any amount of words until they enter '!'
    hold = 0;
    state = OUT;
    while ( (c = getchar()) != '!') { // loop until user enters '!'
        // if user enters whitespace character, ends word or continues not being in a word
        if (c == '\t' || c == '\n' || c == ' ') {
            if (state == IN)
                state = OUT; // state ends word or continues no word if 'hold' is 0
            
            if (hold > 9) { // increments words longer than 9
                ++length[LIMIT - 1];
                hold = 0; // reset word length stored in hold
            }
            else if (hold > 0) {
                ++length[hold - 1]; // if hold is less than 10 and greater 
                                    // than 0, increment array position 
                                    // of length corresponding to hold
                hold = 0; // reset word length stored in hold
            }
        }
        // if user enters a character that isn't whitespace, begin or continue word
        else {
            state = IN; // state begins or continues length of current word
            ++hold; // increment word length
        }
    }
    
    // display histogram
    putchar('\n');
    printf(" - WORD LENGTH HISTORGRAM - \n");
    for (int pos = 0; pos < (LIMIT - 1); pos++) { // loop while pos is less than 9 for the constant number lengths
        printf("%d letter words: ", (pos + 1)); // prints current length position
        for (int i = 0; i < length[pos]; i++) // prints x for the number of times the user enters N amount of letters, horizontally
            putchar('x');
        putchar('\n'); // go to next line
    }
    printf("even longer words: ");
    for (int i = 0; i < length[LIMIT - 1]; i++)
        putchar('x');
    putchar('\n');

    return 0;
}
