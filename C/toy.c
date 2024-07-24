#include <stdio.h>

int main(void)
{
    char str[10] = "something";
    /* str = "hello"; --> wrong! why? because str is a constant pointer and can't be modified to point to another string literal */
    str[0] = 'c';
    printf("%s\n", str);
    int num, reversed;
    int * ptr;
    printf("Addr = %p\n", ptr);
    ptr = NULL;
    printf("Addr = %p\n", ptr);
    printf("\a");
    printf("%e\n", 100.25);
    printf("%g\n", 0.0000123);
    printf("here is an \142 make it a capital :)\n");
    printf("here is an \x6b make it a capital :)\n");
    printf("Enter number: ");
    scanf("%d", &num);
    reversed = -num;
    printf("Original number %d; reversed number %d; flipped bits number %d\n", num, reversed, ((~num)+1));
    return 0;
}