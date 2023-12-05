int flip_trailing1s(int x){
    return ~x | (x + 1);
}