/* Use ptr and complete the following program to read and display the data of one book. Don’t use any 
other variable. Assume that the length of the input strings is less than 100 characters. */

struct book 
{
    char *title; 
    char *authors;
    int *code;
    double *prc;
};

int main(void)
{
    struct book *ptr;
    ...
}