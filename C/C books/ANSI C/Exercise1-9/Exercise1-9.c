#include <stdio.h>
#include <stdlib.h>

/* Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank. */

#define NONBLANK 'a'

int main () {
    system("clear");
    
    int character, lastCharacter;

    lastCharacter = NONBLANK;

    while((character = getchar()) != EOF){
        if(character != ' '){
            putchar(character);
        }
        if(character == ' '){
            if(lastCharacter != ' '){
                putchar(character);
            }
        }

        lastCharacter = character;
    }
}