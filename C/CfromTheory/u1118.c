/* Write a simple version of printf() to take as parameter a format string and a
variable argument list. The string should contain only the %c, %d, %f, and %s specifiers and
characters. The function should process the string and the arguments and call printf()
to display their values. For example: */

void simple_printf(char fmt[], ...);

int main(void)
{
    int i = 5;
    double j = 1.2, k = i+j;

    simple_printf("%s %c = %d+%f = %f\n", "Result: ", 'k', i, j, k);
    return 0;
}

/* The program should display Result: k = 5+1.2 = 6.2 (plus the 0s). */