// Author:  Orlando Cerralta
// Date:    09/01/2020
// Program: Prompts the user for the length of 3 sides of a triangle
//          then judges whether it is an isosceles, scalene, equilateral
//          or not a triangle
#include <iostream>
#include <string>

using namespace std;

// enum triangleType 
enum triangleType { 
    noTriangle, scalene, isosceles, equilateral 
};

// constant
const double NO_LENGTH_SET = -1.0;

// prototypes
void            initializeSides(double& a, double& b, double& c);
triangleType    triangleShape(double a, double b, double c); // finds triangle type using length of sides given
string          printTriangle(triangleType t);  // prints triangle type as string

int main() {
    double side1, side2, side3;
    triangleType triangle;
    initializeSides(side1, side2, side3);

    cout << "This program recieves the length of each side of a triangle, "
        << "then figures out the type of triangle entered!" << endl;
    cout << "Enter the length of each side of the triangle: ";
    // loop if user enters input failure or enters a negative number as a side
    do {
        cin >> side1 >> side2 >> side3;
        // first, check if entered input failure
        if (!cin) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << endl << "Error, please enter the length of each side again: ";
            // reset value of sides to prevent user from prematurely exiting loop 
            //      due to side effects of clearing input failure
            initializeSides(side1, side2, side3);
        }
        // otherwise, check if the user inputs a negative number
        else if (side1 < 0 || side2 < 0 || side3 < 0) {
            cout << endl << "Side can't be a negative number. Please try again." << endl
                << "Enter the length of each side of the triangle: ";
        }
    } while ((side1 < 0) || (side2 < 0) || (side3 < 0));

    // find triangle type
    triangle = triangleShape(side1, side2, side3);

    // output triangle type
    cout << endl;
    cout << "Triangle type: " << printTriangle(triangle) << endl;
    return 0;
}

// initializes length of side
void initializeSides(double& a, double& b, double& c) {
    a = NO_LENGTH_SET;
    b = NO_LENGTH_SET;
    c = NO_LENGTH_SET;
    return;
}

// triangleShape: finds the type of triangle
triangleType triangleShape(double a, double b, double c) {
    triangleType t;

    // no triangle
    if (a == 0 || b == 0 || c == 0)
        t = noTriangle;
    // equilateral
    else if (a == b && b == c)
        t = equilateral;
    // isosceles
    else if (a == b || b == c || c == a)
        t = isosceles;
    // scalene
    else
        t = scalene;

    return t;
}

// printTriangle: prints the type of triangle as string
string printTriangle(triangleType t) {
    string strTriangle;

    switch(t) {
        case noTriangle:
            strTriangle = "No triangle";
            break;
        case equilateral:
            strTriangle = "Equilateral";
            break;
        case isosceles:
            strTriangle = "Isosceles";
            break;
        case scalene:
            strTriangle = "Scalene";
            break;
    }

    return strTriangle;
}
