#ifndef PERSON_H
#define PERSON_H

typedef struct 
{
    int year;
    int month;
    int date;
    char * name;
} Person;

Person * person_construct(int, int, int, char *);
void person_destruct(Person *);
void print_person(Person *);
Person * person_copy(Person *);
Person * person_assign(Person *, Person *);

#endif

