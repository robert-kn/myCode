#include <stdio.h>
#include <limits.h>
#include <stddef.h>

int tadd(int x, int y)
{
    int sum = x + y;
    int pos_over = x > 0 && y > 0 && sum <= 0;
    int neg_over = x < 0 && y < 0 && sum >= 0;
    return !(pos_over || neg_over);
}

int main(void)
{
    int result_add = INT_MAX + 1;
    printf("adding %d; result_add %d\n", INT_MAX, result_add);

    int result_sub = INT_MIN - 1;
    printf("subtracting %d; result_sub %d\n", INT_MIN, result_sub);

    int result_com = INT_MAX + INT_MIN;
    printf("result_sub %d\n", result_com);

    int result_intmin = INT_MIN - INT_MIN;
    printf("result_intmin %d\n", result_intmin);
    printf("%d\n", tadd(INT_MIN, -INT_MIN));
    printf("%ld\n", __SIZE_MAX__);
    return 0;

}