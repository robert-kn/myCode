/**
 * Write a program that reads a character, an integer, and a float number and displays
them. Use one scanf().
 */

#include <stdio.h>

int main(void)
{
    char ch;
    int i;
    float f;
    
    printf("Enter character, int and float: ");
    scanf("%c%d%f", &ch, &i, &f);
    printf("\nC:%c\tI:%d\tF:%f\n", ch, i, f);
    return 0;
}