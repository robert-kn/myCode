#include <stdio.h>

void inplace_swap(int * x, int * y){
    * y = * x ^ * y;
    * x = * x ^ * y;
    * y = * x ^ * y; 
}

void reverse_array(int a[], int count){
    int first, last;
    for(first = 0, last = count - 1; first  < last; first++, last--){
        inplace_swap(&a[first], &a[last]);
    }
}

void print_array(int a[], size_t arr_size){
    printf("{");
    for(int i = 0; i < arr_size; i++){
        printf(" %d ", *(a + i));
    }
    printf("}\n");
}

int main(){
    int arr[]= {1,2,3,4,5};
    print_array(arr, 5);
    reverse_array(arr, 5);
    print_array(arr, 5);
}