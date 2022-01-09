#include <stdio.h>

/* program prints its input one word per line  */

int main(){
	int character;

	while((character = getchar()) != EOF){

		if(character == ' ' || character == '\n' || character == '\t')
			putchar('\n');
		else
			putchar(character);
	}
}
