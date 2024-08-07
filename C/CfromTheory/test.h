/* Suppose that the content of test.h is */

#include <stdio.h>

#define TEST

#ifdef TEST
#define f() printf("One ");
#undef TEST
#endif