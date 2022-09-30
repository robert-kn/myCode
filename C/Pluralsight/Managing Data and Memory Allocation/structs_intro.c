#include <stdio.h>
#include <stddef.h>

typedef struct Grade{
    char letter;
    int rank;
} Grade;

int main(int argc, char * argv[]){
    // declare and initialise struct on the stack
    const Grade student_grade = {'A', 96};

    // read values from a struct's members
    printf("\nLetter: %c", student_grade.letter);
    printf("\nRank: %d", student_grade.rank);

    // get byte size of struct members
    const size_t letter_byte_size = sizeof(student_grade.letter);
    const size_t rank_byte_size = sizeof(student_grade.rank);

    printf("\nSize of student grade letter is: %zu", letter_byte_size);
    printf("\nSize of student grade rank is: %zu", rank_byte_size);

    const size_t student_grade_byte_size =  sizeof(student_grade);

    printf("\nTotal size of student grade in bytes: %zu\n", student_grade_byte_size);

    // memory address positions of struct members
    printf("Address of letter stored in student grade struct: %p\n", &student_grade.letter);
    printf("Address of integer stored in student grade struct: %p\n", &student_grade.rank);
}