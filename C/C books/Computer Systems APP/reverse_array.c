void inplace_swap(int *x, int *y) {
  *y = *x ^ *y;    /* Step 1 */
  *x = *x ^ *y;    /* Step 2 */
  *y = *x ^ *y;    /* Step 3 */
}


void reverse_array(int a[], int cnt) {
    int first, last;
    for(first = 0, last = cnt-1; first <= last; first++,last--)
        inplace_swap(&a[first], &a[last]);         
}

int main() {
  
  int arr[4] = {1,2,3,4};
  int arr1[5] = {1,2,3,4,5};
  reverse_array(arr, sizeof(arr)/sizeof(int));
  reverse_array(arr1, sizeof(arr1)/sizeof(int));

  return 0;
}