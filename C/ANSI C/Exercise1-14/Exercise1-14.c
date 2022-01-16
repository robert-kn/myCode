#include <stdio.h>

/* program prints a histogram of the frequencies of different chars in its input */

int main(){

	int alphabet[26];

	int i, character;

	for(i = 0; i < 26; i++)
		alphabet[i] = 0;

	while((character = getchar()) != EOF){

                if(character >= 'a' || character <= 'z')
			//++alphabet[character - 'a'];
			printf("*");
		else if(character == ' ' || character == '\t' || character == '\n')
			printf("\n");

        }


	//for(i = 0; i < 26; i++)
	//	putchar('\n');
	//	for(int j = 0; j < alphabet[i]; j++)
	//		printf("*");	

}
