/**
 * And because we are “bad characters” and want to press you a bit more, what hap- pens if we change the for statement to:
*/

int *ptr, arr[2][5] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

for(ptr = arr[0]+4; ptr < arr[0]+7; ptr++)

/**
 * Answer: The statement ptr = arr[0]+4; makes ptr point to the address of arr[0][4]. Therefore, the statement *ptr = 0; is equivalent to arr[0][4] = 0;. Since each row contains five elements, the addresses beyond arr[0]+4 don’t 
 * correspond to array elements. Right?
 * 
 * Don’t think so, see why. When ptr is incremented and because the array elements are stored in successive memory locations, ptr will point to the first element of the next row. In other words, the address of arr[0]+5 is the same as 
 * of arr[1][0]. Similarly, the address of arr[0]+6 is the same as of arr[1][1]. Therefore, the program makes zero the value of the last element of the first row and the first two of the next one.
*/