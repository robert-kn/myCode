/* A parking lot has 200 parking spaces for cars and 40 parking spaces for motos.
Write a function (e.g., find_plate()) that takes as parameters a two-dimensional array
that contains plate numbers of less than 10 characters, the plate number of a vehicle, and a
third one to specify the vehicle’s type (e.g., 1 for cars). If the number is found in the array,
the function should return its position in the array, -1 otherwise.
Write a program that reads continuously plate numbers and their vehicle types. For
each plate, the program should call find_plate(), and if it returns -1, it means that
the vehicle is not parked and its plate number should be stored in the first available
position of a respective two-dimensional array. Use a two-dimensional plate array for
cars and another one for motos. To find an available position, write a second function.
If find_plate() does not return -1, it means that the plate number is found and the
program should set 0 to that position in order to free the space and charge it. The park-
ing fee is $10 for the cars and $4 for the motos. If the user enters end for plate number,
the program should terminate and display the total charge and the number of free
spaces. */