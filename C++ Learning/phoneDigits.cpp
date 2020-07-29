// Author: Orlando Cerralta
// Date: 7/27/2020
// Description: This program converts a character inputted by the 
//              user and outputs the corresponding telephone digit
#include <iostream>

using namespace std;

// function prototypes
int findPhoneDigit(char letter);
void outDigit(int number);

int main() {
    // declare variables
    char letter;
    int digit;

    // introduction prompt
    cout << "This program takes a character as input and "
        << "outputs the corresponding telephone digit" << endl;

    // prompt the user to enter a character
    cout << "Enter a letter: ";
    cin.get(letter);

    // enters function to find digit
    digit = findPhoneDigit(letter);

    // output the digit
    cout << endl;
    outDigit(digit);
   
    return 0;
}

// This function finds the corresponding phone digit
int findPhoneDigit(char letter) {
    int number = -1;

    switch(letter) {
        case 'A':
        case 'a':
        case 'B':
        case 'b':
        case 'C':
        case 'c':
            number = 2;
            break;
        case 'D':
        case 'd':
        case 'E':
        case 'e':
        case 'F':
        case 'f':
            number = 3;
            break;
        case 'G':
        case 'g':
        case 'H':
        case 'h':
        case 'I':
        case 'i':
            number = 4;
            break;
        case 'J':
        case 'j':
        case 'K':
        case 'k':
        case 'L':
        case 'l':
            number = 5;
            break;
        case 'M':
        case 'm':
        case 'N':
        case 'n':
        case 'O':
        case 'o':
            number = 6;
            break;
        case 'P':
        case 'p':
        case 'Q':
        case 'q':
        case 'R':
        case 'r':
        case 'S':
        case 's':
            number = 7;
            break;
        case 'T':
        case 't':
        case 'U':
        case 'u':
        case 'V':
        case 'v':
            number = 8;
            break;
        case 'W':
        case 'w':
        case 'X':
        case 'x':
        case 'Y':
        case 'y':
        case 'Z':
        case 'z':
            number = 9;
            break;
        case ' ':
        case '&':
        case '\'':
        case '(':
        case ',':
        case '@':
        case '_':
            number = 1;
            break;
        case '+':
            number = 0;
            break;
        default:
            break;
    }
    return number;
}

// simply outputs the phone digit, unless otherwise
void outDigit(int number) {
    switch (number) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            cout << "Phone Digit: " << number << endl;
            break;
        default:
            cout << "This character has no corresponding digit" << endl;
            break;
    }
}
