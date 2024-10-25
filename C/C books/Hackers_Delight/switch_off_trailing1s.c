/* use this to determine if an unisgned integer is all 1's, or 0 or (2^n) - 1 */

int switch_off_trailing1s(unsigned x){
    return x & (x + 1);
}