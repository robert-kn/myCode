#include <stdio.h>

void selectionSort(int[], int);

int main(){
    int array[5] = {23, 17, 14, 8, 6};
    selectionSort(array, 5);
    printf("[");
    for(int i = 0; i < 5; i ++){
        if(i < 4)
            printf("%d,", array[i]);
        else
            printf("%d", array[i]);
    }
    printf("]\n");
    return 0;
}

void selectionSort(int array[], int n){

    int small, i, j, temp;

    for(i = 0; i < n-1; i++){
        // the small variable gets the index of the current item on the loop
        small = i;

        for(j = i+1; j < n; j++){
            // compare the next item in the array (i+1) to the previous item in the array (small)
            if(array[j] < array[small])
                small = j;
        }

        temp = array[small];
        array[small] = array[i];
        array[i] = temp;
    }

}