/* Write a program that reads the order of preference that 100 tourists answered in the question: “What did you enjoy the most in Greece?”
1. The natural diversity
2. The climate
3. The islands
4. The night life
5. The monuments
6. The people
7. The food
Each answer takes 1–7 points according to its rank order. The frst answer takes 7 points, the second one takes 6 points, and the last one takes 1 point. For example, if two tourists answered the following:

First Tourist      Second Tourist
5 (7p.)             3 (7p.)
4 (6p.)             7 (6p.)
6 (5p.)             2 (5p.)
3 (4p.)              1 (4p.)
2 (3p.)              5 (3p.)
1 (2p.)              4 (2p.)
7 (1p.)               6 (1p.)

the program should display: First answer gets 6 points Second answer gets 8 points

Third answer gets 11 points Fourth answer gets 8 points Fifth answer gets 10 points Sixth answer gets 6 points Seventh answer gets 7 points

The program should read valid answers in [1, 7] and check if the answer is already given. If it is, the program should display a message and prompt the user to enter a new one.
*/

#include <stdio.h>
#include <string.h>

#define TOURISTS    100
#define ANSWERS    7

int main(void)
{
    int i, j, sel, pnts[ANSWERS] = {0}; /* This array holds the points of each answer. For example, pnts[0] holds the points of the first answer, pnts[1] holds the points of the second answer and so on. */
    int given_ans[ANSWERS] = {0}; /* This array is used to check whether an answer is already given or not. If an element's value is 1, it means that the respective answer is chosen. For example, if the user chooses the third answer, given_ans[2] becomes 1. */

    for(i = 0; i < TOURISTS; i++)
    {
        printf("\nEnter answers of tourist_%d:\n", i+1);
        memset(given_ans, 0, sizeof(given_ans)); /* The values must be zeroed before reading the answers of a new tourist. See memset() in Appendix C. */

        for(j = 0; j < ANSWERS; j++)
        {
            while(1) /* Infinite loop until the user enters a valid answer, not already given. */
            {
                printf("Answer_%d [1-%d]: ", j+1, ANSWERS); 
                scanf("%d", &sel);

                if(sel < 1 || sel > ANSWERS)
                    printf("Wrong answer ...\n"); 
                else if(given_ans[sel-1] == 1)
                    printf("Error: This answer is already given ...\n");
                else
                    break;
            }
            pnts[sel-1] += ANSWERS - j; /* For example, if the first answer (j = 0) is the fifth one, then pnts[sel-1] = pnts[5-1] = pnts[4] += 7–0 = 7; that is, 7 more points are added to the points of the fifth choice. */
            given_ans[sel-1] = 1;
        }
    }
    printf("\n***** Answer Results *****\n");
    for(i = 0; i < ANSWERS; i++)
        printf("Answer_%d gets %d points\n", i+1, pnts[i]);
    return 0;
}