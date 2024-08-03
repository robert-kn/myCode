/* Write a program that intends to write some data into a fle. The program should read a file name and, if the file does not exist, the program should create it and write 
the string One into it. If it exists, the program should ask the user to overwrite it. If 
the answer is positive, the program should write the string One into it; otherwise, the program should prompt the user to enter another file name in order to repeat the same procedure. */

#include <stdio.h>
#include <stdlib.h>

FILE *open_file(char name[], int *f);

int main(void)
{
    FILE *fp;
    char name[100];
    int flag, sel;

    flag = 0;
    do
    {
        printf("Enter file name: ");
        scanf("%s", name);
        fp = fopen(name, "r"); /* Check whether the file exists or not. If not, we open it for writing. Otherwise, we close the file and ask the user. */

        if(fp == NULL)
            fp = open_file(name, &flag);
        else
        {
            fclose(fp);
            printf("Would you like to overwrite existing file (Yes:1 - No:0)? ");
            scanf("%d", &sel);
            if(sel == 1) /* Overwrite the file. */
                fp = open_file(name, &flag);
        }
    
    }while(flag == 0);

    fputs("One", fp);
    fclose(fp);
    return 0;
}

FILE *open_file(char name[], int *f)
{
    FILE *fp;
    fp = fopen(name, "w"); 
    if(fp == NULL)
    {
        printf("Error: fopen() failed\n"); 
        exit(EXIT_FAILURE);
    }
    *f = 1; 
    return fp;
}

/*  This code is reliable with the assumption that the failure reason of fopen() is 
that the file does not exist, not some other reason. Also, we assume that no other running 
application will create the file in the time interval between checking and creating the file. */