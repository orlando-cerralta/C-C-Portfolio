// Author: Orlando Cerralta
// Date: 08/20/2020
// Program: User inputs a sequence of characters until the newline,
//          the program will then output the number of vowels enter from the line
#include <iostream>

using namespace std;

void readInput(int& numbOfChars, int& vowels, int& y);
void isVowel(char ch, int& numOfVowels, int& numOfY);
void results(int numOfLetters, int totalVowels, int totalY);

int main() {
    int totalChars = 0; // stores the number of characters entered by the keyboard
    int vowels = 0;     // stores the total vowels including Y's
    int y = 0;          // stores the total number of Y's entered

    cout << "This program takes a sequence of characters from the keyboard until the user presses <Enter>" << endl;
    cout << "The program will then display the total number of vowels and letter Y's entered!" << endl;
    cout << "Enter line: ";
    readInput(totalChars, vowels, y);
    
    cout << endl;
    results(totalChars, vowels, y);

    return 0;
}

// reads each character the user enters until the newline, calls function checkVowels()
// to count the number of vowels and letter Y's entered
void readInput(int& numOfChars, int& vowels, int& y) {
    char c;

    // read chars and check for vowels and Ys
    for(numOfChars = 0; (c = cin.get()) != '\n'; numOfChars++) {
        isVowel(c, vowels, y);
    }
}

// increments number of vowels and Y's, if entered
void isVowel(char ch, int& numOfVowels, int& numOfY) {
    switch(ch) {
        // UPPERCASE
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
        // lowercase
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            numOfVowels++;
            break;
        // sometimes Y
        case 'Y':
        case 'y':
            numOfVowels++;
            numOfY++;
            break;
        // else
        default:
            break;
    }
}

// displays dedicated results according to the number of vowels and Y's there are
void results(int numOfLetters, int totalVowels, int totalY) {
    cout << "Total Characters: " << numOfLetters << endl;

    // checks for plural
    switch(totalVowels) {
        case 1:
            cout << "There was " << totalVowels << " vowel";
            break;
        default:
            cout << "There were " << totalVowels << " vowels";
            break;
    }

    cout << " and ";

    // decides the correct grammar to end sentence
    switch(totalY) {
        case 0:
            cout << totalY << " Y's.";
            break;
        default:
            if(totalVowels == 1 && totalY == 1)
                cout << "it was a Y!";
            else if (totalVowels == totalY)
                cout << "they were Y's.";
            else if (totalY == 1)
                cout << totalY << " of them was a Y.";
            else
                cout << totalY << " of them were Y's!";
            break;
    }
    cout << endl;
}
