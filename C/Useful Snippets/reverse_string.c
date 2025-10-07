#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 20

void Reverse(char string[], int len);
void char_swap(char * character_1, char * character_2);

int main()
{
    char input[MAX_LENGTH];
    printf("Enter a string with a maximum 19 characters\n");
    fgets(input, MAX_LENGTH, stdin);

    char input_copied[MAX_LENGTH];
    memcpy(input_copied, input, MAX_LENGTH);

    unsigned int len = strlen(input);

    Reverse(input, len);
    printf("string: %s reversed is: %s\n", input_copied, input);
    return EXIT_SUCCESS;

}

void char_swap(char * character_1, char * character_2)
{
    char temp_val = * character_1;
    * character_1 = * character_2;
    * character_2 = temp_val;
}


void Reverse(char string[], int len)
{
    int i;
    for(i = 0; i < (len/2); i++)
    {
        char_swap(&string[i], &string[len - 1 - i]);
    }
}
