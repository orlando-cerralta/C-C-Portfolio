// Author: Orlando Cerralta
// Date: 08/15/2020
// Description: Converts a string of hexadecimal digit to its equivalent int value
// Note: when compiling using gcc, you must include  -lm  to the command to link
//      with <math.h>'s pow() function
#include <stdio.h>
#include <math.h>   // for pow()
#include <ctype.h>

const int LIMIT = sizeof(long) + 2; // the limit for string. Holds the length of bytes of long
                                    // (either 4 or 8, depending on the PC this program is run on)
                                    // + 2 to hold "0x" in string

// prototypes
void            lineGet(char line[], int max, int *len);
unsigned long   getNum(char line[], int len);
int             hexToInt(char h);

int main() {
    char            str[LIMIT + 1]; // +1 to hold null
    int             length;         // holds string length
    unsigned long   num;

    printf("This program converts a string of hexadecimal "
            "digits to its equivalent integer value!\n");
    printf("Enter hex string: ");
    lineGet(str, LIMIT, &length);

    num = getNum(str, length); // convert hex digits in hex string to their int equivalent

    // print results
    putchar('\n');
    printf("Hex: %s\n", str);
    printf("Int Equivalent: %ld\n", num);
    return 0;
}

// lineGet: gets character string and makes sure it's a valid hex digit
//          if char is not a valid hex digit, it will be ignored 
//          and will not be stored in line[]
//          ex. "The C Programming Language" -> "0xeCaaae"
void lineGet(char line[], int max, int *len) {
    char    c; // stores character
    int     pos; // counter for position on line[]

    for (pos = 0; pos < LIMIT && (c = getchar()) != EOF && c != '\n'; /*incr inside loop*/) {
        // check if c is a valid hex digit. Otherwise, ignore character and go to the next
        if (isdigit(c) || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f')) {
            // checks for '0x' in the first and second loop iteration
            switch (pos) {
                case 0: // if in the first position
                    switch (c) {
                        case '0':   // if the value of the first char is '0', continue
                            line[pos++] = c;
                            break;
                        default:    // if first char is not '0', set str[0] & [1] to '0' and 'x', respectively
                            line[pos++] = '0';
                            line[pos++] = 'x';
                            switch(c) { // ignore any X's after '0x'
                                case 'X':
                                case 'x':
                                    break;
                                default:
                                    line[pos++] = c;
                                    break;
                            } // end of 3rd layer switch
                            break;
                    } // end of 2nd layer switch
                    break;
                case 1: // if user has entered '0' as first char
                    switch (c) {
                        case 'X':
                        case 'x':
                            line[pos++] = c;
                            break;
                        default: // if user did not enter 'x' as the second char
                            line[pos++] = 'x';
                            line[pos++] = c;
                            break;
                    } // end of 2nd layer switch
                    break;
                default: // line positions after "0x"
                    switch(c) {
                        // ignore any X's after "0x"
                        case 'X':
                        case 'x':
                            break;
                        default:
                            line[pos++] = c;
                            break;
                    } // end of 2nd layer switch
                    break;
            } // end of first layer switch
        } // end of if
    } // end of for loop
    line[pos] = '\0'; // insert null terminator
    *len = pos - 1; // value of len is position before null terminator
}

// getNum: returns the sum of all the hex digits within line[] in decimal base 10
unsigned long getNum(char line[], int len) {
    const int       base = 16;
    unsigned long   sum = 0; // stores the sum of each hex digit

    // accumulate sum of each hex digit (base 16), starting from the right end of line[]
    // to decimal base 10
    for(int i = len, basePos = 0; line[i] != 'x' && i >= 0; i--, basePos++) {
        sum += hexToInt(line[i]) * (pow(base, basePos));
    }

    return sum;
}

// hexToInt: converts each hex digit from line[] into its equivalent integer value
int hexToInt(char h) {
    int i = 0;

    // converts hex digits (in type char) to their integer equivalent
    if (h >= '0' && h <= '9')
        i = h - '0';
    else if (h >= 'A' && h <= 'F')
        i = (h - 'A') + 10;
    else if (h >= 'a' && h <= 'f')
        i = (h - 'a') + 10;

    return i;
}
