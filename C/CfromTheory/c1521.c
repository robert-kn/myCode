/* Suppose that the number of students is stored in the beginning of the test. bin binary fle. The next group of fves declares the grades of the frst student in fve courses. The next 
group declares the fve grades of the second student in the same courses, and so on. Write a program that reads the fle and displays the average grade of each student.*/

#include <stdio.h>
#include <stdlib.h>

#define LESSONS 5

int main(void)
{
    FILE *fp;
    int i, j, stud_num;
    float **grd_arr, sum_grd;

    fp = fopen("test.bin", "rb"); 
    if(fp == NULL)
    {
        printf("Error: fopen() failed\n");
        exit(EXIT_FAILURE);
    }
    if(fread(&stud_num, sizeof(int), 1, fp) != 1)
    {
        fclose(fp);
        printf("Error: fread() failed to read number\n");
        exit(EXIT_FAILURE);
    }
    /* We use grd_arr as a two-dimensional array of stud_num rows and LESSONS columns. First, we allocate memory for the rows. Next, we allocate memory for each row. Each row holds the grades of the student in LESSONS courses. */

    grd_arr = (float**) malloc(stud_num * sizeof(float*)); 
    if(grd_arr == NULL)
    {
        fclose(fp);
        printf("Error: Not available memory\n");
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < stud_num; i++)
    {
        grd_arr[i] = (float*) malloc(LESSONS * sizeof(float)); 
        if(grd_arr[i] == NULL)
        {
            fclose(fp);
            printf("Error: Not available memory\n");
            exit(EXIT_FAILURE);
        }
    }
    for(i = 0; i < stud_num; i++)
    {
        sum_grd = 0;
        if(fread(grd_arr[i], sizeof(float), LESSONS, fp) == LESSONS)
        {
            for(j = 0; j < LESSONS; j++)
                sum_grd += grd_arr[i][j];
            
            printf("%d. %f\n", i+1, sum_grd/LESSONS);
        }
        else
        {
            printf("Error: fread() failed\n"); 
            break; /* Stop reading. */
        }
    }

    for(i = 0; i < stud_num; i++) 
        free(grd_arr[i]);
    
    free(grd_arr); 
    fclose(fp); 
    return 0;
}

/* We could present a simpler solution similar to C.15.16. That is, we could declare grd_arr as an ordinary pointer, store the grades in the allocated memory, and read the grades from this memory 
in groups of fve, in order to calculate the average grade of each student. The reason we choose this solution is to remember how to handle the allocated memory as a two-dimensional array.*/