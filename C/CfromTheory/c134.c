/* Define the structure type time with members: hours, minutes, and seconds. Write a function that takes as parameter a pointer to an integer and converts that integer to hours, minutes, and seconds. 
These values should be stored into the members of a structure of type time, and the function should return that structure. Write a program that reads an integer, calls the function, 
and displays the members of the returned structure. */

#include <stdio.h>

struct time
{
    int hours; 
    int mins;
    int secs;
};

struct time mk_time(int *ptr);

int main(void)
{
    int secs;
    struct time t;

    printf("Enter seconds: ");
    scanf("%d", &secs);

    t = mk_time(&secs);
    printf("\nH:%d M:%d S:%d\n", t.hours, t.mins, t.secs);

    return 0;
}

struct time mk_time(int *ptr)
{
    struct time tmp;
    tmp.hours = *ptr/3600;
    tmp.mins = (*ptr%3600)/60;
    tmp.secs = *ptr%60;
    return tmp;
}

/* Comments: As said, when you want to save time and space, do not return an entire structure. This exercise is just an example to show you how to return a structure. For example, we could change the return type 
to void and pass the address of t to mk_time(). Thus, the function modifes a structure of the calling function instead of declaring and returning a new structure. */

void mk_time(int *ptr, struct time *tmp)
{
    tmp->hours = *ptr/3600;
    tmp->mins = (*ptr%3600)/60;
    tmp->secs = *ptr%60;
}