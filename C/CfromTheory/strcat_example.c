#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[30];
    return !printf("%s\n", strcat(strcpy(strcpy(str, "Shaws")+5, "hank Red"), "emption")-5);
}