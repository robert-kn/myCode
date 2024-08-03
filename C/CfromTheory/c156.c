/* Write a program that reads products’ codes (less than 20 characters each) and their  prices and stores them in a text fle, as follows: 

C101  17.5
C102  32.8 
...

If the user enters -1 for price, the insertion of products should terminate. Then, the pro- gram should read a product’s code and search the fle to fnd and display its price.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_text(char str[], int size, int flag);

int main(void)
{
    FILE *fp;
    char flag, str[20], prod[20];
    double prc;

    fp = fopen("test.txt", "w+"); /* Open file for reading and writing. */

    if(fp == NULL)
    {
        printf("Error: fopen() failed\n"); 
        exit(EXIT_FAILURE);
    }

    while(1)
    {
        printf("Enter price: ");
        scanf("%lf", &prc);
        if(prc == -1)
            break;
        getchar();
        printf("Enter product code: "); 
        read_text(str, sizeof(str), 1); 
        fprintf(fp, "%s %f\n", str, prc);
    }

    getchar();
    printf("Enter product code to search for: "); 
    read_text(prod, sizeof(prod), 1);

    flag = 0;
    fseek(fp, 0, SEEK_SET);
    while(1)
    {
        if(fscanf(fp, "%s%lf", str, &prc) != 2) 
            break;
        if(strcmp(str, prod) == 0)
        {
            flag = 1;
                break; /* Since the product is found exit from the loop. */
        }
    }

    if(flag == 0)
        printf("The %s product is not listed\n", prod);
    else
        printf("The price for product %s is %f\n", prod, prc);
    fclose(fp);
    return 0;
}

int read_text(char str[], int size, int flag) 
{
    int len;

    if(fgets(str, size, stdin) == NULL)
    {
        printf("Error: fgets() failed\n");
        exit(EXIT_FAILURE);
    }

    len = strlen(str);

    if(len > 0)
    {
        if(flag && (str[len-1] == '\n'))
        {
            str[len-1] = '\0';
            len--;
        }
    }
    else
    {
        printf("Error: No input\n");
        exit(EXIT_FAILURE);
    }
    return len;
}

/* We could use frst the w mode to open the fle to write data, then close it, and reopen it with the r mode to read data. To avoid that, we used the r+w mode and the fseek() function to rewind the fle 
pointer at the beginning of the fle and start reading from there. We’ll talk about fseek() in a short. */
