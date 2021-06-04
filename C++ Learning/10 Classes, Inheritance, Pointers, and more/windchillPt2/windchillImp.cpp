// Author:      Orlando Cerralta
// Description: Implementation file for "windchill.h"
#include <iostream>
#include <cmath>
#include "temperature.h"
#include "windchill.h"
using namespace std;

// CLASS WINDSPEED_T
// CONSTRUCTOR
windspeed_t::windspeed_t(int s, windspeedUnit_t u)
{
    if (s > 0)
        speed = s;
    else
        speed = 0;

    unit = u;

    return;
}

// MUTATOR FUNCTIONS
void windspeed_t::setSpeed(int sp)
{
    if (sp > 0)
        speed = sp;
    else
        speed = 0;

    return;
}

void windspeed_t::setUnit(windspeedUnit_t u)
{
    unit = u;
    return;
}

void windspeed_t::conversion(windspeedUnit_t u)
{
    const double ratio = 1.609; // conversion ratio
    
    // check if converting to already assigned unit
    if (unit == u)
        ; // null
    else
    {
        // convert to...
        switch(u)
        {
            case MPH:
                speed *= ratio;
                break;
            case KPH:
                speed /= ratio;
                break;
        }
        unit = u;
    }
    return;
}

// ACCESSOR FUNCTIONS
int windspeed_t::getSpeed() const
{
    return speed;
}

windspeedUnit_t windspeed_t::getUnit() const
{
    return unit;
}

void windspeed_t::print(ostream& outF) const
{
    outF << speed;

    switch(unit)
    {
        case MPH:
            outF << "mph";
            break;
        case KPH:
            outF << "km/h";
            break;
    };

    return;
}

// CLASS WINDCHILL_T
// CONSTRUCTORS
windchill_t::windchill_t(double temp, scale_t s, int ws) 
    : windspeed_t(ws), temperature_t(temp, s)
{
    assignWSUnit(getScale());
    windchill = 0.00;
    return;
}

windchill_t::windchill_t(scale_t s, double temp, int ws)
    : windspeed_t(ws), temperature_t(s, temp)
{
    assignWSUnit(getScale());
    windchill = 0.00;
    return;
}

windchill_t::windchill_t(char s, double temp, int ws)
    : windspeed_t(ws), temperature_t(s, temp)
{
    assignWSUnit(getScale());
    windchill = 0.00;
    return;
}


// MUTATOR FUNCTIONS
void windchill_t::setScale(char s)
{
    temperature_t::setScale(s);
    assignWSUnit(getScale());
    return;
}

void windchill_t::setScale(scale_t s)
{
    temperature_t::setScale(s);
    assignWSUnit(getScale());
    return;
}

void windchill_t::conversion(char s)
{
    temperature_t::conversion(s);
    assignWSUnit(getScale());
    return;
}

void windchill_t::conversion(scale_t s)
{
    temperature_t::conversion(s);
    assignWSUnit(getScale());
    return;
}

void windchill_t::setWindspeed(int ws)
{
    if (ws > 5)
        windspeed.setSpeed(ws);
    else
        windspeed.setSpeed(5);

    return;
}

void windchill_t::calculateWindchill()
{
    double          convT;  // temporarily holds converted temperature
    temperature_t   wcTemp = *this; // copies temperature values of 'this' to later hold windchill temperature
    windspeed_t     ws = windspeed; // copies windspeed values
    
    // check if scale is an Absolute scale, if so convert to corresponding common scale
    switch(wcTemp.getScale())        
    {
        // in km/h
        case KELVIN:
            wcTemp.conversion(CELSIUS);
        case CELSIUS:
            // calculate using formula: Winchill = 13.12 + 0.6215 * T - 11.37 * (V^0.16) 
            //                          + 0.3965 * T * (V^0.16)
            convT =  13.12 + (0.6215 * wcTemp.getTemperature()) - (11.37 * pow(ws.getSpeed(), 0.16))
                    + (0.3965 * wcTemp.getTemperature()) * pow(ws.getSpeed(), 0.16);
            break;
        // in mph
        case RANKINE:
            wcTemp.conversion(FAHRENHEIT);
        case FAHRENHEIT:
            // calculate using formula: Windchill = 35.74 + 0.6215 * T - 35.75(V^0.16)
            //                          + 0.4275 * T * (V^0.16)
            convT =  35.74 + (0.6215 * wcTemp.getTemperature()) - (35.75 * pow(ws.getSpeed(), 0.16))
                    + (0.4275 * wcTemp.getTemperature()) * pow(ws.getSpeed(), 0.16);
            break;
    };
    // store windchill temperature
    wcTemp.setTemperature(convT);
    // if scale was originally not Celsius or Fahr., convert back to original scale
    wcTemp.conversion(getScale());
    
    // set values for windchill and windspeed
    windchill.setTemperature(wcTemp.getTemperature());
    windchill.setScale(wcTemp.getScale());

    return;
} // end of calculateWindchill()


// ACCESSOR FUNCTIONS
int windchill_t::getWindspeed() const
{
    return windspeed.getSpeed();
}

temperature_t windchill_t::getWindchill() const
{
    return windchill;
}

void windchill_t::print(ostream& outF) const
{
    temperature_t::print(outF);
    outF << ", Windspeed: ";
    windspeed.print(outF);
    outF << ", ";
    switch(getScale())
    {
        case KELVIN:
        case RANKINE:
            outF << "Approximate ";
        case CELSIUS:
        case FAHRENHEIT:
            outF << "Windchill: ";
            break;
    }
    windchill.print(outF);
    return;
}

// display frostbite risk and time, based on studies from Environment Canada / Toronto, Canada
void windchill_t::printFrostbiteTime(ostream& outF) const
{
    temperature_t temp;
    int wc; // holds windchill temperature in Celsius

    // make sure windchill scale is in celsius
    if (windchill.getScale() == CELSIUS)
        wc = static_cast<int>(windchill.getTemperature());
    else
    {
        temp = windchill;
        temp.conversion(CELSIUS);
        wc = static_cast<int>(temp.getTemperature());
    }

    if (wc > 0)
        outF << "You're good to go! No risk of frostbite.";
    else if (wc <= 0 && wc >= -9)
        outF << "Dress warmly, low risk of frostbite.";
    else if (wc < -9 && wc >= -27)
        outF << "Wear layers of warm clothing, moderate risk of frostbite.";
    else if (wc < -27 && wc >= -39)
        outF << "Cover exposed skin. High risk of frostbite, 10 - 30 minutes!";
    else if (wc < -39 && wc >= -47)
        outF << "Cover all exposed skin. Very high risk of frostbite, 5 - 10 minutes!";
    else if (wc < -47 && wc >= -54) {
        outF << "Cover all exposed skin and possibly cancel plans outside. " << endl
            << "Severe risk of frostbite, 2 - 5 minutes!!";
    }
    else
        outF << "Stay indoors. Extreme risk of frostbite, less than 2 minutes...";

    return;
} // end of printFrostbiteTime()


// PRIVATE FUNCTIONS

// assignWSUnit: sets appropriate windspeed unit depending on the scale
void windchill_t::assignWSUnit(scale_t sc)
{
    switch(sc)
    {
        case CELSIUS:
        case KELVIN:
            windspeed.setUnit(KPH);
            break;
        case FAHRENHEIT:
        case RANKINE:
            windspeed.setUnit(MPH);
            break;
    }
    return;
}
