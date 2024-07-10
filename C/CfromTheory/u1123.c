/* Image editing programs often use the flood fill algorithm to fill similarly colored
connected areas with a new color. Suppose that the two-dimensional 8×8 array of Figure
11.4a represents the pixels of an image, where 0 represents the black color, 1: white, 2: red,
3: green, and 4: blue. Consider that a pixel is similarly colored connected with another, if
they have the same color and it is adjacent to it. The similarly colored areas are depicted
in Figure 11.4b.
To implement the flood fill algorithm, write a recursive floodfill() function, which
changes the color (e.g., c) of a pixel at a random location (e.g., i, j) to a new color and
then it changes the color of its neighboring pixels (i.e., the pixels to its left, right, up, and
down) having the same color c. Notice that this process should continue recursively on
the neighbors of the changed pixels, until there are no other pixels to check. For example,
if we choose to change the color of the pixel in the position 0, 0 from black (e.g., 0) to
green (e.g., 3), the color of the top-left area of four pixels changes to green, as shown in
Figure 11.4c.
Write a program that uses a two-dimensional 8×8 array of integers and assigns to its ele-
ments random values in [0, 4]. Then, the program should read the location of a pixel (e.g.,
i, j) and a new color and use floodfill() to change the existing color of its similarly
colored area with the new one. */