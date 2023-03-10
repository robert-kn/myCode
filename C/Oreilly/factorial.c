#include <stdio.h>
#include <stdlib.h>

int factorial(int num){
    if(num == 1 || num == 0)
        return 1;
    else
        return num * factorial(num - 1);
}

int main(int argc, char * argv[]){
    if(argc < 2)
        printf("usage: factorial.exe <number>");
    else{
        long ans = factorial(atoi(argv[1]));
        printf("%ld\n", ans);
    }

    return 0;
    
}