/**
 * What is the output of the following program?
*/

#include <stdio.h> 

int main(void){
    int a[] = {0, 0, 1, 2, 3}, b[] = {0, 0, 4, 5, 6};
    int *ptr1 = a, *ptr2 = b;

    while(!*ptr1++ && !*ptr2++)
        ;
    
    printf("%d %d\n", *(b+(ptr1-a)), *(a+(ptr2-b)));
    return 0;
}

/**
 * First iteration. Notice that in !*ptr1++ the ! operator is applied first and then ptr1 is increased. Since ptr1 points to a, *ptr1 is 
 * equal to a[0], that is, 0. The ! opera- tor makes it 1. Next, ptr1 is increased and points to a[1]. Similarly, the value of !*ptr2 is 
 * 1 and ptr2 points to b[1]. Since both terms are true, the loop continues.
 * 
 * Second iteration. Like before, the values of !*ptr1 and !*ptr2 are 1. ptr1 points to a[2] and ptr2 points to b[2].
 * 
 * Third iteration. Since ptr1 points to a[2], !*ptr1 is 0 and ptr1 is increased and points to a[3]. Here is the key to the answer. 
 * Recall from Chapter 4 and the description of the && operator that if an operand is false the rest operands are not evaluated and 
 * the value of the expression becomes 0. Therefore, the loop terminates. Since the !*ptr2++ term is not evaluated, ptr2 is not increased.
 * 
 * Since ptr1 points to a[3] the result of ptr1-a is 3. Therefore, the expression *(b+(ptr1- a)) is equivalent to *(b+3), that is, b[3]. 
 * Similarly, since ptr2 points to b[2] the expression *(a+(ptr2-b)) is equivalent to *(a+2), that is, a[2]. Therefore, the program 
 * outputs: 5 1.
 * 
 * And to make it even worse, what would be the output if we replace the && operator with the || operator and write:
 * 
 * while(!*ptr1++ || !*ptr2++);
 * 
 * If you find it, please let us know...
*/