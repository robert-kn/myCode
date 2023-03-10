#include <stdio.h>
#include <string.h>

int main(){

    char array[6] = "Hello";
    char array1[] = "Taken";

    printf("%s %s\n", array, array1);

    array[0] = 'P';
    array1[0] = 'H';

    printf("%s %s\n", array, array1);

    printf("size = %lu; length = %lu\n", sizeof(array), strlen(array));

    return 0;

}