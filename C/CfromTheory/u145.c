/* Use ptr and complete the following program to read and display the data of one student. */

struct student
{
    char *name;
    int code;
    float grd;
};

int main(void)
{
    struct student *ptr;
    ...
}

/* Then, the program should read a number of students (use extra variables) and use ptr to allocate memory 
and store the data of those students whose name begin with an 'A'. The program should display their data 
before it ends. Assume that the names are less than 100 characters.*/