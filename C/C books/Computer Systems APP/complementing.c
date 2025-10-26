#include <stdio.h>

typedef unsigned char * byter_pointer;

void show_bytes(byter_pointer start, size_t len)
{
    int i;
    for(i = len-1; i >= 0; i--)
    {
        printf("%.2X", start[i]);
    }
    printf("\n");
}


int main(void)
{
    int x = 0x87654321;
    int lval = 0xFEDCBA98 << 32;
    show_bytes((byter_pointer) &lval, sizeof(int));
    int aval = 0xFEDCBA98 >> 36;
    show_bytes((byter_pointer) &aval, sizeof(int));
    int y = (~x & ~0xFF) | (x & 0xFF);
    int z = (x | 0xFF);
    int a = 0x66 & 0x39;
    int b = 0x66 | 0x39;
    int c = ~0x66 | ~0x39;
    int d = 0x66 | !0x39;
    int e = 0x66;
    int f = 0x39;
    int g = e && ~f;
    show_bytes((byter_pointer) &d, sizeof(int));
    printf("%.2X\n", g);
    return 0;
}