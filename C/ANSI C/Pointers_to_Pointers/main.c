#include <stdio.h>
#include <string.h>

#define MAXLINES 5000           /* max #lines to be sorted */
char * lineptr[MAXLINES];      /* pointers to text lines */

int read_lines(char * lineptr[], int nlines);
void writelines(char * lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);
void swap(char *v[], int i, int j);

/* sort input lines */
int main()
{
    int nlines;      /* number of input lines read */

    if((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

/* qsort: sort v[left]... v[right] into increasing order */

void qsort(char *v[], int left, int right){
    int i, last;
    void swap(char *v[], int i, int j);

    if(left >= right) /* do nothing if array contains */
        return;       /* fewer than two elements */
    swap(v, left, (left + right)/2); /* move partition elem */
    last = left;                    /* to v[0]*/
    for(i = left + 1; i <= right; i++) /* partition */
        if(strcmp(v[i],  v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);        /* restore partition elem */
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j){
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}