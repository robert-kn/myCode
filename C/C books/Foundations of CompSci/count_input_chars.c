#include <stdio.h>

int main(){
    int num = 0;
    while(getchar() != EOF)
        ++num;
    printf("Number of  characters entered: %d\n", num);
}