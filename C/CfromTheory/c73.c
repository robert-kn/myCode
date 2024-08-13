/**
 * Write a program that declares an array of five elements and uses a for loop to assign the v
 * alues 1.1, 1.2, 1.3, 1.4, and 1.5 to them. 
 * Then, the program should display the array’s elements in reverse order.
*/

#include <stdio.h>

int main(void){
    float arr[5], num = 1.1;
    int i;
    for(i = 0; i < 5; i++){
        arr[i] = num + (i * 0.1);
    }

    for(i = 4; i >= 0; i--)
        printf("%.1f ", arr[i]);

    printf("\n");
    return 0;
}