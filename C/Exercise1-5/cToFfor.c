#include <stdio.h>

#define LOWER   0 /* lower limit */
#define UPPER 300 /* upper limit */
#define STEP   20 /* step size */
int main(){
	int celsius;
	printf("This is a program that converts celsius to fahrenheit using a for loop!\n\n");
	for(celsius = UPPER; celsius >= LOWER; celsius-=STEP){
		printf("%3d %6.1f\n",celsius, celsius * (9/5.0) + 32);
	}
}
