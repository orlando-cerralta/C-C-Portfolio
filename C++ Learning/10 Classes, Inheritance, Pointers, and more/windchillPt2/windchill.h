// Author:      Orlando Cerralta
// Description: An ADT derived from "temperature.h" which holds operations to calculate the windchill factor.
#pragma once
#include <iostream>
#include "temperature.h"
using namespace std;

enum windspeedUnit_t { MPH, KPH }; // describes the unit of measurement, Mph and Km/h

class windspeed_t
{
public: 
    // MUTATOR FUNCTIONS
    void setSpeed(int sp);
    void setUnit(windspeedUnit_t u);
    void conversion(windspeedUnit_t u);

    // ACCESSOR FUNCTIONS
    int             getSpeed() const;
    windspeedUnit_t getUnit() const;
    void            print(ostream&) const;    
    // CONSTRUCTOR
    windspeed_t(int s = 0, windspeedUnit_t u = KPH);
private:
    int             speed;
    windspeedUnit_t unit;
};

class windchill_t : private windspeed_t, public temperature_t
{
public:
    // MUTATOR FUNCTIONS
    void    setScale(char s); // override
    void    setScale(scale_t s); // override
        // post condition: scale = s, windspeed.unit = KPH (if CELSIUS or KELVIN) or MPH (if FAHR or RANKINE)
    void    conversion(char s); // override
    void    conversion(scale_t s); // override
        // post condition: temperature, scale, and windspeed are converted to corresponding selected values
    void    setWindspeed(int ws);
        // post condition: windspeed = ws, unless ws is less than 0
    void    calculateWindchill();
        // pre  condition: temperature, degree, and windspeed must be set
        // post condition: sets value for windchill
    
    // ACCESSOR FUNCTIONS
    int             getWindspeed() const;
    temperature_t   getWindchill() const;
    void            print(ostream& outF) const; //override
        // pre  condition: all private variables must be set
        // post condition: prints in the form of 
        //          "'temperature' 'degree', Windspeed = 'windspeed''unit', Windchill = 'windchill''scale'"
        //          to desired output
    void            printFrostbiteTime(ostream& outF) const;

    // CONSTRUCTORS
    windchill_t(double temp = 0.00, scale_t s = CELSIUS, int ws = 0);
    windchill_t(scale_t s, double temp = 0.00, int ws = 0);
    windchill_t(char s, double temp = 0.00, int ws = 0);
private:
    void assignWSUnit(scale_t sc); // sets windspeed unit corresponding to scale

    windspeed_t     windspeed;  // holds windspeed (in MPH for fahrenheit / kmph for celcius)
    temperature_t   windchill;  // holds windchill factor based on scale degree
};
