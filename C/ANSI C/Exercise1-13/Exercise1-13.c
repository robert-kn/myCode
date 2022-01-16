#include <stdio.h>

/* program to print a histogram of the lengths of words in its input */

int main(){
	int character;

	while((character = getchar()) != EOF){

		if(character == '\n' || character == '\t' || character == ' ')
			putchar('\n');
		else
			printf("*");
	
	}
}
