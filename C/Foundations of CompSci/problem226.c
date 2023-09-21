/**
 * Modify Fig. 2.3 to perform selection sort when array elements are not integers, but rather structures of type
 *  struct STUDENT, as defined in the box “Sorting on Keys.” Suppose that the key field is studentID.
*/
#include <stdio.h>

#define MAX 5

struct STUDENT {
    int studentID;
    char * name;
    char  grade;
};

void print_students(struct STUDENT arr[], int count);

void selection_sort(struct STUDENT arr[], int num);

int main(){

    struct STUDENT arr_students[MAX] = {
        {345, "Robert", 'B'},
        {120, "James", 'A'},
        {88, "Chris", 'C'},
        {459, "Theo", 'D'},
        {56, "David", 'A'}
    };

    print_students(arr_students, MAX);
    selection_sort(arr_students, MAX);
    print_students(arr_students, MAX);

}

void print_students(struct STUDENT arr[], int count){
    for(int i = 0; i < count; i++){
        printf("{student_id = %d, name = %s, grade = %c}\n", arr[i].studentID, arr[i].name, arr[i].grade);
    }
    printf("\n");
}

void selection_sort(struct STUDENT arr[], int num){
    int i, j, small;
    struct STUDENT temp;

    for(i = 0; i < num - 1; i++){
        small = i;

        for(j = i + 1; j < num; j++)
            if(arr[j].studentID < arr[small].studentID)
                small = j;

        temp = arr[small];
        arr[small] = arr[i];
        arr[i] = temp;     
        
    }   
}


