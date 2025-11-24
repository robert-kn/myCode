// Practice problem 2.11
// Armed with the function inplace_swap from Problem 2.10, you decide to write code that will reverse the elements of an array by swapping elements from opposite ends of the array, working toward the middle. 

// You arrive at the following function:

void inplace_swap(int * x, int * y){
    * y = * x ^ * y;
    * x = * x ^ * y;
    * y = * x ^ * y;
}

void reverse_array(int a[], int cnt){
    int first, last;
    for(first = 0, last = cnt - 1; first <= last; first++, last--)
        inplace_swap(&a[first], &a[last]);
}

// When you apply your function to an array containing elements 1, 2, 3, and 4, you find the array now has, as expected, elements 4, 3, 2, and 1. When you try it on an array with elements 1, 2, 3, 4, and 5, however, you are surprised to see that the array now has elements 5, 4, 0, 2, and 1. In fact, you discover that the code always works correctly on arrays of even length, but it sets the middle element to 0 whenever the array has odd length.

// A. For an array of odd length cnt = 2k + 1, what are the values of variables first and last in the final iteration of function reverse_array? Both first and last have value k, so we are attempting to swap the middle element with itself.

// B. Why does this call to function inplace_swap set the array element to 0? because the final element is the same for both first and last variables and hence results in zero due to additive inverse property of boolean algebra

// C. What simple modification to the code for reverse_array would eliminate this problem? change first <= last to first < last