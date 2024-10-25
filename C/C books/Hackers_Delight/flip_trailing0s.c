int flip_trailing0s(int x){
    return ~x & (x - 1);
}