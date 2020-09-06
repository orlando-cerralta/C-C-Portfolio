// Author:  Orlando Cerralta
// Date:    09/05/2020
// Program: Removes all vowels from a string entered by the user using substr()
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// prototypes
bool    checkChoice(char choice);   // checks decision to continue program
bool    isVowel(char c);            // checks if letter is a vowel
void    searchLine(string line, int& pos, bool& vowelFound);    // searches for first instance of vowel in line
string  removeVowels(string line);  // removes vowels from line, then returns the altered line

int main() {
    string  str;            // holds original string entered by the user
    string  strNoVowels;    // holds the altered string that doesnt contain vowels
    char    choice;

    cout << "This program removes vowels from a string entered by the keyboard!" << endl;
    cout << "Would you like to try? (y/n): ";
    cin >> choice;
    while(checkChoice(choice)) {
        cin.ignore(100, '\n'); // clear input stream for getline
        cout << "Enter string: ";
        getline(cin, str);

        // remove vowels
        strNoVowels = removeVowels(str);

        // output and ask to retry
        cout << endl;
        cout << setw(17) << "Original: \"" << str << "\"" << endl 
            << setw(17) << "Without vowels: \"" << strNoVowels << "\"" << endl;
        cout << endl;
        cout << "Would you like to go again? (y/n): ";
        cin >> choice;
    };

    
    return 0;
}

// checkChoice: checks if choice is valid, if not enter choice again
bool checkChoice(char choice) {
    bool validChoice = false;

    while(!validChoice) {
        switch(choice) {
            case 'Y':
            case 'y':
                return true;    // continue program
            case 'N':
            case 'n':
                return false;   // quit program
            default:            // else, enter choice again
                cout << "Please enter either 'y' to continue program or 'n' to quit: ";
                cin.ignore(100, '\n');  // ignore other chars from stream to prevent spam of prompts
                cin >> choice;
                break;
        }   
    };
    return false;
}

// isVowel: checks if passed letter is a vowel
bool isVowel(char c) {
    switch(c) {
        // UPPERCASE
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
        case 'Y':
        // lowercase
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'y':
            return true;
        default:
            return false;
    }
}

// searchLine: scrolls through each letter in 'line' until a vowel is found, otherwise exit with no vowels
void searchLine(string line, int& pos, bool& vowelFound) {
    vowelFound = false;

    // search through line
    for (int i = 0; i < static_cast<int>(line.length()); i++) {
        if (isVowel(line[i])) {
            pos = i;
            vowelFound = true;
        }
    }

    return;
}

// removeVowels: removes vowels from line then returns line without vowels
string removeVowels(string line) {
    const int   firstLetter = 0;    // holds the position of the first letter in 'line'
    int         pos = -1;           // holds the position of found vowel
    bool        vowelsLeft = true;  // Loop Control Var, value is based on whether there are any vowels lefts in 'line'
    int         len;                // holds the length of chars in string

    // loop until there are no vowels left or there are no letters in 'line'
    while (vowelsLeft == true && static_cast<int>(line.length()) > 0) {
        len = static_cast<int>(line.length()); // hold current iteration of length
        
        // if first letter is a vowel
        if (isVowel(line[firstLetter]))
            line = line.substr(firstLetter + 1, len - 1);
        // if last letter is a vowel
        else if (isVowel(line[len - 1]))
            line = line.substr(firstLetter, len - 1);
        else {
            do {
                searchLine(line, pos, vowelsLeft); // check if vowel is inside line
                if (vowelsLeft == true) { // if vowel is inside line
                    // preserve letters around position
                    line = line.substr(firstLetter, pos) + line.substr(pos + 1, len - 1);
                }
            } while (vowelsLeft == true);
            // out of do.. while loop, no more vowels left
        }
    }
    return line;
}
