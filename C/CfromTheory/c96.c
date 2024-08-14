/***
 * According to the ITU-T E.161 international standard, the digits of a phone pad correspond 
 * to letters as follows: ABC=2, DEF=3, GHI=4, JKL=5, MNO=6, PQRS=7, TUV=8, WXYZ=9. There is 
 * no correspondence for the digits 0 and 1. 
 * Write a program that reads a phone number up to 10 digits, which may include letters and 
 * display that number. For example, if the user enters CALL123456, the program should display 
 * 2255123456. The program should accept only 
 * uppercase letters and digits; otherwise, it should terminate. Use putchar() to write a 
 * character.
*/

#include <stdio.h>

int main(void)
{
    int ch, dig, arr[26] = {'2', '2', '2', '3', '3', '3', '4', '4', '4', '5', '5', '5', '6', '6', '6', '7', '7', '7', '7', '8', '8', '8', '9', '9', '9', '9'}; /* Initialize an array to make right away the mapping. */

    dig = 0;

    printf("Enter digit or letter: ");

    while((ch = getchar()) != '\n' && ch != EOF)
    {
        if(ch >= 'A' && ch <= 'Z')
        {
            dig++;
            putchar(arr[ch-'A']); /* The output digit depends on the value of ch. For example, if the user enters 'I' the output would be arr[73-65] = 4. */
        }
        else if(ch >= '0' && ch <= '9')
        {
            dig++;
            putchar(ch);        /* A digit is displayed as is. */
        }
        else{
            printf("Error: Not valid character\n");
            return 0;
        }
        if(dig == 10)
            break;
    }
    if(dig == 10)
        printf("\nNumber completed\n");
    return 0;

}