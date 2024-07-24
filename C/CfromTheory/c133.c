/* What is the output of the following program? */

#include <stdio.h>

struct student
{
    char name[50];
    int code;
    float grd;
};

struct student *test(void), stud_1;

int main(void)
{
    struct student stud = {"somebody", 1111, 7.5}, *ptr = &stud;

    *ptr = *test();
    printf("%s %d %d\n", ptr->name, ptr->code, ptr->grd);
    return 0;
}

struct student *test(void)
{
    return &stud_1;
}

/* Answer:  Since test() returns the address of stud_1, *test() is equivalent to stud_1. Since ptr points to the address of stud, *ptr is equivalent to stud. Therefore, the expression *ptr = *test(); 
is equivalent to stud = stud_1;. Since the global variable is initialized with zero values, the program outputs 0 0. */