/* what is the output of the following program */

#include <stdio.h>

int main(void)
{
    char arr[7][10] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    int i; 

    for(i = 0; i < 7; i++)
    {
        if(arr[i][2] == 'n' && *(arr[i] + 3) == 'd' && *(*(arr+i)+4) == 'a')
            printf("%s is No.%d week day\n", arr[i], i+1);
    }
    return 0;
}