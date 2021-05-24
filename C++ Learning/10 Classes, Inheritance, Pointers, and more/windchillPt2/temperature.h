// Author:      Orlando Cerralta
// Date:        05/19/2021
// Description: An Abstract Data Type which describes temperature. 
//              Use this data type to store the temperature and their unit of measurement,
//              and display unit conversions
#pragma once

#include <iostream>
using namespace std;

// scale_t describes the various units of measurement for temperature.
// Use to select scale unit
enum scale_t { CELSIUS, FAHRENHEIT, KELVIN, RANKINE };

class temperature_t 
{
public:
    // MUTATOR FUNCTIONS
    void    setTemperature(double t);
        // post condition: temperature = t
    
    void    setScale(char s);
    void    setScale(scale_t s); // overload
        // post condition: scale = s

    void    conversion(char s);
    void    conversion(scale_t sc); // overload
        // post condition: temperature & scale are converted to corresponding selected values

    
    // ACCESSOR FUNCTIONS
    double  getTemperature() const;
        // post condition: returns value of temperature (of type double)
    
    scale_t getScale() const;
        // post condition: returns value of scale (of type scale_t)
    
    void    print(ostream& outF = cout) const;
        // post condition: outputs temperature and scale i.e. "0 °C" or "273.15 K"
    
    void    printConversion(char s, ostream& outF = cout);
    void    printConversion(scale_t sc, ostream& outF = cout); // overload
        // post condition: outputs temperature conversion of selected scale without
        //              affecting values of temperature and scale

    // CONSTRUCTORS
    temperature_t(double temp = 0.00, scale_t s = CELSIUS);
    temperature_t(scale_t s, double temp = 0.00);
    temperature_t(char s, double temp = 0.00);
        // post condition: sets temperature = temp, 
        //          and scale = sc [CELCIUS (by default), FAHRENHEIT (if sc = 'F' or 'f'),
        //          KELVIN (if sc = 'K' or 'k'), or RANKINE (if sc = 'R' or 'r')]

private:
    void            assignScale(char sc, scale_t &paramScale);
    // conversion functions
    temperature_t   celsiusConversions(scale_t s);
    temperature_t   fahrConversions(scale_t s);
    temperature_t   kelvinConversions(scale_t s);
    temperature_t   rankineConversions(scale_t s);

    // private variables
    double      temperature;
    scale_t     scale;
};
