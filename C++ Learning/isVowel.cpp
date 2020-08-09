// Author: Orlando Cerralta
// Date: 08/08/2020
// Description: This program takes in a letter from the keyboard
//              and checks if it is a vowel or not
#include <iostream>

using namespace std;

// prototype
void isVowel(char x); // check and prints whether letter is or isn't a vowel

int main() {
    char letter, choice;

    // introduction
    cout << "This program reads a letter from the keyboard and "
        << "checks if it is a vowel or not." << endl;
    // user choice to run program or exit if user enters 'N' or 'n'
    cout << "Would you like to continue program? (y/n): ";
    do {
        cin >> choice;
        switch (choice) {
            case 'Y':
            case 'y':
                cout << "Please enter a letter: ";
                cin >> letter;
                cout << endl;

                isVowel(letter); // check and print result

                cin.ignore(100, '\n'); // ignore other chars if user entered a string
                cout << "Would you like to try again? (y/n): ";
                break;
            case 'N':
            case 'n':
                // exit loop
                break;
            default:
                cout << "Whoops, please enter 'y' or 'n': ";
                cin.ignore(100, '\n'); // if user enters a string of characters
                                        // ignore so the screen wont be filled with spam
                break;               
        }
    } while(choice != 'N' && choice != 'n');

    return 0;
}

// check letter if it is a vowel
void isVowel(char x) {
    switch(x) {
        // uppercase
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
            cout << x << " is a vowel!" << endl;
            cout << endl;
            break;
        // sometimes y
        case 'Y':
        case 'y':
            cout << x << " is sometimes a vowel." << endl;
            cout << endl;
            break;
        // else
        default:
            if ((x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z'))
                cout << x << " is not a vowel." << endl;
            else // if user enters anything other than a letter
                cout << x << " is not an alphabetical letter." << endl;

            cout << endl;
            break;
    }
    return;
}
