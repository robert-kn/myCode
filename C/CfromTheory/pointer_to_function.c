#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void make_rand(void (* ptr) (int evt, int num));
void handle_event(int evt, int num);

int main(void)
{
    /* part A */
    srand(time(NULL));
    make_rand(handle_event); /* notice that only the name of the function was included here  */
    return 0;
}

void make_rand(void (*ptr) (int evt, int num))
{
    /* part B */
    int i, cnt;
    cnt = 0;
    while(1)
    {
        i = rand();
        cnt++;
        if(i >= 1000 && i <= 2000)
        {
            (*ptr)(cnt, i);
            return;
        }
    }
}

void handle_event(int evt, int num)
{
    printf("Times:%d Num:%d\n", evt, num);
}