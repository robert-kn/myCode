#include <stdio.h>

char ToUpper(char inchar);

// Prompt for a line of text, Read one character,
// convert to uppercase, print it out, then get another

int main(void)
{
	char echo = 'A'; // Initialize input character
	char upcase;     // Converted character

	printf("Type input: ");
	while(echo != '\n')
	{
		scanf("%c", &echo);
		upcase = ToUpper(echo);
		printf("%c", upcase);
	}
}

// If the parameter is lowercase, return its uppercase ASCII value
char ToUpper(char inchar)
{
	char outchar;
	if ('a' <= inchar && inchar <= 'z')
		outchar = inchar - ('a' - 'A');
	else
		outchar = inchar;

	return outchar;
}
