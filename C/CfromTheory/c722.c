/***
 * Write a program that simulates an online lottery game. Suppose that the winning numbers are 10 and their values are within [0, 100]. However, the 
 * program should be written in a way to control the winning numbers. In particular, the “cheat” is that 3 of the winning numbers in each lottery 
 * should have also been drawn in the previous one. The program should ask the user to play, and if the answer is no, the program terminates.
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

#define SIZE 10 

int main(void)
{
    int i, pos1, pos2, pos3, ans, arr[SIZE];
    srand(time(NULL));

    /* First lottery. */
    for(i = 0; i < SIZE; i++) {
       arr[i] = rand()%101;
       printf("%d ", arr[i]);
    }
    
    while(1) {
        printf("\nContinue to play? (0:No): "); 
        scanf("%d", &ans);
        if(ans == 0)
            return 0;
        /* We choose three random places. The numbers stored in these places will be drawn in the next lottery. */
        pos1 = rand()%SIZE;
        do{
            pos2 = rand()%SIZE;
        }while(pos1 == pos2);

        do{
            pos3 = rand()%SIZE;
        }while((pos1 == pos3) || (pos2 == pos3));

        /* Next lottery */
        for(i = 0; i < SIZE; i++){
            if((i == pos1) || (i == pos2) || (i == pos3)){
                printf("%d ", arr[i]);
                continue;
            }

            arr[i] = rand()%101;
            printf("%d ", arr[i]);
        }
    }
    return 0;

}