#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(){
    int num = 200 * 300 * 400 * 500;
    unsigned int num2 = 200U * 300 * 400 * 500;
    uint64_t num3 = 200ULL * 300 * 400 * 500;
    printf("%d %u %" PRIu64 "\n", num, num2, num3);
    return 0;
}