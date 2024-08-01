/* Write a function similar to memcmp(). The program should read two strings of less than 100 characters and the number of the characters to be compared and use the function to display the 
result of the comparison.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mem_cmp(const void *ptr1, const void *ptr2, size_t size); 
int read_text(char str[], int size, int flag);

int main(void)
{
    char str1[100], str2[100];
    int num;

    printf("Enter first text: ");
    read_text(str1, sizeof(str1), 1);

    printf("Enter second text: "); 
    read_text(str2, sizeof(str2), 1);

    printf("Enter characters to compare: "); 
    scanf("%d", &num);

    printf("%d\n", mem_cmp(str1, str2, num));

    return 0;
}

int mem_cmp(const void *ptr1, const void *ptr2, size_t size)
{
    char *p1, *p2;

    p1 = (char*)ptr1;
    p2 = (char*)ptr2;
    while(size != 0) 
    {
        if(*p1 != *p2)
            return *p1 - *p2; p1++;
        p2++; 
        size--;
    } 
    return 0;
}

/* The loop compares the characters pointed to by p1 and p2. Since characters are compared, we cast the type void* to char*. If all characters are the same, mem_cmp() returns 0, otherwise 
the difference of the frst two nonmatching characters. */