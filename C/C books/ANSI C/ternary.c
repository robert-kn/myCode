#include <stdio.h>

void print_arr_elem(int arr[], int n){
    int i;
    for(i =  0; i < n; i++){
        printf("%6d%c", arr[i], (i%10==9 || i==n-1)? '\n' : ' ');
    }
}

int main(){
    int arr[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
    print_arr_elem(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}