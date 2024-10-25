// Practice problem 2.41

// For a run of 1s starting at bit position n down to bit position m (n ≥ m), we saw that we can generate two forms of 
// code, A and B. How should the compiler decide which form to use? 

// Assuming that addition and subtraction have the same performance, the rule is to choose form A when n=m, either form 
// when n=m+1, and form B when n > m + 1. 

// The justification for this rule is as follows. Assume first that m > 0. When n = m, form A requires only a single 
// shift, while form B requires two shifts and a subtraction. When n = m + 1, both forms require two shifts and either 
// an addition or a subtraction. When n > m + 1, form B requires only two shifts and one subtraction, while form A 
// requires n − m + 1 > 2 shifts and n − m > 1 additions. For the case of m = 0, we get one fewer shift for both forms 
// A and B, and so the same rules apply for choosing between the two. 