#include <stdio.h>

/* program prints a histogram of the frequencies of different chars in its input */

int main(){
	system("clear");

	int alphabetCount[26];
	char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

	int i, j, character;

	for(i = 0; i < 26; i++)
		alphabetCount[i] = 0;

	while((character = getchar()) != EOF){

		for(i = 0; i < 26; i++){
			if(character == alphabet[i]){
				++alphabetCount[i];
			}
		}
	}
	printf("\n\nHistogram of characters from input read from stdin:\n\n");
	for(i = 0; i < 26; i++){
		printf("\t%c: ", alphabet[i]);
		for(j = 0; j < alphabetCount[i]; j++)
			printf("*");
		printf("\n");
	}

}
