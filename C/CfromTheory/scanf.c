#include <stdio.h>

int main(void){
    int ch, num;
    printf("Enter num: ");

    while(scanf("%d", &num) != 1){
        printf("Enter num: ");
        while((ch = getchar()) != '\n' && ch != EOF)
            ; /* consume the unread characters */
    }
    printf("Input value: %d\n", num);
    return 0;
}