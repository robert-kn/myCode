#include <stdio.h>

enum Days {
    Sunday,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday
};

int main(){

    enum Days myDay;

    myDay = Thursday;

    printf("Thursday = %d\n", myDay);

}