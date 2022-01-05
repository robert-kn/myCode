#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

// this program counts lines, words, and characters (a word is defined as a sequence of characters that doesn't contain a blank, tab or newline
 
int main(){

	int character, newline, numberOfWords, numberOfCharacters, state;

	state = OUT; /* program starts off being outside of a word */

	newline = numberOfWords = numberOfCharacters = 0;

	while((character = getchar()) != EOF){
		++numberOfCharacters;

		if(character == '\n')
			++newline;

		if(character == ' ' || character == '\n' || character == '\t')
			state = OUT; /* currently not in a word */
		else if(state == OUT){
			state = IN;
			++numberOfWords;
		}

	}
	printf("newline count = %d numberOfWords count = %d numberOfCharacters count = %d\n", newline, numberOfWords, numberOfCharacters);

}
