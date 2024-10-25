#include <stdio.h>

void inplace_swap(int * x, int * y){
    * y = * x ^ * y; /* step 1 */
    * x = * x ^ * y; /* step 2 */
    * y = * x ^ * y; /* step 3 */
}

int main(){
    int x = 7;
    int y = 12;
    printf("x = %d, y = %d\n", x, y);
    inplace_swap(&x, &y);
    printf("x = %d, y = %d\n", x, y);
}