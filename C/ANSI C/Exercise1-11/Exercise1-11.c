#include <stdio.h>

#define IN 1  /* inside of a word */
#define OUT 0 /* outside of a word */

/* count lines, words and characters in input */

int main (){

	system("clear");

	int newlineCount, wordCount, charCount, character, STATE;

	STATE = OUT; // start outside a word;

	newlineCount = wordCount = charCount = 0;

	while((character = getchar()) != EOF){

		++charCount;

		if(character == '\n')
			++newlineCount;

		if(character == ' ' || character == '\n' || character == '\t')
			STATE = OUT;
		else if(STATE == OUT){
			STATE = IN;
			++wordCount;
		}
	}
	printf("word count = %d; new lines = %d; character count = %d\n",wordCount, newlineCount, charCount);
	return 0;	
}
