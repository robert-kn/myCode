/**
 * What are the values of a elements in the following program?
*/

#include <stdio.h>
int main(void)
{
    int k = 0, b = 1, c = 2, d = 3, m, a[3];
    int *p[] = {&k, &b, &c, &d};

    for(m = 0; m < 3; m++)
        a[*p[m]] = **(p+m+1);
    return 0;
}

/**
 * Answer: Since p[0] is equal to &k, p[1] equal to &b, p[2] equal to &c, and p[3] equal to &d, the values of *p[0], *p[1], *p[2], and *p[3] are 0, 1, 2, and 3, respectively. In the gen- eral case, p+m+1 is a pointer to the p[m+1] 
 * element. Let’s trace the iterations:
 * 
 * First iteration(m=0): a[*p[0]] = **(p+1) = *p[1] = b, that is, a[0] = 1. 
 * Second iteration(m=1): a[*p[1]] = **(p+2) = *p[2] = c, that is, a[1] = 2. 
 * Third iteration(m=2): a[*p[2]] = **(p+3) = *p[3] = d, that is, a[2] = 3.
*/