#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define CAP_INCR  10

int main(void)
{
    unsigned long long *ptr_Primes = NULL;
    bool found = false;
    unsigned long long limit = 0LL;
    int count = 0;

    printf("Enter the upper limit for primes you want to find: ");
    scanf("%llu", &limit);

    size_t capacity = 10;
    ptr_Primes = calloc(capacity, sizeof(unsigned long long int));
    if(ptr_Primes == NULL)
    {
        printf("Not enough memory. It's the end I'm afraid.\n");
        return 1;
    }

    *ptr_Primes = 2ULL;
    *(ptr_Primes + 1) = 3ULL;
    *(ptr_Primes + 2) = 5ULL;

    count = 3;

    unsigned long long trial = *(ptr_Primes + 2) + 2ULL;
    unsigned long long *pTemp = NULL;

    while(trial <= limit)
    {
        for(int i = 1; i < count; ++i)
        {
            if((found = (trial % *(ptr_Primes + i))))
                break;
        }
    }

}