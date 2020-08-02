// Author: Orlando Cerralta
// Date: 7/26/2020
// Exercise 1-3 from K&R: Convert Celcius to Fahrenheit
#include <stdio.h>

// symbolic constants
#define LOWER   0       // lower limit of table
#define UPPER   300     // upper limit of table
#define STEP    20      // step size

int main()
{
    double      celcius;

    // prepare conversion table
    printf("%6s %6s\n", "celc", "fahr");    // print formatted heading
    // for loop prints each step (from 300 to 0 degrees celcius) with its corresponding fahrenheit equivalent
    for(celcius = UPPER; celcius >= LOWER; celcius -= STEP) 
        printf("%6.0f %6.1f\n", celcius, ((celcius * (9.0 / 5.0)) + 32.0));     // formatted output of current table line
    
    return 0;
}
