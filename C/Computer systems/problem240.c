// Practice problem 2.40

// For each of the following values of K, find ways to express x * K using only the specified number of operations, where 
// we consider both additions and subtractions to have comparable cost. You may need to use some tricks beyond the simple 
// form A and B rules we have considered so far. 

//   K 		    Shifts 			        Add/Subs 				    Expression 
//   6			  2						1					(x << 2) + (x << 1)
//  31			  1						1					(x << 5) - x
//  -6			  2						1					(x << 1) - (x << 3)
//  55			  2						2					(x << 6) - (x << 3) - x

// Observe that the fourth case uses a modified version of form B. We can view the bit pattern [110111] as having a run of 
// 6 ones with a zero in the middle, and so we apply the rule for form B, but then we subtract the term corresponding to 
// the middle zero bit. 