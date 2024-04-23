/**
 * The converse of the famous Pythagoras Theorem says that if a triangle has sides of length a, b and c, and if:
 * 
 * a^2 + b^2 = c2, the triangle is right 
 * a^2 + b^2 > c^2, the triangle is obtuse 
 * a^2 + b^2 < c^2, the triangle is acute
 * 
 * Write a program that uses an array of pointers to read the lengths of a, b, and c sides and determine the type of the triangle. The program should force the user to enter a value for c greater than the other two.
 * 
*/

#include <stdio.h>

int main(void)
{
    int *p[3], i, j, k;

    p[0] = &i;
    p[1] = &j;
    p[2] = &k;

    printf("Enter length_a and length_b: "); 
    scanf("%d%d", p[0], p[1]);

    do
    {
        printf("Enter length_c: ");
        scanf("%d", p[2]);
    } while((*p[2] <= *p[0]) || (*p[2] <= *p[1]));

    if((*p[0])*(*p[0]) + (*p[1])*(*p[1]) == (*p[2])*(*p[2])) 
        printf("Right triangle\n");
    else if((*p[0])*(*p[0]) + (*p[1])*(*p[1]) > (*p[2])*(*p[2])) 
        printf("Acute triangle\n");
    else
        printf("Obtuse triangle\n");
    return 0;
}