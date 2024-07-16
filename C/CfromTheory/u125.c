/* Write a recursive version of the binary_search() in C.12.3. Use the following
prototype to modify the function. Here is an example how to call it: */

int binary_search(int arr[], int num, int start, int end);

int main(void)
{
    ...
    pos = binary_search(arr, num, 0, sizeof(arr)/sizeof(int)-1);
    ...
}