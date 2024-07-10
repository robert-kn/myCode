/* Modify the previous function in order to take void types of pointers and a third
argument to declare the data type. For example, if it is 0, the passed type is int, otherwise,
it is double. Write a program to test the operation of the function. */

#include <stdio.h>

void *max(void *ptr1, void *ptr2, int type);

int main(void)
{
    int *p1, i1, i2;
    double *p2, d1, d2;

    printf("Enter integers: ");
    scanf("%d%d", &i1, &i2);

    printf("Enter floats: ");
    scanf("%lf%lf", &d1, &d2);

    p1 = (int*) max(&i1, &i2, 0);
    p2 = (double*) max(&d1, &d2, 1);

    printf("Max1:%d Max2:%f\n", *p1, *p2);
    return 0;

}

void *max(void *ptr1, void *ptr2, int type)
{
    if(type == 0)
    {
        if(*(int*)ptr1 > *(int*)ptr2)
            return (int*)ptr1;
        else
            return (int*)ptr2;
    }
    else
    {
        if(*(double*)ptr1 > *(double*)ptr2)
            return (double*)ptr1;
        else
            return (double*)ptr2;
    }

}