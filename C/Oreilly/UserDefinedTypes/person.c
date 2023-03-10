#include "person.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char * * argv)
{
    Person * p1 = person_construct(1990, 2, 24, "robert ndungu");
    Person * p2 = person_construct(1987, 8, 31, "elizabeth ndungu");
    Person * p3 = person_copy(p1);
    print_person(p1);
    print_person(p2);
    print_person(p3);
    p3 = person_assign(p3, p2);
    print_person(p3);
    person_destruct(p1);
    person_destruct(p2);
    person_destruct(p3);
    return EXIT_SUCCESS;
}


Person * person_construct(int y, int m, int d, char * name)
{
    Person * p = NULL;
    p = (Person *) malloc(sizeof(Person));
    if(p == NULL)
    {
        printf("malloc failed\n");
        return NULL;
    }
    (*p).year = y;
    (*p).month = m;
    p -> date = d;
    p -> name = (char *) malloc(sizeof(char) * (strlen(name) + 1));

    if((p -> name) == NULL)
    {
        printf("malloc failed to assign space for %s\n", name);
        return NULL;
    }

    strcpy(p -> name, name);
    return p;
}

void person_destruct(Person * p)
{
    free(p -> name);
    free(p);
}

void print_person(Person * p)
{
    printf("Name: %s. ", p->name);
    printf("date of birth: %d/%d/%d\n", p->date, p->month, p->year);
}

Person * person_copy(Person * p)
{
    // creates a new person object by allocating memory
    return person_construct(p -> year, p -> month, (*p).date, (*p).name);
}

Person * person_assign(Person * p1, Person * p2)
{
    // releases memory for existing attributes before copying the attributes over 
    free(p1 -> name);
    p1 -> year = p2 -> year;
    p1 -> month = p2 -> month;
    p1 -> date = p2 -> date;
    p1 -> name = strdup(p2 -> name);
    return p1;
}