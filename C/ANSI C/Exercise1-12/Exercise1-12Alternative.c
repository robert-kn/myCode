#include <stdio.h>

#define IN 1 /* inside of a word */
#define OUT 0 /* outside of a word */

/* print input one word per line */

int main () {
	int character, STATE;

	STATE = OUT;

	while((character = getchar()) != EOF){
		if(character == ' ' || character == '\t' || character == '\n'){
			if(STATE == IN){	/* end of a word reached */
				putchar('\n');
				STATE = OUT;
			}
		}
		else if(STATE == OUT){ /* beginning of a word */
			STATE = IN;
			putchar(character);
		}
		else
			putchar(character);	/* inside of a word */
	}
}
