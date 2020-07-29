// Author: Orlando Cerralta
// Date: 07/28/2020
// Description: This program takes in seven letters, then translates 
//              those letters into digits of a phone number.
//              For example, "GET LOAN" would be 438-5626 or
//              CALL NOW to 225-5669
#include <iostream>
#include <cmath>

using namespace std;

// function prototypes
bool    checkLetter(char letter);
int     letterToDigit(char letter);
int     orderNumber(int digit, int digitPlace);
void    printDigits(int number);

int main() {
    // declare variables
    char    letter;
    int     digit;
    int     number = 0;     // stores each digit in a certain way
    bool    validLetter;    // flag control variable

    // introduction prompt
    cout << "Welcome, this program takes seven letters "
        << "and converts them to a phone number" << endl;

    // prompt the user for letters
    cout << "Please enter 7 letters: ";
    for (int count = 0; count < 7; count++) {
        validLetter = false; // set flag
        // recieve char input then check if user entered a valid character
        do {
            cin >> letter;
            validLetter = checkLetter(letter);
        } while(!validLetter);  // if valid letter is true, exit loop

        digit = letterToDigit(letter);
        number += orderNumber(digit, count); // depending on the place of each digit, the
                                            // function will organize each digit in a specific
                                            // base 10 position, then accumulates variable 'number'
    }

    // print the phone number
    cout << "Your number is: ";
    printDigits(number);

    return 0;
}

// function for flag controlled for do... while loop
bool checkLetter(char letter) {
    // if within ascii char value range for both upper and lower case, return true
    if ((letter >= 'A' && letter <= 'Z') || (letter >= 'a' && letter <= 'z'))
        return true;
    else {
        cout << "Invalid letter, try again: ";
        return false;
    }
}

// function converts alphabetical letter to phone digit
int letterToDigit(char letter) {
    int digit;
    switch(letter) {
        case 'A':
        case 'a':
        case 'B':
        case 'b':
        case 'C':
        case 'c':
            digit = 2;
            break;
        case 'D':
        case 'd':
        case 'E':
        case 'e':
        case 'F':
        case 'f':
            digit = 3;
            break;
        case 'G':
        case 'g':
        case 'H':
        case 'h':
        case 'I':
        case 'i':
            digit = 4;
            break;
        case 'J':
        case 'j':
        case 'K':
        case 'k':
        case 'L':
        case 'l':
            digit = 5;
            break;
        case 'M':
        case 'm':
        case 'N':
        case 'n':
        case 'O':
        case 'o':
            digit = 6;
            break;
        case 'P':
        case 'p':
        case 'Q':
        case 'q':
        case 'R':
        case 'r':
        case 'S':
        case 's':
            digit = 7;
            break;
        case 'T':
        case 't':
        case 'U':
        case 'u':
        case 'V':
        case 'v':
            digit = 8;
            break;
        case 'W':
        case 'w':
        case 'X':
        case 'x':
        case 'Y':
        case 'y':
        case 'Z':
        case 'z':
            digit = 9;
            break;
    }
    return digit;

}

// this function orders each digit in corresponding base 10 position
// for example, 1st digit will be in the ones place, second digit in
// the tens place, 3rd digit in the hundreds place, and so on
int orderNumber(int digit, int digitPlace) {
    switch(digitPlace) {
        case 0:     // ignore the first digit
            break;
        default:    // set the rest of the numbers in their corresponding place
            digit = digit * pow(10.0, digitPlace);
    }
    return digit;
}

// function prints each digit
void printDigits(int number) {
    for (int count = 0; count < 7; count++) {
        // places '-' between the third and fourth digit
        switch (count) {
            case 3:
                cout << "-";
                break;
        }
        cout << (number % 10); // display current digit
        number = number / 10; // delete current digit and go to the next
    }
    cout << endl;
}
