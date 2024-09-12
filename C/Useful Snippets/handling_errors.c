#include <stdio.h>
#define NDEBUG
#include <assert.h>
#include <ctype.h>

int main(void)
{
    int a = 0;
    printf("Line %d of file %s compiled on %s at %s\n", __LINE__, __FILE__, __DATE__, __TIME__);
    assert(a != 0);
    return 0;
}