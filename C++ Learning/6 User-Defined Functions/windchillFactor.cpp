// Author: Orlando Cerralta
// Date: 08/23/2020
// Program: Calculates the Windchill Factor given the windspeed in MPH and
//          temperature in degrees Fahrenheit
// Sources: Environment & Climate Change Canada
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// prototypes
void    getWindspeed(int& ws);
void    getTemperature(int& temp);
char    getDegree();                        // finds whether temp is F or C
void    getWindchill(int ws, int t, char deg, double& wcFahr, double& wcCelc);
double  celciusToFahr(double wcCelc);       // converts celcius to fahrenheit
double  fahrToCelcius(double wcFahr);       // converts fahrenheit to celcius
void    displayFrostbiteTime(double wc);

int main() {
    char    degree = ' '; // user chooses 'F' or 'C'
    int     windspeed, temperature;
    double  wcFahr, wcCelc;

    cout << "It can get really cold during Winter," << endl 
        << "\tthis program helps calculate the Windchill Factor before heading out" << endl;
    cout << endl;
    
    getTemperature(temperature);
    degree = getDegree();
    getWindspeed(windspeed);

    // get windchill in both fahr and celcius
    getWindchill(windspeed, temperature, degree, wcFahr, wcCelc);

    cout << fixed << setprecision(1);
    cout << " - - - - - - - - - - - - - - - " << endl;
    cout << "Windchill Factor: " << wcFahr << "F* / " << wcCelc << "C*" << endl;

    displayFrostbiteTime(wcCelc);
    
    return 0;
}

void getWindspeed(int& ws) {
    cout << "Windspeed is in mph when using Fahrenheit or km when using Celcius" << endl;
    do {
        cout << "Enter windspeed: ";
        cin >> ws;
        // check input failure
        while(!cin) {
            cin.clear();
            cin.ignore(100, '\n');

            cout << "Invalid input, enter windspeed: ";
            cin >> ws;
        }
        // check if user entered negative number
        if (ws < 0) 
            cout << "Can't go negative mph or km. Try again." << endl;
    } while(ws < 0); 
    return;
}

void getTemperature(int& temp) {
    cout << "Enter temperature number: ";
    cin >> temp;
    // input failure
    while(!cin) {
        cin.clear();
        cin.ignore(100, '\n');

        cout << "Error, enter temperature: ";
        cin >> temp;
    }
    return;
}

// prompts the user to choose fahr or celcius
char getDegree() {
    char d;
    
    cout << "Now is this in Fahrenheit or Celcius? (F / C): ";
    do {
        cin >> d;
        // check input failure
        while(!cin) {
            cin.clear();
            cin.ignore(100, '\n');

            cout << "Invalid character, choose 'F' or 'C': ";
            cin >> d;
        }
        // check if user entered valid choice
        switch(d) {
            case 'f':
            case 'F':
            case 'c':
            case 'C':
                break;
            default:
                cout << "Invalid letter, choose 'F' or 'C': ";
                cin.ignore(100, '\n'); // ignore char string, if entered, to prevent spam
                break;
        }

    } while (d != 'f' && d != 'F' && d != 'c' && d != 'C');
    
    return d;
}

// calculate windchill factor
void getWindchill(int ws, int temp, char deg, double& wcFahr, double& wcCelc) {
    switch(deg) {
        // Celcius
        case 'c':
        case 'C':
            // windchill formula for celcius
            wcCelc = 13.2 + 0.6215 * temp - 11.37 * pow(ws, 0.16) + 0.3965 * temp * pow(ws, 0.16);
            // conversion
            wcFahr = celciusToFahr(wcCelc);
            break;
        // Fahrenheit
        case 'f':
        case 'F':
            // windchill formula for fahrenheit
            wcFahr = 35.74 + 0.6215 * temp - 35.75 * pow(ws, 0.16) + 0.4275 * temp * pow(ws, 0.16);
            // conversion
            wcCelc = fahrToCelcius(wcFahr);
            break;
    }
    return;
}

// calculates Fahrenheit equivalent for windchill
double celciusToFahr(double cel) {
    double fahrenheit;

    fahrenheit = (cel * (9.0 / 5.0)) + 32.0; // conversion formula

    return fahrenheit;
}

// calculates Celcius equivalent for windchill
double fahrToCelcius(double fahr) {
    double celcius;

    celcius = (fahr - 32.0) * (5.0 / 9.0);  // conversion formula

    return celcius;
}

// display frostbite risk and time, based on studies from Environment Canada / Toronto, Canada
void displayFrostbiteTime(double wc) {
    if (wc > 0)
        cout << "You're good to go! No risk of frostbite." << endl;
    else if (wc <= 0 && wc >= -9)
        cout << "Dress warmly, low risk of frostbite." << endl;
    else if (wc < -9 && wc >= -27)
        cout << "Wear layers of warm clothing, moderate risk of frostbite." << endl;
    else if (wc < -27 && wc >= -39)
        cout << "Cover exposed skin. High risk of frostbite, 10 - 30 minutes!" << endl;
    else if (wc < -39 && wc >= -47)
        cout << "Cover all exposed skin. Very high risk of frostbite, 5 - 10 minutes!" << endl;
    else if (wc < -47 && wc >= -54) {
        cout << "Cover all exposed skin and possibly cancel plans outside. " << endl
            << "Severe risk of frostbite, 2 - 5 minutes!!" << endl;
    }
    else
        cout << "Stay indoors. Extreme risk of frostbite, less than 2 minutes..." << endl;

}
