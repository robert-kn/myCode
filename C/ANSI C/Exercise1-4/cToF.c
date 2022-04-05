#include <stdio.h>

/* This program will convert degrees celsius to fahrenheit from -20 to 300 in increments of 20 */ 
void  main() {
	float fahr, celsius;
	
	int lower = -20;
	int upper = 300;
	int step = 20;
	
	celsius = lower;
	printf("This is a program to convert celsius to fahrenheit\n\n");	
	while(celsius <= upper) {
		fahr = (celsius * (9.0 / 5.0)) + 32.0;
		printf("%3.0f \t %6.1f \n", celsius, fahr);
		celsius = celsius + step;
	}
}
