#include <stdio.h>
#include <stdlib.h>

/* Write a program to print a histogram of the lengths of words in its input. It is
easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging. */

#define HISTLIMIT 25 /* histogram can only store counts to 15 (no words comprise 0 characters) */

int main(){
	system("clear");
	int character, i, j, characterNumber;
	int frequencyHist[HISTLIMIT];

	characterNumber = 0;

	for(i = 0; i < HISTLIMIT; i++)
		frequencyHist[i] = 0;

	printf("Please enter a paragraph\n\n");

	while((character = getchar()) != EOF){

		// if the char is not a blank then count it
		if(character != ' ' && character != '\n' && character != '\t')
			++characterNumber;
		// if the char is blank, tab or white space then add the count to the array as long as chars 
		// that make up word are less than HISTLIMIT. Reset nChars to 0
		else if(character == '\n' || character == '\t' || character == ' '){
			if(characterNumber < HISTLIMIT)
				++frequencyHist[characterNumber];
			
			characterNumber = 0;
		}
	
	}

	printf("\n\n A histogram of the words that have been input:\n\n");

	for(i = 1; i < HISTLIMIT; i++){
		printf("%2d |", i);
		for(j = 0; j < frequencyHist[i]; j++){
			printf("*");
		}
		printf("\n");
	}
		
}
