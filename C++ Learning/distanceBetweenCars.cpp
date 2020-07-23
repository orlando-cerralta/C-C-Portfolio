// Name: Orlando Cerralta
// Date: 7/23/2020
// Description: This program calculates the shortest distance between two vehicles after a certain amount of time
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const int IGNORE_LIMIT = 100;
const double ONE_HOUR = 60.00;

int main()
{
    // 'mphA' and 'mphB' represent the mph for vehicles A and B, respectively.
    int mphA = 0, mphB = 0;
    int hours, minutes;
    // distance represents the shortest distance apart between the two vehicles after the elapsed time, the rest of the variables are for calculations.
    double distance, distanceSquared, minsToHours, time, carA, carB;

    // Introduction
    cout << "Two cars, A and B, leave an intersection at the same time." << endl;
    cout << "Car A travels West and Car B travels South from the intersection." << endl;
    cout << endl;

    // prompt the user for the mph of the two vehicles and the elapsed time
    // Car A
    cout << "Enter the mph Car A is travelling: ";
    cin >> mphA;
    // input failure
    while (!cin) 
    {
        cin.clear();
        cin.ignore(IGNORE_LIMIT, '\n');
        cout << "Error, try again." << endl;
        cout <<"Enter the mph Car A is travelling: ";
        cin >> mphA;
    }
    // Car B
    cout << "Enter the mph Car B is travelling: ";
    cin >> mphB;
    while (!cin) 
    {
        cin.clear();
        cin.ignore(IGNORE_LIMIT, '\n');
        cout << "Error, try again." << endl;
        cout << "Enter the mph Car B is travelling: ";
        cin >> mphB;
    }
    // Elapsed Time
    cout << "For the elapsed time, use a space in between the hours and minutes. (ex. 1 hour and 30 minutes would be '1 30')" << endl;
    cout << "Elapsed time: ";
    cin >> hours >> minutes;
    while (!cin) 
    {
        cin.clear();
        cin.ignore(IGNORE_LIMIT, '\n');
        cout << "Error, try again." << endl;
        cout << "For the elapsed time, use a space inbetween the hours and minutes (ex. 1 hour and 30 minutes would be '1 30')" << endl;
        cout << "Elapsed time: ";
        cin >> hours >> minutes;
    }

    // Calculations
    minsToHours = minutes / ONE_HOUR;   // converts minutes to decimal form
    time = hours + minsToHours;
    // Find distance
    carA = mphA * time;
    carB = mphB * time;
    // Using the pythagorean theorum to calculate the shortest distance apart
    distanceSquared = pow(carA, 2.0) + pow(carB, 2.0);
    distance = sqrt(distanceSquared);

    // Output
    cout << " - - - - -" << endl;
    cout << fixed << showpoint << setprecision(2);
    cout << "The shortest distance apart between Car A and Car B is " << distance << " miles!" << endl;

    return 0;
}
