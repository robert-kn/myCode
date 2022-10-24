// A constant pointer, sometimes referred to as “pointer to const,” is a pointer which cannot be used to 
// modify the data it points to
const char *name_ptr = "Test"; 

// If we put the const after the *, then the meaning of the const changes. If the declaration begins 
// with “char * const” then the pointer can never be modified to point to a different location
char * const name = "Test";

// Finally, put const in both places to create a pointer that cannot be modified to a data item that cannot be 
// changed, as shown here:
const char *const title_ptr = "Title";