/* Suppose that each line of the students.txt text fle contains the names of the students and their grades in two lessons, as follows: 

John       Morne    7              8.12
Sahil      Nehrud  4.5               9
Koon      Lee       2              5.75

Write a program that reads each line of students.txt and stores in suc.txt the names and grades of the students with average grade greater than or equal to 5, while in fail. txt 
the students with average grade less than 5. To read the grades, use double variables and assume that the names are less than 100 characters. The program should display the number 
of students written in each fle.*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp_in, *fp_suc, *fp_fail;
    char fnm[100], lnm[100];
    int suc_stud, fail_stud;
    double grd1, grd2;

    fp_in = fopen("students.txt", "r");
    if(fp_in == NULL)
    {
        printf("Error: students.txt can't be loaded\n"); 
        exit(EXIT_FAILURE);
    }
    fp_suc = fopen("suc.txt", "w");
    if(fp_suc == NULL)
    {
        fclose(fp_in);
        printf("Error: suc.txt can't be created\n");
        exit(EXIT_FAILURE);
    }
    fp_fail = fopen("fail.txt", "w");
    if(fp_fail == NULL)
    {
        fclose(fp_in);
        fclose(fp_suc);
        printf("Error: fail.txt can't be created\n");
        exit(EXIT_FAILURE);
    }

    suc_stud = fail_stud = 0;

    while(1)
    {
        if(fscanf(fp_in, "%s%s%lf%lf", fnm, lnm, &grd1, &grd2) != 4) 
            break;
        if((grd1+grd2)/2 >= 5)
        {
            fprintf(fp_suc, "%s %s %f %f\n", fnm, lnm, grd1, grd2); 
            suc_stud++;
        }
        else
        {
            fprintf(fp_fail, "%s %s %f %f\n", fnm, lnm, grd1, grd2);
            fail_stud++;
        }
    }

    printf("Failed: %d Succeeded: %d\n", fail_stud, suc_stud); 
    fclose(fp_suc);
    fclose(fp_fail); 
    fclose(fp_in); 
    return 0;
}