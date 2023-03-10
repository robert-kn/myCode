#include <stdio.h>

int main(){

    int a = 100, b = 20;

    int * p0 = &a;

    const int * p1 = &a; // p1 s a pointer to an integer that is constant

    int const * p2 = &a; // p2 is a pointer to an integer that is constant

    int * const p3 = &a; // p3 is a constant pointer to an integer

    const int * const p4 = &a; // p4 is constant pointer to an integer that is a constant

    int const * const p5 = &a; // p5 is constant pointer to an integer that is a constant
    
    // Using p0 we have no limitations
    //1. p0 can change the value of the integer it points to
    //2. p0 can point to a totally different integer

    // p2 and p1 pointers to a constant integers
    // both cannot modify or change the value stored in the variable they point to
    // *p1 = 5;
    // *p2 = 10;
    // both can be used to point to another value
    p1 = &b;

    // p3 a constant pointer to integer
    // the integer value can be modified 
    *p3 = 25;
    // the pointer cannot point to anything else in memory (always points to the same variable)
    // p3 = &b; (error)

    // p4 and p5 constant pointers to an integers that are constant
    // you cannot modify the value stored in the variable nor can you point to another integer in memory
    // *p4 = 29; (error)
    // p5 = &b;  (error)

    return 0;
}