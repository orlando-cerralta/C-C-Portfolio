// Author:      Orlando Cerralta
// Description: Implementation file for "temperature.h"
#include <iostream>
#include <iomanip>
#include "temperature.h"
using namespace std;

// MUTATOR FUNCTIONS
void temperature_t::setTemperature(double t) 
{
    temperature = t;
    return;
}

void temperature_t::setScale(char s) 
{
    assignScale(s, scale);
    return;
}

void temperature_t::setScale(scale_t s) // overloaded function
{
    scale = s;
    return;
}

void temperature_t::conversion(char s) 
{
    scale_t sScale = CELSIUS;

    // assign appropriate scale for sScale
    assignScale(s, sScale);

    conversion(sScale); // goes to overloaded function with parameter of type scale_t
    return;
}

void temperature_t::conversion(scale_t sc) // overloaded function 
{
    // check if converting to already assigned scale
    switch(scale == sc)
    {
        case true:
            return;
        case false:
            break;
    };      

    // assign conversion to 'this' object
    switch (scale) 
    {
        case CELSIUS:
            *this = celsiusConversions(sc);
            break;
        case FAHRENHEIT:
            *this = fahrConversions(sc);
            break;
        case KELVIN:
            *this = kelvinConversions(sc);
            break;
        case RANKINE:
            *this = rankineConversions(sc);
            break;
    };

    return;
}


// ACCESSOR FUNCTIONS

double temperature_t::getTemperature() const 
{
    return temperature;
}

scale_t temperature_t::getScale() const
{
    return scale;
}

// print: prints temperature and symbol to desired output
void temperature_t::print(ostream& outF) const
{
    outF << fixed << setprecision(2);
    outF << temperature << " ";

    switch(scale)
    {
        case CELSIUS:
            outF << "°C";
            break;
        case FAHRENHEIT:
            outF << "°F";
            break;
        case KELVIN:
            outF << "K";
            break;
        case RANKINE:
            outF << "°R";
            break;
    };
    return;
}

// printConversion: prints converted temperature and symbol without affecting 'this' object
void temperature_t::printConversion(char s, ostream& outF)
{
    scale_t sScale = CELSIUS;
    // assign appropriate scale for sScale
    assignScale(s, sScale);
    printConversion(sScale, outF);
    return;
}

void temperature_t::printConversion(scale_t sc, ostream& outF) // overloaded function
{
    // check for already assigned scale
    switch(scale == sc) 
    {
        // if true, print as-is (i.e without conversion)
        case true:
            print(outF);
            break;
        // else, print conversion without affecting 'this' object
        case false:
            switch(scale)
            {
                case CELSIUS:
                    celsiusConversions(sc).print(outF);
                    break;
                case FAHRENHEIT:
                    fahrConversions(sc).print(outF);
                    break;
                case KELVIN:
                    kelvinConversions(sc).print(outF);
                    break;
                case RANKINE:
                    rankineConversions(sc).print(outF);
            };
    };
    return;
}


// CONSTRUCTORS
temperature_t::temperature_t(double temp, scale_t s) {
    scale = s;
    temperature = temp;
    return;
}

temperature_t::temperature_t(scale_t s, double temp) {
    scale = s;
    temperature = temp;
    return;
}

temperature_t::temperature_t(char s, double temp) {
    scale = CELSIUS; // initialize scale before use
    assignScale(s, scale);
    temperature = temp;
    return;
}


// PRIVATE FUNCTIONS
//
// assignScale: finds scale corresponding to the value of parameter sc (of type char)
void temperature_t::assignScale(char sc, scale_t& paramScale) {
    switch(sc) 
    {
         case 'f':
         case 'F':
             paramScale = FAHRENHEIT;
             break;
         case 'k':
         case 'K':
             paramScale = KELVIN;
             break;
         case 'r':
         case 'R':
             paramScale = RANKINE;
             break;
         case 'c':
         case 'C':
            paramScale = CELSIUS;
         default:
             break;
    };
    return;
}

// Conversions
// converts variables temperature and scale from their current scale to desired scale

temperature_t temperature_t::celsiusConversions(scale_t s)
{
    temperature_t conv = *this; // store the contents of 'this' into conv
    // convert from celcius to...
    switch(s) 
    {
        case FAHRENHEIT:
            conv.temperature = (conv.temperature * (9.0 / 5.0)) + 32.0;
            break;
        case KELVIN:
            conv.temperature += 273.15;
            break;
        case RANKINE:
            conv.temperature = (conv.temperature + 273.15) * (9.0 / 5.0);
            break;
        case CELSIUS:
            break;
    };
    conv.scale = s;
    return conv;
}

temperature_t temperature_t::fahrConversions(scale_t s)
{
    temperature_t conv = *this;
    // convert from fahrenheit to...
    switch(s)
    {
        case CELSIUS:
            conv.temperature = (conv.temperature - 32.0) * (5.0 / 9.0);
            break;
        case KELVIN:
            conv.temperature = (conv.temperature - 32.0) * (5.0 / 9.0) + 273.15;
            break;
        case RANKINE:
            conv.temperature = (conv.temperature - 32.0) + 491.67;
            break;
        case FAHRENHEIT:
            break;
    };
    conv.scale = s;
    return conv;
}

temperature_t temperature_t::kelvinConversions(scale_t s)
{
    temperature_t conv = *this;
    //convert from KELVIN to...
    switch(s)
    {
        case CELSIUS:
            conv.temperature -= 273.15;
            break;
        case FAHRENHEIT:
            conv.temperature = (conv.temperature - 273.15) * (9.0 / 5.0) + 32.0;
            break;
        case RANKINE:
            conv.temperature *= (9.0 / 5.0);
            break;
        case KELVIN:
            break;
    };
    conv.scale = s;
    return conv;
}

temperature_t temperature_t::rankineConversions(scale_t s)
{
    temperature_t conv = *this;
    // convert from RANKINE to...
    switch(s)
    {
        case CELSIUS:
            conv.temperature = (conv.temperature * (5.0 / 9.0)) - 273.15;
            break;
        case FAHRENHEIT:
            conv.temperature = (conv.temperature - 491.67) + 32.0;
            break;
        case KELVIN:
            conv.temperature *= (5.0 / 9.0);
            break;
        case RANKINE:
            break;
    };
    conv.scale = s;
    return conv;
}
