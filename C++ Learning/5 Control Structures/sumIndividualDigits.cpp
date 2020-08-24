// Author: Orlando Cerralta
// Date: 7/18/2020
// Description: This program recieves an integer from the user and
//              adds the individual digits. 
//              For example, int = '12345' would be calculated as
//              '1 + 2 + 3 + 4 + 5' and the sum would equal '15'.
//              If the user enters a negative number such as '-98765',
//              it will be converted to positive and calculated as
//              '9 + 8 + 7 + 6 + 5' and the sum would equal '35'.
#include <iostream>

using namespace std;

int main() 
{
    // declare and initialize variables
    int num = 0, sum = 0, numOfDigits = 0;
    int digit, temp;                // temp will be a placeholder for num and numOfDigits

    // introduction
    cout << "This program takes an integer and finds the sum of each individual digit!" << endl;
    // prompt the user for num
    cout << "Enter an integer: ";
    cin >> num;
    // check for input failure
    while (!cin) 
    {
        cin.clear();
        cin.ignore(100, '\n');
        
        cout << "Error, please enter an integer: ";
        cin >> num;
    }

    // if num is a negative number, convert to positive
    if (num < 0) 
    {
        num *= -1;
    }

    // find the number of digits there are by removing each digit with division of 10 each loop
    temp = num;
    while (temp > 0) 
    {
        temp /= 10;
        numOfDigits++;
    }

    sum = 0; // set sum to zero
    temp = numOfDigits; // reuse temp to hold the value of numOfDigits
    //  find each digit and calculate the sum
    for (int i = 0; i < numOfDigits; i++) 
    {
        // this nested for loop finds each digit starting from left to right 
        //  but stops before the right most digit in order
        //  for variable'digit' to not equal zero from the division operation
        digit = num;
        for (int position = temp; position > 1; position--)
        {
            digit /= 10;            // divides by ten, 'position' number of times
        }
        temp--;                     // goes to the next digit position for the nested loop
        
        // output digit
        digit %= 10;                // finds the remainder of the right most position
        cout << digit << " ";       // output current digit
        sum += digit;               // accumulate sum
    }
    
    // in case num is zero and skipped through loops, output zero
    switch (num) 
    {
        case 0:
            cout << "0";
            break;
        default:
            break;
    }
    // output sum
    cout << ", Sum = " << sum << endl;

    return 0;
}
