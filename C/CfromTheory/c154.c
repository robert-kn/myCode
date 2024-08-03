/* What is written in the file and what is displayed on the screen? */

#include <stdio.h>

int main(void)
{
    FILE *fp[2];

    if((fp[0] = fp[1] = fopen("test.txt", "w")) != NULL)
    {
        fputs("One", fp[0]);
        fclose(fp[0]);
        printf("%d\n", fputs("Two", fp[1]));
        fclose(fp[1]);
    }
    return 0;
}

/* The fp[0] and fp[1] pointers become equal to the return value of fopen() and they are both associated with the same file. The first call of fputs() writes One in the file, while the second call fails because 
the file is closed with the first fclose(). Indeed, the program displays the return value of the second fputs(), that is EOF. Therefore, only one One is written in the fle. Had we checked the return value of 
the second fclose(), we would have seen that it fails too.*/