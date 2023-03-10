#include <stdio.h>

#define MAX 10

int main (){
    char buffer[MAX];
    fgets(buffer, MAX, stdin);
    printf("string is:%s\n", buffer);
}