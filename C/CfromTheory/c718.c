/**
 * Write a program that reads products’ codes and stores them in an integer array of 50 places. The program should store a code in the array only if it is 
 * not already stored. If the array becomes full or the user enters -1, the program should display the stored codes and terminate.
*/

#include <stdio.h>

#define SIZE 50

int main(void){
    int code, found, i, curr_index, arr[SIZE] = {};
    i = found = curr_index = 0;

    while(1){
        printf("Enter product code number %d: ", curr_index+1);
        scanf("%d", &code);

        if(code == -1 || curr_index >= SIZE)
            break;
        
        for(; i <= curr_index - 1; i++)
            if(arr[i] == code){
                found = 1;
                break;
            }
        
        i = 0;

        if(found)
            continue;
        else{
            arr[curr_index++] = code;
        }
    }

    for(i = 0; i <=  curr_index - 1; i++)
        printf("arr[%d] has value %d\n", i, arr[i]);
    return 0;
}