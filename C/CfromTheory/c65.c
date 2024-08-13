/**
 * A test consists of 10 multiple choice questions, each of which has three possible answers. 
 * The first answer gets three points, the second one point, and the third two points. Write 
 * a program that uses the switch statement to read the test taker’s 10 answers and display 
 * the final score.
*/

#include <stdio.h>

int main(void){
    int points, i, ans;
    points = 0;

    for(i = 0; i < 10; i++){
        printf("Enter answer [1,3]: ");
        scanf("%d", &ans);
        switch(ans){
            case 1:
                points += 3;
            break;
            case 2:
                points += 1;
            break;
            case 3:
                points += 2;
            break;
            default:
                printf("Error: wrong answer...\n");
            break;
        }
    }
    printf("final score is %d\n", points);
    return 0;
}