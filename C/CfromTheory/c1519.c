/* Suppose  that  the test.bin binary fle  contains  structures  of  the  type employee defned in the previous exercise. Write a program that reads them and copies the employees’ data whose salary is more 
than an input amount in the data. bin binary fle. The program should also display the average salary of the employees stored in data.bin.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct employee 
{
    char name[100];
    int tax_num;
    int salary;
};

int main(void)
{
    FILE *fp_in, *fp_out;
    int count, amount, sum_sal;
    struct employee tmp_emp;

    fp_in = fopen("test.bin", "rb"); 
    if(fp_in == NULL)
    {
        printf("Error: Input file can't be loaded\n"); 
        exit(EXIT_FAILURE);
    }
    fp_out = fopen("data.bin", "wb"); 
    if(fp_out == NULL)
    {
        fclose(fp_in);
        printf("Error: Output file can't be created\n"); 
        exit(EXIT_FAILURE);
    }

    printf("Enter amount: ");
    scanf("%d", &amount);
    count = sum_sal = 0;

    while(1)
    {
        if(fread(&tmp_emp, sizeof(employee), 1, fp_in) != 1)
            break;
        if(tmp_emp.salary > amount)
        {
            fwrite(&tmp_emp, sizeof(employee), 1, fp_out); 
            sum_sal += tmp_emp.salary;
            count++;
        }
    }
    if(count)
        printf("Avg = %.2f\n", (float)sum_sal/count);
    else
        printf("No employee gets more than %d\n", amount);

    fclose(fp_in);
    fclose(fp_out);
    return 0;
}