// Practice problem 2.38

// As we will see in Chapter 3, the lea instruction can perform computations of the form (a<<k)+b, where k is either 
// 0, 1, 2, or 3, and b is either 0 or some program value. The compiler often uses this instruction to perform 
// multiplications by constant factors. For example, we can compute 3*a as (a<<1) + a. 

// Considering cases where b is either 0 or equal to a, and all possible values of k, what multiples of a can be computed 
// with a single lea instruction? 

// In Chapter 3, we will see many examples of the lea instruction in action. The instruction is provided to support 
// pointer arithmetic, but the C compiler often uses it as a way to perform multiplication by small constants. 
// For each value of k, we can compute two multiples: 2k (when b is 0) and 2k + 1 (when b is a). Thus, we can compute 
// multiples 1, 2, 3, 4, 5, 8, and 9. 