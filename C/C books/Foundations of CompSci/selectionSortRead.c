#include <stdio.h>

#define MAX 100
int arr[MAX];

void selection_sort(int [], int);
void print_array(int [], int);

int main(){

    int i, num;

    for(num = 0; num < MAX && scanf("%d", &arr[num]) != EOF; num++)
        ;
    int count = sizeof(arr)/sizeof(arr[0]);
    print_array(arr, count);
    selection_sort(arr, count);
    print_array(arr, count);


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