// Practice problem 2.25

// Consider the following code that attempts to sum the elements of an array a, where the number of elements is given by 
// parameter length: 

// float sum_elements(float a[], unsigned length){
//     int i;
//     float result = 0;
    
//     for(i = 0; i <= length - 1; i++)
//         result += a[i]
//     return result;
// }￼

// When run with argument length equal to 0, this code should return 0.0. Instead, it encounters a memory error. Explain 
// why this happens. Show how this code can be corrected. 

// This problem is designed to demonstrate how easily bugs can arise due to the implicit casting from signed to unsigned. 
// It seems quite natural to pass parameter length as an unsigned, since one would never want to use a negative length. 
// The stopping criterion i <= length-1 also seems quite natural. But combining these two yields an unexpected outcome! 
// Since parameter length is unsigned, the computation 0 − 1 is performed using unsigned arithmetic, which is equivalent 
// to modular addition. The result is then UMax. The ≤ comparison is also performed using an unsigned comparison, and since
// any number is less than or equal to UMax, the comparison always holds! Thus, the code attempts to access invalid 
// elements of array a. 

// The code can be fixed either by declaring length to be an int or by changing the test of the for loop to be i < length. 