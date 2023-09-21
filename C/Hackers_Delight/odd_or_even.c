#include <stdio.h>

#define SHIFT 1

int odd_or_even(int num);

int main(){
    printf("%d\n", odd_or_even(0x11)); /* should  return 1 */
    printf("%d\n", odd_or_even(0x10)); /* should  return 0 */
    return 0;
}

int odd_or_even(int num){
    return !!(num & SHIFT);
}