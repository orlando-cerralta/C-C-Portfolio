// Author: Orlando Cerralta
// Date: 08/03/2020
// K&R Fahr to Celcius conversion program
#include <stdio.h>

// symbolic constants
#define LOWER   0       // lower limit of temperature table
#define UPPER   300     // upper limit of temperature table
#define STEP    20      // step size

// function prototypes
double fahrToCelcius(double fahr);

int main()
{
    double fahr;

    // print table header
    printf("%6s %6s\n", "fahr", "celc");
    // print fahrenheit to celcius table
    for (fahr = LOWER; fahr <= UPPER; fahr += STEP)
        printf("%6.0f %6.1f\n", fahr, fahrToCelcius(fahr)); // formatted output of current line

    return 0;
}

// converts fahrenheit to celcius
double fahrToCelcius(double fahr) {
    double celcius;

    celcius = (5.0 / 9.0) * (fahr - 32.0); // fahr to celcius formula

    return celcius;
}
