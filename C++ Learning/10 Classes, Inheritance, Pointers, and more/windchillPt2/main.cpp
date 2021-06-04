// Author:  Orlando Cerralta
// Date:    05/30/21
// Program: This is an upgraded version of my windchillFactor.cpp program, this time using classes.
//          Calculates the Windchill Factor given the temperature, scale, and windspeed.
// Focus:   Understanding the use of classes and derived classes, pointer dereferencing and the 'this' reserved word.
// Sources: Environment & Climate Change Canada
#include <iostream>
#include "windchill.h"

using namespace std;

void getTemperature(windchill_t &wc);
void getDegree(windchill_t &wc);
void getWindspeed(windchill_t &wc);

int main() 
{
    windchill_t wc;
    
    cout << "It can get really cold during Winter," << endl
        << "  this program helps calculate the Windchill Factor before heading out!" << endl;
    cout << endl;

    // Recieve data
    getTemperature(wc);
    getDegree(wc);
    getWindspeed(wc);
    
    // Calculate
    wc.calculateWindchill();
    
    // Output data
    wc.print(cout);
    cout << endl;
    wc.printFrostbiteTime(cout);
    cout << endl;

    return 0;
}

void getTemperature(windchill_t &wc)
{
    double temp;

    // get temperature
    cout << "Enter the temperature: ";
    cin >> temp;
    wc.setTemperature(temp);

    return;
}

void getDegree(windchill_t &wc)
{
    char d;

    cout << "Enter the scale [(C)elsius, (F)ahrenheit, (K)elvin, or (R)ankine]: ";
    cin >> d;
    // check for input failure
    while(!cin) 
    {
        cin.clear();
        cin.ignore(100, '\n');
        
        cout << "Invalid character, choose 'C', 'F', 'K', or 'R': ";
        cin >> d;
    }
    wc.setScale(d);
    cin.ignore(100, '\n'); // remove leftover characters, if any
    
    return;
}

void getWindspeed(windchill_t &wc)
{
    int ws;

    cout << "Enter the windspeed ";
    switch(wc.getScale())
    {
        case CELSIUS:
        case KELVIN:
            cout << "in Km/h ";
            break;
        case FAHRENHEIT:
        case RANKINE:
            cout << "in MPH ";
            break;
    }
    cout << "(must be greater than 5): ";
    cin >> ws;
    wc.setWindspeed(ws);
    return;
}
