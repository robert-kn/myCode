/* Defne the structure type city with members: city name, country name, and population. Write a program that uses this type to read the data of 100 cities and store them in an array. 
Then, the program should read the name of a country and a number and display the cities of that country whose population is greater than the input number. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

int read_text(char str[], int size, int flag);

struct city 
{
    char name[50];
    char cntry[50];
    int population;
};

int main(void)
{
    char cntry[50];
    int i, pop, flag;
    struct city cities[SIZE];

    for(i = 0; i < SIZE; i++)
    {
        printf("\nCity: ");
        read_text(cities[i].name, sizeof(cities[i].name),1);

        printf("Country: ");
        read_text(cities[i].cntry, sizeof(cities[i].cntry), 1);

        printf("Population: ");
        scanf("%d",  &cities[i].population);

        getchar();
    }

    printf("\nEnter country to search: ");
    read_text(cntry, sizeof(cntry), 1);

    printf("Population: ");
    scanf("%d", &pop);

    flag = 0;
    for(i = 0; i < SIZE; i++)
    {
        if((strcmp(cities[i].cntry, cntry) == 0) && (cities[i].population > pop))
        {
            flag = 1;
            printf("C: %s P: %d\n", cities[i].name, cities[i].population);
        }
    }
    if(flag == 0)
        printf("\nNone city is found\n");
    return 0;
}