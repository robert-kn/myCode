#include <stdio.h>

int main(void){
    float a = 3.1;

    if(a == 3.1)
        printf("YES\n");
    else
        printf("No\n");
    printf("%.9f\n", a-3.1);
    return 0;
}