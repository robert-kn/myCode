/**
 * Write a program that a teacher may use to test if the students know the 
 * multiplication table. The program should generate two random values within 
 * [1, 10] (e.g., a and b) and display axb =(the smaller number should appear 
 * first). The program should prompt the student to enter the result and display 
 * an informative message to indicate whether the answer is correct or not. If the 
 * student enters -1, the program should display the total number of correct and 
 * wrong answers and then terminate.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){

    int i, j, num, fails, wins;

    fails = wins = 0;
    srand(time(NULL));

    do{
        i = rand() % 10 + 1;

        j = rand() % 10 + 1;

        if(i < j)
            printf("%d x %d = ", i, j);
        else
            printf("%d x %d = ", j, i);

        printf("Enter ans: ");
        scanf("%d", &num);

        if(num != -1){
            if(num == i*j){
                printf("Correct\n");
                wins++;
            }
            else{
                printf("Wrong (answer = %d)\n", i * j);
                fails++;
            }
        }
    } while(num != -1);

    printf("Fails = %d, Wins = %d\n", fails, wins);
    return 0;
}