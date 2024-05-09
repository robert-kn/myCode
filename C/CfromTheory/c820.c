/**
 * Write a program that reads the grades of 10 students, stores them in an array, and displays the best and the worst grade and the 
 * positions of their first occurrences in the array. The program should force the user to enter grades within [0, 10]. Use pointer 
 * arithmetic to process the array.
*/
#include <stdio.h>

#define SIZE 10

int main(void){
    int count, i, best_idx, wor_idx, arr[SIZE] = {0};
    count = 0;
    double grade, best, worst;
    worst = 10;
    best = 0;

    while(1){
        if(count > (SIZE - 1))
            break;
        
        printf("Enter grade [0, 10] for student %d: ", count+1);
        scanf("%lf", &grade);

        
        if(grade < 0 || grade > 10){
            printf("Grade should be within range [0, 10]\n");
            continue;
        }
        else{
            *(arr + count) = grade;
            count++;
        }
    }

    for(i = 0; i < SIZE; i++){
        if(*(arr + i) > best){
            best = *(arr + i);
            best_idx = i;
        }
        if(*(arr + i) < worst){
            worst = *(arr + i);
            wor_idx = i;
        }
    }

    printf("The best grade was %.2f at pos %d. The worst grade was %.2f at pos %d\n", best, best_idx, worst, wor_idx);


}