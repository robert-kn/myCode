/* Write a program that simulates a simple electronic roulette that allows the player to bet on whether the 
winning number of the next spin of the roulette ball will be odd or even. The numbers of the roulette are 
from 0 up to 36. If the winning number is 0, the player loses because 0 is counted as neither odd nor even. 
The program should display a menu to perform the following operations:

1. Bet on odd numbers
2. Bet on even numbers
3. Spin the ball
4. Statistics
5. Termination

After selecting the kind of bet (i.e., odd or even), the player should specify the bet. When the third option 
is chosen, the program should generate a random integer in [0, 36] and display a message to indicate if the 
player won or lost. The fourth option should display some statistics, that is, how many times the player 
won/lost and how much money the player wins or loses.

We left the best for the end. The program should be written in such a way that the player should have 
defnitely lost, at the end of the game. In particular, the player must lose the frst bet and when he or 
she bets more than the amount he or she loses.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOSS 0
#define WIN 1

void unfair_play(int sel, int bet, int *lost, int *times); 
int fair_play(int sel, int bet, int *lost);

int main(void)
{
    int sel, last_sel, flag, tmp, bet, sum_lost, win_times, lost_times;

    flag = 1;
    sum_lost = win_times = lost_times = 0;

    while(1)
    {
        printf("\nRoulette Game\n");
        printf("--------------\n");

        printf("1. Odd\n");
        printf("2. Even\n");
        printf("3. Play\n");
        printf("4. Stats\n");
        printf("5. Exit\n");

        printf("\nEnter choice: ");
        scanf("%d", &sel);

        srand(time(NULL));

        switch(sel)
        {
            case 1:
            case 2:
                last_sel = sel; /* last_sel holds the last choice of the player, before the third choice is selected. */
                do
                {
                    printf("\nPlace your bet: ");
                    scanf("%d", &bet);
                } while (bet <= 0);
            break;

            case 3:
                if(bet == 0)
                {
                    printf("No bet is placed\n");
                    break;
                }
                if(flag == 1) /* We force the program to play unfairly and make the player to lose the first bet. */
                {
                    flag = 0;
                    unfair_play(last_sel, bet, &sum_lost, &lost_times);
                }
                else
                {
                    if(bet >= sum_lost) /* If the player bets a larger amount than the money he loses, the program behaves unfairly and the player loses. */
                        unfair_play(last_sel, bet, &sum_lost, &lost_times);
                    else
                    {
                        tmp = fair_play(last_sel, bet, &sum_lost);
                        if(tmp == LOSS)
                        {
                            printf("Sorry, you lost ...\n");
                            lost_times++;
                        }
                        else
                        {
                            printf("Yeaaaaah, you won ...\n");
                            win_times++;
                        }
                    }
                }
                bet = 0;
            break;

            case 4:
                printf("\nWin_Times: %d\tLost_Times: %d\tLost_ Money: %d euro\n", win_times, lost_times, sum_lost);
            break;

            case 5:
            return 0;

            default:
                printf("\nWrong choice\n");
            break;
        }
    }
    return 0;
}

/* The program generates a number, so that the player loses. For example, if the player bets on odd numbers the program generates an even number, and vice versa. */
void unfair_play(int sel, int bet, int *lost, int *times)
{
    int num;

    *lost += bet;
    (*times)++;

    while(1)
    {
        num = rand() % 37;
        if(sel == 1) /* The player bets on odd numbers. */
        {
            if((num & 1) == 0)
            {
                printf("\nThe ball goes to %d. Sorry, you lost ...\n", num);
                return;
            }
        }
        else /* The player bets on even numbers. */
        {
            if((num & 1) == 1)
            {
                printf("\nThe ball goes to %d. Sorry, you lost ...\n", num);
                return;
            }
        }
    }
}

int fair_play(int sel, int bet, int *lost)
{
    int num;

    num = rand() % 37;
    printf("\nThe ball goes to %d. ", num);

    if(num == 0) /* If zero comes out, the player loses. */
    {
        *lost += bet; 
        return LOSS;
    }
    if(sel == 1) /* The player bets on odd numbers. */
    {
        if((num & 1) == 1)
        {
            *lost -= bet; /* If the player wins, the total lost amount is reduced. */
            return WIN;
        }
        else
            *lost += bet; /* If the player loses, the total lost amount is increased. */
    }
    else /* The player bets on even numbers. */
    {
        if((num & 1) == 0)
        {
            *lost -= bet; 
            return WIN;
        }
        else
            *lost += bet;
    }
    return LOSS;
}

/* Since the program controls the bets, the player eventually loses even if he or she won more times than he 
or she lost. In other words, the program creates the feeling of “misfortune” in the player, whereas it 
actually cheats him or her.

However, the main purpose of this exercise is instructive. With this simple simulation example, we want to 
show you that gambling games’ software can be written in a way that creates the feeling of “bad luck,” 
whereas the player is just a victim of fraud.

Therefore, stay away from online gaming and any kind of electronic “lucky machines” 
(e.g., slot machines, fruit machines, and so on). The big profts they promise are not for you, but for 
their owners.*/