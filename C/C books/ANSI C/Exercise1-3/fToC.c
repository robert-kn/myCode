#include <stdio.h>

/* print fahrenheit-celcius table for fahr = 0, 20, ..., 300 */

int main() {

	float fahr, celsius;
	float lower, upper, step;
	
	lower = 0; // lower limit of temp scale
	upper = 300; // upper limit of temp
	step = 20; // step size
	
	fahr = lower;
	printf("Table of Fahrenheit temperatures converted to celsius\n\n"); 
	while(fahr <= upper) {
		celsius = 5.0 * (fahr - 32.0) / 9.0;
		printf("%3.0f \t %6.1f \n", fahr, celsius);
		fahr = fahr + step;
	}

    return  0;	
}

