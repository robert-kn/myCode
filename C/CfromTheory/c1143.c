/* What is the output of the following program? */

#include <stdio.h>

int main(int argc, char *argv[])
{
    while(--argc)
        printf((argc > 1) ? "%s " : "%s\n", *++argv);

    return 0;
}

/* Answer: argc is equal to the number of the command line arguments. If the only argu-
ment is the name of the program, argc would be 1 and the loop won’t be executed because
its value becomes 0. If there are more arguments, the program displays their values, sepa-
rated by a space, and it adds a new line character after printing the last one.
For example, suppose that the command line arguments are one and two. Therefore,
argc would be 3 and the loop condition makes it 2. Since (argc > 1) is true, the "%s "
will be replaced by *++argv and a space. Since argv points to argv[0], the expression
++argv makes it point to argv[1]. Therefore, *++argv is equivalent to argv[1], and
the program outputs one. In the next iteration, argc becomes 1, so the "%s\n" will be
replaced by argv[2]. As a result, the program outputs two and a new line character.
Now, answer this one. What would be the output if we write *argv++ instead of *++argv? 

Answer: The program would display the name of the program and the command line
arguments, but the last one.*/