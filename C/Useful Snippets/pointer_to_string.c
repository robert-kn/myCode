#include <stdio.h>

int main(void)
{
    char arr[] = "message";
    char * ptr = "message";
    printf("%c %c %c %c %c\n", "message"[4], arr[4], *("message"+4), ptr[4]);
    return 0;
}