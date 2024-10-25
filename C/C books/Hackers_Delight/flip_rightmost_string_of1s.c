int flip_rightmost_string_of1s(int x){
    return ((x & -x) + x) & x;
}