#include <stdio.h>

/* program prints a histogram of the frequencies of different chars in its input */

int main(){

	int alphabetCount[25];

	int i, j, c;

	for(i = 0; i < 26; i++)
		alphabetCount[i] = 0;

	while((c = getchar()) != EOF)
		++alphabetCount[c - 'a'];

	printf("\n\nHistogram of characters from input read from stdin:\n\n");
	for(i = 0; i < 26; i++){
		printf("\t%c: ", 'a' + i);
		for(j = 0; j < alphabetCount[i]; j++)
			printf("*");
		printf("\n");
	}

}
