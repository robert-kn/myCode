int isolate_rightmost1_flip_all_other_bits(int x){
    return ~x | (x - 1);
}