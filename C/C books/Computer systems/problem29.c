// practice problem 2.9
/**
 * Computers generate color pictures on a video screen or liquid crystal display by mixing three different colors of light: red, green, and blue. Imagine a simple scheme, with three different lights, each of which can be turned on or off, projecting onto a glass screen:
 * 
 * We can then create eight different colors based on the absence (0) or presence (1) of light sources R, G, and B:
 * 
 * R           G           B           Color
   0           0           0           Black
   0           0           1           Blue
   0           1           0           Green
   0           1           1           Cyan
   1           0           0           Red
   1           0           1           Magenta
   1           1           0           Yellow
   1           1           1           White

  Each of these colors can be represented as a bit vector of length 3, and we can apply Boolean operations to them.
 */

// A.	The complement of a colour is formed by turning off the lights that are on and turning on the lights that are off. What would be the complement of each of the eight colour’s listed above? 
// 	[000] -> black is the complement of [111] -> white
// 	[001] -> blue is the complement of [110] -> yellow
// 	[010] -> green is the complement of [101] -> magenta
// 	[011] -> cyan is the complement of [100] -> red

//  B. Describe the effect of applying Boolean operations on the following colours:
// 	blue | green = [001] | [010] = [011] -> cyan
// 	yellow & cyan = [110] & [011] = [010] -> green
// 	red ^ magenta = [100] ^ [101] = [001] -> blue