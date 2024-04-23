/**
 * Write a program that reads three characters and checks if they are consecutive in the ASCII character set.
*/

#include <stdio.h>

int main(void)
{
    char ch1, ch2, ch3;

    printf("Enter characters: ");
    scanf("%c%c%c", &ch1, &ch2, &ch3);

    if((ch1+1 == ch2) && (ch2+1 == ch3))
        printf("Consecutive\n");
    else
        printf("Not consecutive\n");
    return 0;
}

/* Comments: If you run the program, don’t type a space between the input characters because the space is a character as well (unless the space character is among the characters you want to check). */