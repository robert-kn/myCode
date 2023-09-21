// Practice problem 2.51

// We saw in Problem 2.46 that the Patriot missile software approximated 0.1 as x = 0.000110011001100110011002. Suppose 
// instead that they had used IEEE round-to-even mode to determine an approximation x′ to 0.1 with 23 bits to the right 
// of the binary point. 

// What is the binary representation of x′? 0.00011001100110011001101
// What is the approximate decimal value of x′ − 0.1? 2.38 x 10-8
// How far off would the computed clock have been after 100 hours of operation? 2.38 x 10-8 x 100 x 60 x 60 x 10 ~ 0.086 
// seconds
// How far off would the program’s prediction of the position of the Scud missile have been? 171.66 m 