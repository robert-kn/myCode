#include <stdio.h>

int main(){
	int celsius;
	for(celsius = 300; celsius >= 0; celsius-=20){
		printf("%3d %6.1f\n",celsius, celsius * (9/5.0) + 32);
	}
}
