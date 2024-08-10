/* Write a program that simulates the popular game master-mind. The program should generate a random 
sequence of four different colors out of six available colors (e.g., red:0, green:1, blue:2, white:3, 
black:4, yellow:5). This is the secret sequence. Then, the program should prompt the user to enter sequences 
of colors in order to fnd the secret one. For each given sequence, the program should inform the user of 
the number of the right colors in right places and the number of right colors in wrong places.

For example, if the secret sequence to be found is: 0 1 2 3 and the user enters the sequence: 5 1 4 2, the 
program should display: “one right color in the right place and one right color in wrong place.” If the 
user makes 10 unsuccessful attempts, the program terminates and the user loses.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEBUG

void guess_code(int guess[]);

int main(void)
{
    int i, j, k, found, corr_guess, col_guess, code[4], guess[4];

    srand(time(NULL));
    i = 0;
    /* Generate a random sequence with four different colors. */ 
    while(i < 4)
    {
        code[i] = rand()%6;
        found = 0;
        for(j = 0; j < i; j++)
        {
            if(code[j] == code[i])
            {
                found = 1;
                break;
            }
        }
        if(found == 0)
            i++;
    }
#ifdef DEBUG
    printf("\n**** Secret code is: %d %d %d %d\n\n", code[0], code[1], code[2], code[3]);
#endif
    for(i = 0; i < 10; i++)
    {
        guess_code(guess);
        corr_guess = col_guess = 0;
        /* Calculate the number of right colors in right places. */
        for(j = 0; j < 4; j++)
        {
            if(guess[j] == code[j]) 
                corr_guess++;
        }
        if(corr_guess == 4)
        {
            printf("\nCongratulations !!! You did it in %d attempts\n", i+1);
            return 0;
        }
        /* Calculate the number of right colors in wrong places. */ 
        for(j = 0; j < 4; j++)
        {
            for(k = 0; k < 4; k++)
            {
                /* The second term is needed, in order not to add again the number of right colors in right places. */
                if((guess[k] == code[j]) && (k != j))
                {
                    col_guess++;
                    break;
                }
            }
        }
        printf("Colors in right places = %d\nMatching colors in wrong places = %d\n\n", corr_guess, col_guess);
    }
    printf("\nFail: The secret code is %d %d %d %d\n", code[0], code[1], code[2], code[3]);
    return 0;
}

/* For simplicity, we assume that the user enters different colors. */ 
void guess_code(int guess[])
{
    int i, col;
    i = 0;
    while(i < 4)
    {
        printf("Enter color (RED:0,GREEN:1,BLUE:2,WHITE:3,BLACK:4, YEL:5): ");
        scanf("%d", &col);

        switch(col)
        {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                guess[i] = col;
                i++;
            break;

            default:
                printf("Wrong choice\n");
            break;
        }
    }
}

/* The reason we didn’t remove the DEBUG macro is to show you how we can use a macro to check the operation of the program. */