/**
 * Write a program that assigns random values within [0, 20] to the elements of a 6×8 integer array. Then, the program should read the user’s choice, and 
 * if it is 1, it should read two more integers, which correspond to two rows, and swap their elements. If it is not 1, the two input integers correspond to 
 * columns. The program should check the validity of the two input integers and display the original and final array.
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

#define ROWS 6 
#define COLS 8

int main(void){
    int i, j, a, b, max, tmp, type, arr[ROWS][COLS];

    srand(time(NULL));
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLS; j++){
            arr[i][j] = rand()%21;
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }
    printf("Enter swap type (1:rows): "); 
    scanf("%d", &type);

    if(type == 1)
        max = ROWS;
    else
        max = COLS;

    do{
        printf("Enter dim_1[1-%d]: ", max);
        scanf("%d", &a);
    }while(a < 1 || a > max);

    do{
        printf("Enter dim_2[1-%d]: ", max);
        scanf("%d", &b);
    }while(b < 1 || b > max);

    a--; /* Subtract 1, since indexing starts from 0.*/ 
    b--;

    if(type == 1)
    {
        for(i = 0; i < COLS; i++) {
            tmp = arr[a][i];
            arr[a][i] = arr[b][i];
            arr[b][i] = tmp;
        }
    }
    else{
        for(i = 0; i < ROWS; i++){
            tmp = arr[i][a];
            arr[i][a] = arr[i][b];
            arr[i][b] = tmp;
        }
    }

    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLS; j++)
            printf("%5d", arr[i][j]);
        printf("\n");
    }
    return 0;
}