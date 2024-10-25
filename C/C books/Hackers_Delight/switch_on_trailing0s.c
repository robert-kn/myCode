int switch_on_trailing0s(int x){
    return (x | (x - 1));
}