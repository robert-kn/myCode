/**
 * As mentioned in the box on “Sorting on Keys,” if the elements to be sorted are large structures such as 
 * type STUDENT, it makes sense to leave them stationary in an array and sort pointers to these structures, found 
 * in a second array. Write this variation of selection sort.
*/

#include <stdio.h>

#define MAX 5

struct STUDENT {
    int studentID;
    char * name;
    char  grade;
};

void print_students(struct STUDENT * ptr[], int count);
void print_students2(struct STUDENT arr[], int count);
void selection_sort(struct STUDENT * arr[], int num);


int main(){

    struct STUDENT arr_students[MAX] = {
        {345, "Robert", 'B'},
        {120, "James", 'A'},
        {88, "Chris", 'C'},
        {459, "Theo", 'D'},
        {56, "David", 'A'}
    };

    struct STUDENT * stdent1 = &(arr_students[0]);
    struct STUDENT * stdent2 = &(arr_students[1]);
    struct STUDENT * stdent3 = &(arr_students[2]);
    struct STUDENT * stdent4 = &(arr_students[3]);
    struct STUDENT * stdent5 = &(arr_students[4]);

    struct STUDENT * arr[MAX] = {stdent1, stdent2, stdent3, stdent4, stdent5};   
    
    print_students(arr, MAX);
    selection_sort(arr, MAX);
    print_students(arr, MAX);
    print_students2(arr_students, MAX);

}

void print_students(struct STUDENT * ptr[], int count){
     for(int i = 0; i < count; i++){
         printf("{student_id = %d, name = %s, grade = %c}\n", (*(ptr + i))->studentID, (*(ptr + i))->name, (*(ptr + i))->grade);
     }
     printf("\n");
}

void print_students2(struct STUDENT arr[], int count){
    for(int i = 0; i < count; i++){
        printf("{student_id = %d, name = %s, grade = %c}\n", arr[i].studentID, arr[i].name, arr[i].grade);
    }
    printf("\n");
}

void selection_sort(struct STUDENT * arr[], int num){
    int i, j, small;
    struct STUDENT * temp;

    for(i = 0; i < num - 1; i++){
        small = i;

        for(j = i + 1; j < num; j++)
            if((*(arr + j))->studentID < (*(arr + small))->studentID)
                small = j;

        temp = *(arr + small);
        *(arr + small) = *(arr + i);
        *(arr + i) = temp;     
        
    }   
}
