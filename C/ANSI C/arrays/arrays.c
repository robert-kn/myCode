#include <stdio.h>

/* program counts digits, whitespace and other characters */

int main () {
	
	int i, character, nWhite, nOther;

	int digits[10];

	nWhite = nOther = 0;

	for(i = 0; i < 10; i++)
		digits[i] = 0;

	while((character = getchar()) != EOF){
		
		if(character >= '0' && character <= '9')
			++digits[character - '0'];
		else if(character == ' ' || character == '\n' || character == '\t')
			++nWhite;
		else
			++nOther;
	
	}

	printf("digits = ");
	for(i = 0; i < 10; i++)
		printf("%d", digits[i]);
	printf(", white space = %d, other = %d\n", nWhite, nOther);




}
