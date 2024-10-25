#include <stdio.h>

void selection_sort(int [], int);
void print_array(int [], int);

int main(){

    int arr[6] = {6, 4, 7, 9, 0, 1};
    int num = sizeof(arr)/sizeof(int);
    print_array(arr, num);
    selection_sort(arr, num);
    print_array(arr, num);


}

void selection_sort(int arr[], int num){
    int i, j, small, temp;

    for(i = 0; i < num - 1; i++){
        small = i;

        for(j = i + 1; j < num; j++)
            if(arr[j] < arr[small])
                small = j;

        temp = arr[small];
        arr[small] = arr[i];
        arr[i] = temp;     
        
    }   
}

void print_array(int arr[], int num){
    for (int i = 0;  i < num; i++){
        printf("i = %d = %d\t\t", i, *(arr + i));
    }
    printf("\n");
}