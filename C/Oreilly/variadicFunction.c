#include <stdio.h>
#include <stdarg.h>

// 1- passing the count as the first argument
int sum(int count, ...){

    int total = 0;
    
    va_list v1; //variadic list variable

    va_start(v1, count); //initialise and use variable list

    for (int i = 0; i < count; ++i){
        total += va_arg(v1, int);
    }

    va_end(v1); //free up any resources used in the process
    return total;
}

// 2- passing a sentinel (magic) value
int sum2(int number, ...){

    int total = number;
    
    va_list v1; //variadic list variable

    va_start(v1, number); //initialise and use variable list

    for (; ;){
        int arg = va_arg(v1, int);
        if(0 == arg)
            break; // no more arguments
        total += arg;
    }

    va_end(v1); //free up any resources used in the process
    return total;
}


int main() {
    printf("Sum = %d\n", sum(4, 1, 2, 3, 4));
    printf("Sum2 = %d\n", sum2(1, 2, 3, 4, 0));
}