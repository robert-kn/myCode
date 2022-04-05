#include <stdio.h>

void ascending(int[]);
void descending(int[]);

void main(){
    system("clear");
    int array[10], x;
    int choice = 0;

    for(x=0; x < 10; x++){
        array[0] = 0;
    }

    printf("Please enter 10 integers separated by space characters\n");

    for(x=0; x < 10; x++){
        scanf("%d", &array[x]);
    }

    printf("\nChoose whether you would like to see the integers in:\n");
    printf("\t1. Ascending order\n");
    printf("\t2. Descending order\n");
    scanf("%d", &choice);

    if(choice == 1)
        ascending(array);
    else
        descending(array);
}

void ascending(int array[]){

    int i, j;
    int temp = 0;

    for(j = 0; j < 10; j++ ){

        for(i = 0; i <= 8; i++){
            if(array[i] > array[i+1]){
                temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
            }
        }
    }
    

    for(i=0; i < 10; i++)
        printf("%d ", array[i]);

    printf("\n");

}

void descending(int array[]){
    int i, j;
    int temp = 0;

    for(j = 0; j < 10; j++ ){

        for(i = 0; i <= 8; i++){
            if(array[i+1] > array[i]){
                temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
            }
        }
    }
    

    for(i=0; i < 10; i++)
        printf("%d ", array[i]);

    printf("\n");

}

    