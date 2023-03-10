/**
 * how this program executes will depend on the compiler that is used to execute it. It might
 * crash or it might run and write to amemory location segment that is not assigned to the 
 * program. The behaviour is undefined
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv){
    int x = -2;
    int arr[] = {0, 1, 2, 3, 4};
    int y = 15;

    printf("&x = %p, &y = %p\n", &x, &y);
    printf("&arr[0] = %p, &arr[4] = %p\n", &arr[0], &arr[4]);
    printf("x = %d, y = %d", x, y);
    arr[-1] = 7;
    arr[5] = -23;
    printf("x = %d, y = %d", x, y);
    arr[6] = 108;
    printf("x = %d, y = %d", x, y);
    arr[7] = -353;
    printf("x = %d, y = %d", x, y);
    return EXIT_SUCCESS;
}