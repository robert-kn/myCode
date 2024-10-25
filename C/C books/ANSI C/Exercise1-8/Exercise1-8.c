#include <stdio.h>
#include <stdlib.h>

/* Write a program to count blanks, tabs, and newlines. */

int main(){
	system("clear");
	int character, countB, countT, countNL;
	
	countB = countT = countNL = 0;

	while((character = getchar()) != EOF){
		if(character == '\n')
			++countNL;
		if(character == '\t')
			++countT;
		if(character == ' ')
			++countB;
	}
	printf("blanks = %d, tabs = %d, newlines = %d\n", countB, countT, countNL);
}
