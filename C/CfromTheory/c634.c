/**
 * The final grade in a course is calculated as 30% of the lab grade and as 70% of the exam’s grade, only if both grades 
 * are greater than or equal to 5; otherwise, the final grade will be the lesser. Write a program that reads continuously 
 * pairs of grades (lab and exam grades) and displays the final grade for each student, until the user enters a pair of grades 
 * containing the value −1. The program should display the average grade of all students in the course, before it ends. The 
 * program should force the user to enter grades within [0, 10].
*/

#include <stdio.h>

int main(void){
    double lab_grade, exam_grade, final_grade, sum;
    int count = 0;
    lab_grade = exam_grade = sum = 0;

    while(1){

        printf("Enter lab grade [0, 10]: ");
        scanf("%lf", &lab_grade);
        printf("Enter exam grade [0, 10]: ");
        scanf("%lf", &exam_grade);

        if(lab_grade == -1 && exam_grade == -1)
            break;
        
        if(lab_grade < 0 || lab_grade > 10 || exam_grade < 0 || exam_grade > 10){
            printf("grades entered are out of range\n");
            continue;
        }
        else if((lab_grade + exam_grade) >= 5.0){
            final_grade = (0.3 * lab_grade) + (0.7 * exam_grade);
            sum += final_grade;
            count++;
            printf("final grade for student %.3lf\n", final_grade);
        }

        
    }
    if(count != 0)
        printf("Average grade of all students %lf\n", sum/count);
    return 0;
}