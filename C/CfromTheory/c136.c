/* Defne the structure type product with members: name, code, and price. Write a function that takes as parameters an array of such structures, the number 
of the products and a product code. The function should check if a product’s code is equal to that number, and if so, it should return a pointer to the respective 
structure, otherwise NULL. Write a program that uses the type product to read the data of 100 products. The program should store the products that cost more than $20 
in an array of such structures. Then, the pro- gram should read an integer and use the function to display the product’s name and price, if found. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

struct product
{
    char name[50];
    int code;
    float prc;
};

struct product *find_prod(struct product prod[], int num_prods, int code); /* Declare a function that takes as parameters an array of structures and two integers and returns a pointer to a structure of type product. */

int read_text(char str[], int size, int flag);

int main(void)
{
    int i, cnt, code;
    float prc;
    struct product *ptr, prod[SIZE]; cnt = 0;
    for(i = 0; i < SIZE; i++)
    {
        printf("\nPrice: ");
        scanf("%f", &prc);

        if(prc > 20)
        {
            prod[cnt].prc = prc;

            getchar();

            printf("Name: ");

            read_text(prod[cnt].name, sizeof(prod[cnt].name),1);

            printf("Code: ");
            scanf("%d", &prod[cnt].code); 
            cnt++;
        }
    }
    if(cnt == 0)
    {
        printf("None product is stored\n"); 
        return 0; 
    }
    printf("\nEnter code to search: "); 
    scanf("%d", &code);

    ptr = find_prod(prod, cnt, code); 
    if(ptr == NULL)
        printf("\nNo product with code = %d\n", code);
    else
        printf("\nN: %s C: %d P: %.2f\n", ptr->name, code, ptr->prc);
    return 0;

}

struct product *find_prod(struct product prod[], int num_prods, int code)
{
    int i;
    
    for(i = 0; i < num_prods; i++)
    {
        if(prod[i].code == code)
            return  &prod[i];  /*  If  the  code  is  found,  the function terminates and the address of that structure is returned. */
    }
    return NULL; /* If the code reaches that point, it means that the product is not found and the function returns NULL. */
}