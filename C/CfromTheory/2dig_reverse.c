#include <stdio.h> 
int main(void)
{
    int i;
    printf("Enter number between 19 and 99: ");
    scanf("%d", &i);
    i = 10*(i%10) + i/10;
    printf("%d\n", i);
    _Bool valid = 0;
    _Bool invalid = 1;
    printf("valid %d and invalid %d\n", valid, invalid);
    return 0; 
}