/**
 * The 13-digit International Standard Book Number (ISBN) is a unique code that identifies a book commercially. 
 * The last digit is a check digit used for error detection. To calculate its value, each digit of the first 12 
 * digits is alternately multiplied, from left to right, by 1 or 3. The products are summed up and divided by 10. 
 * The check digit is the remainder of the division subtracted from 10. If it is 10, it becomes 0. For example, assume 
 * that the first 12 digits are: 978960931961.
*/

#include <stdio.h>

int main(void){
    int dig1, dig2, dig3, dig4, dig5, dig6, dig7, dig8, dig9, dig10, dig11, dig12, dig13, sum, check_dig;
    printf("Enter ISBN digits: \n");
    scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d", &dig1, &dig2, &dig3, &dig4, &dig5, &dig6, &dig7, &dig8, &dig9, &dig10, &dig11, &dig12, &dig13);

    sum = dig1 + dig2*3 + dig3 + dig4*3 + dig5 + dig6*3 + dig7 + dig8*3 + dig9 + dig10*3 + dig11 + dig12*3;

    check_dig = 10 - (sum % 10);

    if(check_dig == 10)
        check_dig = 0;
    if(check_dig == dig13)
        printf("valid ISBN\n");
    else
        printf("Invalid ISBN\n");

    return 0;

}