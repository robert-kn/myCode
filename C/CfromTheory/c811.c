/**
 * Use the p2 pointer and complete the following program to read students’ grades continuously until the user enters -1. Use 
 * the p1 pointer to display how many students got a grade within [5, 10] and the p3 pointer to display the best grade.
 * 
*/

#include <stdio.h> 
int main(void)
{
    int *p1, sum;
    float *p2, *p3, grade, max; 

    p1 = &sum;
   
    p2 = &grade;
    
    p3 = &max;

    *p1 = *p3 = 0;

    while(1){
        printf("Enter grade between [5, 10]: ");
        scanf("%f", p2);

        if(*p2 >= 5 && *p2 <= 10){
            ++(*p1);
            if(*p2 > *p3)
                *p3 = *p2;
        }

        if(*p2 == -1)
            break;
    }

    if(max == 0)
        printf("No grades were entered\n");
    else
        printf("%d students got grades between [5, 10]. The best grade was %f\n", *p1, *p3);

    return 0;
    
}
