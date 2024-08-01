How many bytes does the following malloc() allocate?

double *ptr;
ptr = (double*) malloc(100*sizeof(*ptr));

Answer: Since ptr is a pointer to double, sizeof(*ptr) calculates the size of the double type, that is 8. Therefore, malloc() allocates 800 bytes.