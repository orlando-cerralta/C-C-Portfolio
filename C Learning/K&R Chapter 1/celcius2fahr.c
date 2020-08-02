// Author: Orlando Cerralta
// Date: 7/26/2020
// Exercise 1-3 from K&R: Convert Celcius to Fahrenheit
#include <stdio.h>

int main()
{
    // variable declarations
    double      fahr, celcius;
    int         lower, upper, step;
    // variable initialization
    lower = 0;          // lower limit of temperature table
    upper = 300;        // upper limit of temp table
    step = 20;          // step size

    // prepare conversion table
    celcius = lower;                                // set celius to zero
    printf("%6s %6s\n", "celc", "fahr");            // print formatted heading
    // while loop prints each step (until 300 degrees celcius) with its correspondingfahrenheit equivalent
    while(celcius <= upper) 
    {
        fahr = (celcius * (9.0 / 5.0)) + 32.0;      // celcius to fahrenheit formula
        printf("%6.0f %6.1f\n", celcius, fahr);     // formatted output of current line
        celcius = celcius + step;                   // go to next step
    }
    return 0;
}
