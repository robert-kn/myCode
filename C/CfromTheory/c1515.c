/* Suppose that the purpose of the following program is to write a string into a binary fle, read it from the fle, and display it. Is this code error-free? */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE* fp;
    char str1[5], str2[] = "test";

    if((fp = fopen("text.bin", "w+b")) != NULL)
    {
        fwrite(str2, 1, 4, fp);
        fread(str1, 1, 4, fp);
        printf("%s\n", str1);
        fclose(fp);
    }
    return 0;
}

/* As you guess, there are several errors. The frst bug is that the fle pointer is not rewinded to the beginning of the fle before calling fread(). This bug is eliminated by adding:

fseek(fp, 0, SEEK_SET);

between fwrite() and fread().
Now, fread() reads successfully the four characters and stores them into str1.
The second bug is that str1 is not null terminated; therefore, printf() won’t work prop- erly. To eliminate this bug, add this statement before printf():

str1[4] = '\0';
or initialize str1 like:  char str1[5] = {0};
*/