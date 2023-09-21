// Practice problem 2.39
// How could we modify the expression for form B for the case where bit position n is the most significant bit? 

// Form B: (x<<(n + 1)) - (x<<m)

// The expression simply becomes -(x<<m). To see this, let the word size be w so that n = w−1. Form B states that we 
// should compute (x<<w) - (x<<m), but shifting x to the left by w will yield the value 0. 